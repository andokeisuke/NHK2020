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
#define r 0.15

float temp_theta = 0;
double now_theta = 0;
double pose,theta = 0;
double w = 0;
float v ;

float gain,k;

ros::Subscriber sub,pose_sub;
ros::Publisher	left_front_pub,
				left_rear_pub,
				right_front_pub,
				right_rear_pub;


custom_msg::wh_msg left_front,left_rear,right_front,right_rear;

void messageCallback_pose(const std_msgs::Float64::ConstPtr& pose){

	theta = pose->data;



}

void messageCallback(const geometry_msgs::Twist::ConstPtr& msg){

	//pub side


	float temp_v = 0;

	float linear_vel,vel_x,vel_y, w,rsin,rcos;

	vel_x = msg->linear.x;
	vel_y = msg->linear.y;


	rsin = r * w * sin(theta+M_PI/4);
	rcos = r * w * cos(theta+M_PI/4);


	

	

	linear_vel  = sqrt((msg->linear.x)*(msg->linear.x)+(msg->linear.y)*(msg->linear.y));
	if(linear_vel>1){

		linear_vel=1;


	}
	if(linear_vel<-1){
		linear_vel=-1;

	}
	

	if(angular_vel != 0)//回転があるとき
	{

		w = k * angular_vel;
		rsin = r * w * sin(theta+M_PI/4);
		rcos = r * w * cos(theta+M_PI/4);

		left_front.st_target_deg = atan((vel_y-rsin)/(vel_x-rcos))/M_PI*180-(theta+M_PI/4);
		left_rear.st_target_deg = atan((vel_y-rcos)/(vel_x+rsin))/M_PI*180-(theta+M_PI/4);
		right_rear.st_target_deg = atan((vel_y+rsin)/(vel_x+rcos))/M_PI*180-(theta+M_PI/4);
		right_front.st_target_deg =atan((vel_y+rcos)/(vel_x-rsin))/M_PI*180-(theta+M_PI/4);		

		left_front.wh_target_vel = -sqrt((vel_y-rsin)*(vel_y-rsin)+(vel_x-rcos)*(vel_x-rcos));
		left_rear.wh_target_vel = -sqrt((vel_y-rcos)*(vel_y-rcos)+(vel_x+rsin)*(vel_x+rsin));
		right_rear.wh_target_vel = -sqrt((vel_y+rsin)*(vel_y+rsin)+(vel_x+rcos)*(vel_x+rcos));
		right_front.wh_target_vel = -sqrt((vel_y+rcos)*(vel_y+rcos)+(vel_x-rsin)*(vel_x-rsin));

		pose = theta;

//１８０度以上回転を小さくする、０度の移り変わり

		

	}
	else if((!((msg->linear.y ==0)&&(msg->linear.x ==0)))&&angular_vel==0)//回転がないとき
	{
		
		
		w = gain * (pose-theta);
		rsin = r * w * sin(theta+M_PI/4);
		rcos = r * w * cos(theta+M_PI/4);

		left_front.st_target_deg = atan((vel_y-rsin)/(vel_x-rcos))/M_PI*180-(theta+M_PI/4);
		left_rear.st_target_deg = atan((vel_y-rcos)/(vel_x+rsin))/M_PI*180-(theta+M_PI/4);
		right_rear.st_target_deg = atan((vel_y+rsin)/(vel_x+rcos))/M_PI*180-(theta+M_PI/4);
		right_front.st_target_deg =atan((vel_y+rcos)/(vel_x-rsin))/M_PI*180-(theta+M_PI/4);		

		left_front.wh_target_vel = -sqrt((vel_y-rsin)*(vel_y-rsin)+(vel_x-rcos)*(vel_x-rcos));
		left_rear.wh_target_vel = -sqrt((vel_y-rcos)*(vel_y-rcos)+(vel_x+rsin)*(vel_x+rsin));
		right_rear.wh_target_vel = -sqrt((vel_y+rsin)*(vel_y+rsin)+(vel_x+rcos)*(vel_x+rcos));
		right_front.wh_target_vel = -sqrt((vel_y+rcos)*(vel_y+rcos)+(vel_x-rsin)*(vel_x-rsin));


	}
	else{


		left_front.wh_target_vel = 0;
		left_rear.wh_target_vel = 0;
		right_rear.wh_target_vel = 0;
		right_front.wh_target_vel = 0;

	}

	if(msg->angular.x){

		left_front.st_target_deg = 0;
		left_rear.st_target_deg = 0;
		right_rear.st_target_deg = 0;
		right_front.st_target_deg = 0;
		left_front.wh_target_vel = 0;
		left_rear.wh_target_vel = 0;
		right_rear.wh_target_vel = 0;
		right_front.wh_target_vel = 0;
		


	}

	//now_theta = temp_theta;

	left_front_pub.publish(left_front);
	left_rear_pub.publish(left_rear);
	right_rear_pub.publish(right_rear);
	right_front_pub.publish(right_front);

}




int main(int argc,char **argv){
	ros::init(argc,argv,"sub_pub");
	ros::NodeHandle nh;
	nh.getParam("tf_twist/speed", v);

	pose_sub = nh.subscribe("pose",10,messageCallback_pose);
	sub = nh.subscribe("sub",10,messageCallback);


	left_front_pub = nh.advertise<custom_msg::wh_msg>("left_front",1);
	left_rear_pub = nh.advertise<custom_msg::wh_msg>("left_rear",1);
	right_front_pub = nh.advertise<custom_msg::wh_msg>("right_front",1);
	right_rear_pub = nh.advertise<custom_msg::wh_msg>("right_rear",1);

	ros::spin();
	return 0;
}
