#include <ros/ros.h>
#include <std_msgs/Float64.h>

//pub side
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <custom_msg/wh_msg.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <sstream>

#define WHEEL_RADIUS 0.064

float temp_theta = 0;
float v ;

ros::Subscriber sub;
ros::Publisher	left_front_pub,
				left_rear_pub,
				right_front_pub,
				right_rear_pub;


custom_msg::wh_msg left_front,left_rear,right_front,right_rear;

void messageCallback(const geometry_msgs::Twist::ConstPtr& msg){

	//pub side


	float temp_v = 0;

	float linear_vel , angular_vel;

	linear_vel  = sqrt((msg->linear.x)*(msg->linear.x)+(msg->linear.y)*(msg->linear.y));
	if(linear_vel>1){
		linear_vel=1;

	}
	if(linear_vel<-1){
		linear_vel=-1;

	}
	angular_vel = msg->angular.z;

	if(angular_vel != 0)//回転があるとき
	{


		temp_v = v*linear_vel;//angular_vel / WHEEL_RADIUS;
		temp_theta = 0;

                if(angular_vel>0){
			left_front.st_target_deg = 0;
			left_rear.st_target_deg = 0;
			right_rear.st_target_deg = 0;
			right_front.st_target_deg = 0;
		}
		else{
			left_front.st_target_deg = 180;
			left_rear.st_target_deg = 180;
			right_rear.st_target_deg = 180;
			right_front.st_target_deg = 180;

		}

		

		left_front.wh_target_vel = -temp_v;
		left_rear.wh_target_vel = -temp_v;
		right_rear.wh_target_vel = -temp_v;
		right_front.wh_target_vel = -temp_v;

	}
	else if((!((msg->linear.y ==0)&&(msg->linear.x ==0)))&&angular_vel==0)//回転がないとき
	{
		

	        
		if(!((msg->linear.y ==0)&&(msg->linear.x ==0)))
		{                 
			if(!((temp_theta<-M_PI*99/100)&&(temp_theta>-M_PI*99/100))){
				temp_theta = atan2(msg->linear.y,msg->linear.x);
				}
		}
		if((temp_theta<-M_PI*99/100)||(temp_theta>M_PI*99/100))
		{

			temp_v = 0;
		}
		
		temp_v = v*linear_vel;//linear_vel / WHEEL_RADIUS;
		left_front.st_target_deg = (temp_theta + M_PI/4)/M_PI*180;
		left_rear.st_target_deg = (temp_theta - M_PI/4)/M_PI*180;
		right_rear.st_target_deg = (temp_theta + M_PI/4)/M_PI*180;
		right_front.st_target_deg = (temp_theta - M_PI/4)/M_PI*180;

		left_front.wh_target_vel = temp_v;
		left_rear.wh_target_vel = temp_v;
		right_rear.wh_target_vel = -temp_v;
		right_front.wh_target_vel = -temp_v;
	}
	else{


		left_front.wh_target_vel = 0;
		left_rear.wh_target_vel = 0;
		right_rear.wh_target_vel = 0;
		right_front.wh_target_vel = 0;

	}

	left_front_pub.publish(left_front);
	left_rear_pub.publish(left_rear);
	right_rear_pub.publish(right_rear);
	right_front_pub.publish(right_front);

}

int main(int argc,char **argv){
	ros::init(argc,argv,"sub_pub");
	ros::NodeHandle nh;
	nh.getParam("tf_twist/speed", v);

	sub = nh.subscribe("sub",10,messageCallback);

	left_front_pub = nh.advertise<custom_msg::wh_msg>("left_front",1);
	left_rear_pub = nh.advertise<custom_msg::wh_msg>("left_rear",1);
	right_front_pub = nh.advertise<custom_msg::wh_msg>("right_front",1);
	right_rear_pub = nh.advertise<custom_msg::wh_msg>("right_rear",1);

	ros::spin();
	return 0;
}
