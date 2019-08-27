#include <Wire.h>
#include <stdlib.h>
#include "ti2c.h"
#include "pid_driver.h"

uint8_t addr = 0x23;
PidDriver m1 = PidDriver(addr);

int degree = 0;

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
////////   
   // m1.setdegree(70);
//    delay(4000);
//  m1.setdegree(0);
//    delay(4000);
//Serial.print("ssss");
int enc = m1.encorder();
Serial.println(enc);
//delay(100);

 
 // Serial.println(enc);
 
  }
