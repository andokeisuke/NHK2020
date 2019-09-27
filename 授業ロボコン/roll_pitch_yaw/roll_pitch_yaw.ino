#include <Wire.h>
#include <MadgwickAHRS.h>
//#include <ros.h>
//#include <std_msgs/Float64.h>

Madgwick MadgwickFilter;

#define MPU6050_PWR_MGMT_1   0x6B
#define MPU_ADDRESS  0x68

double precom = 0;
double theta = -180;
double th = 0;

//std_msgs::Float64 pose;
//ros::NodeHandle  nh;
//ros::Publisher pub("imu", &pose);

void setup() {
  Wire.begin();
  Serial.begin(9600); //115200bps

   // nh.initNode();
    //nh.advertise(pub);

  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(MPU6050_PWR_MGMT_1);  //MPU6050_PWR_MGMT_1レジスタの設定
  Wire.write(0x00);
  Wire.endTransmission();

  MadgwickFilter.begin(100); //100Hz
}

void loop() {
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 14, true);
  while (Wire.available() < 14);
  int16_t axRaw, ayRaw, azRaw, gxRaw, gyRaw, gzRaw, Temperature;

  axRaw = Wire.read() << 8 | Wire.read();
  ayRaw = Wire.read() << 8 | Wire.read();
  azRaw = Wire.read() << 8 | Wire.read();
  Temperature = Wire.read() << 8 | Wire.read();
  gxRaw = Wire.read() << 8 | Wire.read();
  gyRaw = Wire.read() << 8 | Wire.read();
  gzRaw = Wire.read() << 8 | Wire.read();


  // 加速度値を分解能で割って加速度(G)に変換する
  float acc_x = axRaw / 16384.0;  //FS_SEL_0 16,384 LSB / g
  float acc_y = ayRaw / 16384.0;
  float acc_z = azRaw / 16384.0;

  acc_x = acc_x + 0.1016;
  acc_y = acc_y + 0.0421;
  acc_z = acc_z + 0.1101;

  // 角速度値を分解能で割って角速度(degrees per sec)に変換する
  float gyro_x = gxRaw / 131.0;  // (度/s)
  float gyro_y = gyRaw / 131.0;
  float gyro_z = gzRaw / 131.0;

  static double total;
  static double var = 0;
  

  gyro_x = gyro_x + 3.1260;
  gyro_y = gyro_y - 2.0105;
  gyro_z = gyro_z - 0.9186;

 

  /*
    //c.f. Madgwickフィルターを使わずに、PRY（pitch, roll, yaw）を計算
    double roll  = atan2(acc_y, acc_z) * RAD_TO_DEG;
    double pitch = atan(-acc_x / sqrt(acc_y * acc_y + acc_z * acc_z)) * RAD_TO_DEG;
  */

  //Madgwickフィルターを用いて、PRY（pitch, roll, yaw）を計算
  MadgwickFilter.updateIMU(gyro_x, gyro_y, gyro_z, acc_x, acc_y, acc_z);

  //PRYの計算結果を取得する
  float roll  = MadgwickFilter.getRoll();
  float pitch = MadgwickFilter.getPitch();
  double yaw   = MadgwickFilter.getYaw();

  static double com = 0;
  static double oldYaw = 0;

  //yaw = yaw*3/7;

  if(yaw >= 0 && oldYaw >= 0) {
    com = com + (yaw - oldYaw);
  }else if(yaw < 0 && oldYaw < 0) {
    com = com + (yaw - oldYaw);
  }else if(yaw >= 0 && oldYaw < 0) {
    com = com + abs(yaw + oldYaw);
  }else if(yaw < 0 && oldYaw >= 0) {
    com = com + abs(yaw + oldYaw);
  }

  theta = theta+(com-precom);
  th = theta;
  if(th>0)th = th +7;
  else if (th <0)th = th -7;
  Serial.print(theta,5);  Serial.println("");

  //pose.data = com;

  oldYaw = yaw;
  precom = com;
 // pub.publish( &pose );

  //nh.spinOnce();

  
}
