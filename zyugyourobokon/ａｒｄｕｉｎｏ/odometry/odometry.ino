#include <ros.h>
#include <std_msgs/Int64.h>

ros::NodeHandle  nh;
volatile  int temp, counter = 0;

std_msgs::Int64 enc;
ros::Publisher chatter("enc", &enc);

void setup() {
  Serial.begin (9600);
  nh.initNode();
 
  pinMode(2, INPUT_PULLUP);
 
  pinMode(3, INPUT_PULLUP);
  //interuptをセットアップする
  //
  attachInterrupt(0, ai0, RISING);
 
  //
  attachInterrupt(1, ai1, RISING);

  nh.advertise(chatter);
}
 
void loop() {
  // カウンターの値を出力する
  if ( counter != temp ) {
    Serial.println (counter);
    temp = counter;
  }

  enc.data = counter;

  chatter.publish( &enc );
  nh.spinOnce();
}
 
void ai0() {
  if (digitalRead(3) == LOW) {
    counter++;
  } else {
    counter--;
  }
}
 
void ai1() {
  if (digitalRead(2) == LOW) {
    counter--;
  } else {
    counter++;
  }
}
