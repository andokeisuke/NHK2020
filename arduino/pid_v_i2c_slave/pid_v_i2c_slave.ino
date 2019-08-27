#include <TimerOne.h>
#include <Wire.h>

#include "ti2c_slave.h"


#define encA 2
#define encB 3
#define PWMH 5
#define PWML 6
#define dir 7

volatile long int temp, counter = 0;

volatile long double v = 0;
const float Kp=100;//2.0455;//0.63919;
const float Ki=90;//0.87196;//0;
const float Kd=0;//0.0047161;//0.25552;
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

int I2C_address;
Ti2c receiver(0x34);

ISR(PCINT1_vect,ISR_NOBLOCK){
  if((PINC & (1<<PINC0))^((PINC & (1<<PINC1))>>1))--counter;
  else ++counter;
  
  }


void setup() {
  PCICR |= (1<<PCIE1);
  PCMSK1 |=(1<<PCINT8);

  
  I2C_address = 0x34;
  
  Serial.begin (9600);
 
  pinMode(encA, INPUT_PULLUP);
 
  pinMode(encB, INPUT_PULLUP);

  pinMode(PWML, OUTPUT);
  pinMode(PWMH, OUTPUT);
 
  pinMode(dir, OUTPUT);
  //interuptをセットアップする
  //
  //attachInterrupt(0, ai0, RISING);
 
  //
  //attachInterrupt(1, ai1, RISING);
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);


  

 Timer1.initialize(3000);
 
Timer1.attachInterrupt(PID);

 Wire.begin(I2C_address);   // join i2c bus with address #8
 
 Wire.onReceive(receiveEvent); // register event
  
 Wire.onRequest(requestEvent);
 _SFR_BYTE(TCCR2A) |= _BV(COM2A1);
  // fast PWM mode
  // 動作クロックは分周なしの8MHz
  // PWMキャリア波の周波数は8MHz/256=31.25kHz
}



 
void loop() {
enc = counter;

    v = (enc - preenc)/dt/4000*3.14*0.064;
    
  //PID();
 //analogWrite(PWM,pw);
}


void PID(){
    

    
    P = targetv - v;
    
    I += P*dt;
    
    D = (P - preP)/dt;
    
    duty = Kp * P + Ki * I + Kd * D;

    preP = P;
    preenc = enc;
    if(duty>255)duty=255;
    if(duty<-255)duty=-255;
    
    if(duty>=0)PORTD &= ~_BV(PD7);//digitalWrite(dir,LOW);
    else PORTD |= _BV(PD7);//digitalWrite(dir,HIGH);

    pw = abs(int(duty));
    //OCR2A = pw; //analogWrite(PWM,pw);
    analogWrite(PWML,pw);
    analogWrite(PWMH,pw);

  }



  

void ai0() {
  unsigned char a;

  a = PIND & _BV(PD3);
  //a= digitalRead(3);
  
  if (a == LOW) {
    counter++;
  } else {
    counter--;
  }
}
 
void ai1() {
  
   unsigned char a;

   a = PIND & _BV(PD2);

  //a=digitalRead(2);
  
  if (a == LOW) {
    counter--;
  } else {
    counter++;
  }
}



void receiveEvent(int howMany)
{
  receiver.receiveStr();
  targetv = double(atoi(receiver.buf))/100;
}

void requestEvent(){
  
  char buf[10] = {};
  int num;
  num = sprintf(buf, "%d$", int(enc));


  receiver.sendStr(buf);
  //Serial.println(buf); 
  
  
  }

