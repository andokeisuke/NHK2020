#include <MPU9250.h>

#include <Wire.h>
#include <MadgwickAHRS.h>
#include<ros.h>
#include <std_msgs/Int16.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>



Madgwick MadgwickFilter;

std_msgs::Int16 pose;
ros::NodeHandle  nh;
ros::Publisher pub("imu", &pose);

/////////////////////////MPU9250////////////////////////////
#define MPU9250_ADDRESS 0x68//I2CでのMPU9250のスレーブアドレス

#define PWR_MGMT_1 0x6b//電源管理のアドレス，スリープモード解除用
#define INT_PIN_CFG 0x37//磁気センサのバイパスモード設定用のアドレス

#define ACCEL_CONFIG 0x1c//加速度センサ設定用のアドレス
#define ACCEL_FS_SEL_2G 0x00//加速度センサのレンジ(2G)
#define ACCEL_FS_SEL_4G 0x08//加速度センサのレンジ(4G)
#define ACCEL_FS_SEL_8G 0x10//加速度センサのレンジ(8G)
#define ACCEL_FS_SEL_16G 0x18//加速度センサのレンジ(16G)

#define GYRO_CONFIG 0x1b//ジャイロセンサ設定用のアドレス
#define GYRO_FS_SEL_250DPS 0x00//ジャイロセンサのレンジ(250DPS)
#define GYRO_FS_SEL_500DPS 0x08//ジャイロセンサのレンジ(500DPS)
#define GYRO_FS_SEL_1000DPS 0x10//ジャイロセンサのレンジ(1000DPS)
#define GYRO_FS_SEL_2000DPS 0x18//ジャイロセンサのレンジ(2000DPS)

#define AK8963_ADDRESS 0x0c//磁気センサのスレーブアドレス
#define CNTL1 0x0a//磁気センサ設定用のアドレス
#define CNTL1_MODE_SEL_8HZ 0x12//磁気センサの出力周期(8Hz)
#define CNTL1_MODE_SEL_100HZ 0x16//磁気センサの出力周期(100Hz)
#define ST1 0x02//データ読み込み用フラッグのアドレス
///////////////////////////////////////////////////////////

float INITIAL_GYRO_X,INITIAL_GYRO_Y,INITIAL_GYRO_Z,INITIAL_ACC_X,INITIAL_ACC_Y,INITIAL_ACC_Z;
float AVERAGENUM_INIT = 1000.0;
int counter_init = 0;

volatile float accRange;//計算で使用するので，選択したレンジを入力する定数
volatile float gyroRange;//計算で使用するので，選択したレンジを入力する定数

volatile uint8_t accGyroTempData[14];//センサからのデータ格納用配列
volatile uint8_t magneticData[7];//センサからのデータ格納用配列
volatile uint8_t ST1Bit;//磁気センサのフラッグ

volatile int16_t ax = 0;//16bitの出力データ
volatile int16_t ay = 0;//16bitの出力データ
volatile int16_t az = 0;//16bitの出力データ
volatile int16_t gx = 0;//16bitの出力データ
volatile int16_t gy = 0;//16bitの出力データ
volatile int16_t gz = 0;//16bitの出力データ
volatile int16_t tempMPU9250Raw = 0;//16bitの出力データ
volatile int16_t mx = 0;//16bitの出力データ
volatile int16_t my = 0;//16bitの出力データ
volatile int16_t mz = 0;//16bitの出力データ

volatile float accX = 0;//加速度センサから求めた重力加速度
volatile float accY = 0;//加速度センサから求めた重力加速度
volatile float accZ = 0;//加速度センサから求めた重力加速度

volatile float gyroX = 0;//ジャイロセンサから求めた角速度
volatile float gyroY = 0;//ジャイロセンサから求めた角速度
volatile float gyroZ = 0;//ジャイロセンサから求めた角速度

volatile float tempMPU9250 = 0;//MPU9250の温度

volatile float magX = 0;//磁気センサから求めたuT
volatile float magY = 0;//磁気センサから求めたuT
volatile float magZ = 0;//磁気センサから求めたuT

volatile float accX_offset = -0.0274;//
volatile float accY_offset = 0;//-0.0824;//
volatile float accZ_offset = -1.0427;//

volatile float magX_offset = -26;//
volatile float magY_offset =   31;//
volatile float magX_offset_init = 0;//
volatile float magY_offset_init = 0;//

volatile float magX_max_offset = 0;//
volatile float magY_max_offset = 0;//
volatile float magX_min_offset = 0;//
volatile float magY_min_offset = 0;//

volatile float accX_inioffset;//
volatile float accY_inioffset;//
volatile float accZ_inioffset;//

volatile float gyroX_offset = -0.256;//
volatile float gyroY_offset = -1.150;//
volatile float gyroZ_offset = -0.915;//

static double sum = 0;
int i = 1;


void setup() {
  Wire.begin();//I2C通信を開始する
  Serial.begin(9600);//シリアル通信を開始する

  i2cWriteByte(MPU9250_ADDRESS, PWR_MGMT_1, 0x00);//スリープモードを解除
  i2cWriteByte(MPU9250_ADDRESS, ACCEL_CONFIG, ACCEL_FS_SEL_16G);//加速度センサの測定レンジの設定
  accRange = 16.0;//計算で使用するので，選択したレンジを入力する
  i2cWriteByte(MPU9250_ADDRESS, GYRO_CONFIG, GYRO_FS_SEL_2000DPS);//ジャイロセンサの測定レンジの設定
  gyroRange = 2000.0;//計算で使用するので，選択したレンジを入力する
  i2cWriteByte(MPU9250_ADDRESS, INT_PIN_CFG, 0x02);//bypass mode(磁気センサが使用出来るようになる)
  i2cWriteByte(AK8963_ADDRESS, CNTL1, CNTL1_MODE_SEL_100HZ);//磁気センサのAD変換開始
  MadgwickFilter.begin(100); //100Hz

  MPU9250();

magX_max_offset = magX;//
magY_max_offset = magY;//
magX_min_offset = magX;//
magY_min_offset = magY;//
   nh.initNode();
  nh.advertise(pub);


  initGyro();
  
}

void loop() {

  //if(i==100){
  MPU9250();
  //i=0;
  //}

MadgwickFilter.update(gyroX,gyroY,gyroZ,accX,accY,accZ,magX,magY,magZ);
//MadgwickFilter.updateIMU(gyroX,gyroY,gyroZ,accX,accY,accZ);
    double yaw   = MadgwickFilter.getYaw();
   //yaw = (yaw-180)/15.37*180;j
   //serialprint();
//    Serial.print(magX_offset_init);
//    Serial.print(" ");
//    Serial.println(magY_offset_init);
//    
pose.data = int((yaw-180)/60*90/260*180/185*180);
  pub.publish( &pose );

  nh.spinOnce();

// sum = sum + gyroZ;
//if(i==1000){
//
//  Serial.println(sum/1000,10);
// i = 1;
//sum=0;
// 
//}
i++;

//delay(500);
}

void MPU9250() {
  //akiracing.com (無断転載を禁ず)




  
  //ACC&GRYO///////////////////////////////////////////////////////////////////////////
  i2cRead(MPU9250_ADDRESS, 0x3b, 14, accGyroTempData); //0x3bから，14バイト分をaccGyroDataにいれる

  //COMPASS////////////////////////////////////////////////////////////////////////////
  i2cRead(AK8963_ADDRESS, ST1, 1, &ST1Bit);//読み出し準備ができたか確認
  if ((ST1Bit & 0x01)) {
    i2cRead(AK8963_ADDRESS, 0x03, 7, magneticData);//7番目の0x09(ST2)まで読まないとデータが更新されない
  }

  //Acc
  ax = (accGyroTempData[0] << 8) | accGyroTempData[1];//accGyroTempData[0]を左に8シフトし(<<)，accGyroTempData[1]を足し合わせる(|)
  ay = (accGyroTempData[2] << 8) | accGyroTempData[3];//accGyroTempData[2]を左に8シフトし(<<)，accGyroTempData[3]を足し合わせる(|)
  az = (accGyroTempData[4] << 8) | accGyroTempData[5];//accGyroTempData[4]を左に8シフトし(<<)，accGyroTempData[5]を足し合わせる(|)
  //Gyro
  gx = (accGyroTempData[8] << 8) | accGyroTempData[9];//accGyroTempData[8]を左に8シフトし(<<)，accGyroTempData[9]を足し合わせる(|)
  gy = (accGyroTempData[10] << 8) | accGyroTempData[11];//accGyroTempData[10]を左に8シフトし(<<)，accGyroTempData[11]を足し合わせる(|)
  gz = (accGyroTempData[12] << 8) | accGyroTempData[13];//accGyroTempData[12]を左に8シフトし(<<)，accGyroTempData[13]を足し合わせる(|)
  //Temp
  tempMPU9250Raw = (accGyroTempData[6] << 8) | accGyroTempData[7];//accGyroTempData[6]を左に8シフトし(<<)，accGyroTempData[7]を足し合わせる(|)
  //Magneto
  mx = (magneticData[3] << 8) | magneticData[2];//センサの軸が違うので順番が加速度とジャイロと違う
  my = (magneticData[1] << 8) | magneticData[0];//magneticData[1]を左に8シフトし(<<)，magneticData[0]を足し合わせる(|)
  mz = -((magneticData[5] << 8) | magneticData[4]);//加速度，ジャイロセンサと軸の向きが逆なので-を掛ける

  accX = ax * accRange / 32768.0 - INITIAL_ACC_X;//[G]に変換
  accY = ay * accRange / 32768.0 - INITIAL_ACC_Y;//[G]に変換
  accZ = az * accRange / 32768.0 -0.03; //- INITIAL_ACC_Z;//[G]に変換

  if(abs(accX)<0.02)accX = 0;
   if(abs(accY)<0.01)accY = 0;
   if(abs(accZ)<0.01)accZ = 0;

  gyroX = gx * gyroRange / 32768.0 + gyroX_offset;//[deg/s]に変換
  gyroY = gy * gyroRange / 32768.0 + gyroY_offset;//[deg/s]に変換
  gyroZ = gz * gyroRange / 32768.0 + gyroZ_offset;//[deg/s]に変換
// gyroX = gx * gyroRange / 32768.0 - INITIAL_GYRO_X;//[deg/s]に変換
// gyroY = gy * gyroRange / 32768.0 - INITIAL_GYRO_Y;//[deg/s]に変換
//  gyroZ = gz * gyroRange / 32768.0 - INITIAL_GYRO_Z;//[deg/s]に変換

 if(abs(gyroX)<1.0)gyroX = 0;
   if(abs(gyroY)<1.5)gyroY = 0;
   if(abs(gyroZ)<0.5)gyroZ = 0;
  
  tempMPU9250 = ((tempMPU9250Raw - 0.0) / 333.87) + 21.0f;
  //MPU-9250 Product Specification Revision 1.0のP12の値と,
  //MPU-9250Register Map and Descriptions Revision 1.4のP33の式を使用



  magX = mx / 32768.0f * 4800.0f + magX_offset;//[uT]に変換
  magY = my / 32768.0f * 4800.0f +magY_offset;//[uT]に変換
  magZ = mz / 32768.0f * 4800.0f;//[uT]に変換

      if(magX_max_offset < magX)magX_max_offset = magX;
  if(magY_max_offset < magY)magY_max_offset = magY;
  if(magX_min_offset > magX)magX_min_offset = magX;
  if(magY_min_offset > magY)magY_min_offset = magY;

  magX_offset_init = -(magX_max_offset+magX_min_offset)/2;
  magY_offset_init= -(magY_max_offset+magY_min_offset)/2;


    


//  magX = (mx + 344.0f) / 32768.0f * 4921.0f * 10.0f;//[mGauss]に変換
//    magY = (my - 234.0f) / 32768.0f * 4921.0f * 10.0f;//[mGauss]に変換
//    magZ = (mz - 410.0f) / 32768.0f * 4921.0f * 10.0f;//[mGauss]に変換
}

void MPU9250_test() {
  //akiracing.com (無断転載を禁ず)
  //ACC&GRYO///////////////////////////////////////////////////////////////////////////
  i2cRead(MPU9250_ADDRESS, 0x3b, 14, accGyroTempData); //0x3bから，14バイト分をaccGyroDataにいれる

  //COMPASS////////////////////////////////////////////////////////////////////////////
  i2cRead(AK8963_ADDRESS, ST1, 1, &ST1Bit);//読み出し準備ができたか確認
  if ((ST1Bit & 0x01)) {
    i2cRead(AK8963_ADDRESS, 0x03, 7, magneticData);//7番目の0x09(ST2)まで読まないとデータが更新されない
  }

  //Acc
  ax = (accGyroTempData[0] << 8) | accGyroTempData[1];//accGyroTempData[0]を左に8シフトし(<<)，accGyroTempData[1]を足し合わせる(|)
  ay = (accGyroTempData[2] << 8) | accGyroTempData[3];//accGyroTempData[2]を左に8シフトし(<<)，accGyroTempData[3]を足し合わせる(|)
  az = (accGyroTempData[4] << 8) | accGyroTempData[5];//accGyroTempData[4]を左に8シフトし(<<)，accGyroTempData[5]を足し合わせる(|)
  //Gyro
  gx = (accGyroTempData[8] << 8) | accGyroTempData[9];//accGyroTempData[8]を左に8シフトし(<<)，accGyroTempData[9]を足し合わせる(|)
  gy = (accGyroTempData[10] << 8) | accGyroTempData[11];//accGyroTempData[10]を左に8シフトし(<<)，accGyroTempData[11]を足し合わせる(|)
  gz = (accGyroTempData[12] << 8) | accGyroTempData[13];//accGyroTempData[12]を左に8シフトし(<<)，accGyroTempData[13]を足し合わせる(|)
 
 
  accX = ax * accRange / 32768.0;//[G]に変換
  accY = ay * accRange / 32768.0;//[G]に変換
  accZ = az * accRange / 32768.0;//[G]に変換


  gyroX = gx * gyroRange / 32768.0;//[deg/s]に変換
  gyroY = gy * gyroRange / 32768.0;//[deg/s]に変換
  gyroZ = gz * gyroRange / 32768.0;//[deg/s]に変換


  
 
}



void i2cRead(uint8_t Address, uint8_t Register, uint8_t NBytes, volatile uint8_t* Data) {//指定したアドレスのデータを読む関数
  Wire.beginTransmission(Address);//指定したアドレスと通信を始める
  Wire.write(Register);//レジスタを書き込む
  Wire.endTransmission();//通信を終了する

  Wire.requestFrom(Address, NBytes);//スレーブからNByteのデータを要求する
  uint8_t index = 0;
  while (Wire.available()) {
    Data[index++] = Wire.read();//データを読み込む
  }
}

void i2cWriteByte(uint8_t Address, uint8_t Register, volatile uint8_t Data) {//指定したアドレスにデータを書き込む関数
  Wire.beginTransmission(Address);//指定したアドレスと通信を始める
  Wire.write(Register);//指定するレジスタを書き込む
  Wire.write(Data);//データを書き込む
  Wire.endTransmission();//通信を終了する
}


void serialprint(){
     Serial.print("ax: ");
  Serial.print(accX);
  Serial.print("\t");
  Serial.print("ay: ");
  Serial.print(accY);
  Serial.print("\t");
  Serial.print("az: ");
  Serial.print(accZ);
  Serial.print("\t");
  Serial.print("gx: ");
  Serial.print(gyroX);
  Serial.print("\t");
  Serial.print("gy: ");
  Serial.print(gyroY);
  Serial.print("\t");
  Serial.print("gz: ");
  Serial.print(gyroZ);
  Serial.print("\t");
  Serial.print("mx: ");
  Serial.print(magX);
  Serial.print("\t");
  Serial.print("my: ");
  Serial.print(magY);
  Serial.print("\t");
  Serial.print("mz: ");
  Serial.print(magZ);
  Serial.print("\t");
  Serial.print("temp: ");
  Serial.print(tempMPU9250);
  Serial.println("\t");
  
  
  }


  
void initGyro() {
  INITIAL_GYRO_X = 0;
  INITIAL_GYRO_Y = 0;
  INITIAL_GYRO_Z = 0;
  INITIAL_ACC_X = 0;
  INITIAL_ACC_Y = 0;
  INITIAL_ACC_Z = 0;
  for (int i = 0;i < AVERAGENUM_INIT;i++) {
    MPU9250_test();
    INITIAL_GYRO_X += gyroX / AVERAGENUM_INIT;
    INITIAL_GYRO_Y += gyroY / AVERAGENUM_INIT;
    INITIAL_GYRO_Z += gyroZ / AVERAGENUM_INIT;
    INITIAL_ACC_X += accX / AVERAGENUM_INIT;
    INITIAL_ACC_Y += accY / AVERAGENUM_INIT;
    INITIAL_ACC_Z += accZ / AVERAGENUM_INIT;
    delay(5);
  }
}


