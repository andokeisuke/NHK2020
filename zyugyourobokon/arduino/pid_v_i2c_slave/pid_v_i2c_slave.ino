#include <TimerOne.h>
#include <Wire.h>

#include "ti2c_slave.h"



#define PWMH 5
#define PWML 6
#define dir 7
#define SR 4

volatile long int temp, counter = 0;

volatile long double v = 0;
const float Kp=1950.4;//1950.4;//2.0455;//0.63919;
const float Ki=0;//0;//0.87196;//0;
const float Kd=3.9111;//39.111;//0.0047161;//0.25552;
long double targetv=0;
float P=0;
float preP=0;
float dt=0.003;
float I=0;
float D=0;
float duty=0;
int pw = 0;
float preTime=0;
long double enc = 0;
long double preenc =0;
long double prepw =0;
int state = false;

int I2C_address = 0x22;
Ti2c receiver(I2C_address);

ISR(PCINT1_vect,ISR_NOBLOCK){
  if((PINC & (1<<PINC0))^((PINC & (1<<PINC1))>>1))--counter;
  else ++counter;
  
  }


void setup() {
  PCICR |= (1<<PCIE1);
  PCMSK1 |=(1<<PCINT8);

  
  //I2C_address = 0x22;
  
  Serial.begin (9600);

  pinMode(PWML, OUTPUT);
  pinMode(PWMH, OUTPUT);
  pinMode(SR,OUTPUT); 
  pinMode(dir, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);

  digitalWrite(SR,LOW);
  
  Timer1.initialize(3000);
  Timer1.attachInterrupt(PID);

  Wire.begin(I2C_address);   // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent);

}



 
void loop() {
  //enc = counter;
  //v = (enc - preenc)/dt/4000*3.14*0.064;

}


void PID(){
    enc = counter;
    v = (enc - preenc)/dt/4000*3.14*0.064;
    
    P = targetv - v;
    
    I += P*dt;
    
    D = (P - preP)/dt;
    
    duty = Kp * P + Ki * I + Kd * D;
    //duty = 30;
    
    preP = P;
    preenc = enc;
    if(duty>50)duty=50;
    if(duty<-50)duty=-50;
    
    if(duty>=0)PORTD &= ~_BV(PD7);//digitalWrite(dir,LOW);
    else PORTD |= _BV(PD7);//digitalWrite(dir,HIGH);

    pw = abs(int(duty));

    analogWrite(PWML,pw);
    analogWrite(PWMH,pw);

  }




void receiveEvent(int howMany)
{
  receiver.receiveStr();
  targetv = double(atoi(receiver.buf))/1000;

  P = 0;
  preP = 0;
  D = 0;
  I = 0;

  
}

void requestEvent(){
  
  char buf[10] = {};
  int num;
  //num = sprintf(buf, "%d$", int(v*1000*5/4));
  num = sprintf(buf, "%d$", int(duty));

  receiver.sendStr(buf);
  //Serial.println(buf); 
  
  
  }

