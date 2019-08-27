#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <Wire.h>


#include <ros.h>
#include <custom_msg/wh_msg.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>

#include <std_msgs/Float64.h>

#include "ti2c.h"
#include "ise_motor_driver.h"
#define ENC_PER_DEG 13//１度のエンコーダの値


ros::NodeHandle  nh;

struct MotorHandler
{
  public:
  double target_vel;

};



// ============================== arguments ==============================

IseMotorDriver right_front = IseMotorDriver(0x62);//62
IseMotorDriver right_rear = IseMotorDriver(0x61);//61
IseMotorDriver left_front = IseMotorDriver(0x21);//21
IseMotorDriver left_rear = IseMotorDriver(0x63);//63
IseMotorDriver right_front_st = IseMotorDriver(0x24);//24
IseMotorDriver right_rear_st = IseMotorDriver(0x35);//35
IseMotorDriver left_front_st = IseMotorDriver(0x33);//33
IseMotorDriver left_rear_st = IseMotorDriver(0x34);//34    

                                                         

MotorHandler right_front_handler;
MotorHandler right_rear_handler;
MotorHandler left_front_handler;
MotorHandler left_rear_handler;
MotorHandler right_front_st_handler;
MotorHandler right_rear_st_handler;
MotorHandler left_front_st_handler;
MotorHandler left_rear_st_handler;

std_msgs::Int16MultiArray array;


// ============================== callback ==============================

void set_target(MotorHandler *mh, MotorHandler *mh_st, double target_vel, double target_deg_st)
{
  mh -> target_vel = target_vel;
  mh_st -> target_vel = (target_deg_st) * ENC_PER_DEG;
}





void wh_cb_rfront(const custom_msg::wh_msg& msg)
{
  set_target(&right_front_handler, &right_front_st_handler, msg.wh_target_vel, msg.st_target_deg);

  right_front_st.setSpeed(right_front_st_handler.target_vel);
  right_front.setSpeed(right_front_handler.target_vel);
}

void wh_cb_rrear(const custom_msg::wh_msg& msg)
{
  set_target(&right_rear_handler, &right_rear_st_handler, msg.wh_target_vel, msg.st_target_deg);

  right_rear.setSpeed(right_rear_handler.target_vel);
  right_rear_st.setSpeed(right_rear_st_handler.target_vel);
}

void wh_cb_lfront(const custom_msg::wh_msg& msg)
{
  
  set_target(&left_front_handler, &left_front_st_handler, msg.wh_target_vel, msg.st_target_deg);

  left_front.setSpeed(left_front_handler.target_vel);
  left_front_st.setSpeed(left_front_st_handler.target_vel);
  
}

void wh_cb_lrear(const custom_msg::wh_msg& msg)
{
  set_target(&left_rear_handler, &left_rear_st_handler, msg.wh_target_vel, msg.st_target_deg);

  left_rear.setSpeed(left_rear_handler.target_vel);
  left_rear_st.setSpeed(left_rear_st_handler.target_vel);
}


ros::Subscriber<custom_msg::wh_msg>right_front_sub("right_front",wh_cb_rfront);
ros::Subscriber<custom_msg::wh_msg>right_rear_sub("right_rear",wh_cb_rrear);
ros::Subscriber<custom_msg::wh_msg>left_front_sub("left_front",wh_cb_lfront);
ros::Subscriber<custom_msg::wh_msg>left_rear_sub("left_rear",wh_cb_lrear);


std_msgs::Float64 msg;
ros::Publisher chatter("chatter", &msg);

// ==================== functions ==================== //

int vel_time = 0;



void setup() {

  
  Wire.begin();
  nh.initNode();

  
  nh.subscribe(right_front_sub);
  nh.subscribe(right_rear_sub);
  nh.subscribe(left_front_sub);
  nh.subscribe(left_rear_sub);



  nh.advertise(chatter);

 

  
}



void loop() {
 


//  msg.data = left_rear_handler.target_vel;
 // chatter.publish( &msg );

 delay(5);
  nh.spinOnce();
  
}
