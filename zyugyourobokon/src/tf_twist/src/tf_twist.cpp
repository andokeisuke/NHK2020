#include <ros/ros.h>
#include <std_msgs/Float64.h>

//pub side
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <custom_msg/wh_msg.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int16.h>
#include <math.h>
#include <sstream>

#define WHEEL_RADIUS 0.064

float temp_theta = 0;
double now_theta = 0;
float v ;

int now_pose,const_pose;

ros::Subscriber sub,pose_sub;
ros::Publisher	left_front_pub,
				left_rear_pub,
				right_front_pub,
				right_rear_pub;


custom_msg::wh_msg left_front,left_rear,right_front,right_rear;

void pose_messageCallback(const std_msgs::Int16::ConstPtr& pose){

	now_pose = pose->data;

}

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

		if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)<=M_PI)temp_theta=(int(now_theta/(2*M_PI)))*2*M_PI;
		else if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)>M_PI)temp_theta=(int(now_theta/(2*M_PI)+1))*2*M_PI;

			
		left_front.st_target_deg = temp_theta/M_PI*180;
		left_rear.st_target_deg = temp_theta/M_PI*180;
		right_rear.st_target_deg = temp_theta/M_PI*180;
		right_front.st_target_deg =temp_theta/M_PI*180;		

                if(angular_vel>0){

			left_front.wh_target_vel = -temp_v;
			left_rear.wh_target_vel = -temp_v;
			right_rear.wh_target_vel = -temp_v;
			right_front.wh_target_vel = -temp_v;

			
		}
		else{

			left_front.wh_target_vel = temp_v;
			left_rear.wh_target_vel = temp_v;
			right_rear.wh_target_vel = temp_v;
			right_front.wh_target_vel = temp_v;



		}

		const_pose = now_pose;

	}
	else if(msg->linear.z != 0)//旋回があるとき
	{


		temp_v = v*linear_vel;//angular_vel / WHEEL_RADIUS;
		temp_theta = 0;

		if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)<=M_PI)temp_theta=(int(now_theta/(2*M_PI)))*2*M_PI;
		else if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)>M_PI)temp_theta=(int(now_theta/(2*M_PI)+1))*2*M_PI;

			
		left_front.st_target_deg = temp_theta/M_PI*180+(atan(455/75)-M_PI/4)/M_PI*180;
		left_rear.st_target_deg = temp_theta/M_PI*180-(atan(455/75)-M_PI/4)/M_PI*180;
		right_rear.st_target_deg = temp_theta/M_PI*180-(atan(275/75)-M_PI*3/4)/M_PI*180;
		right_front.st_target_deg =temp_theta/M_PI*180+(atan(275/75)-M_PI*3/4)/M_PI*180;		

                if(msg->linear.z>0){

			left_front.wh_target_vel = -temp_v*91/55;
			left_rear.wh_target_vel = -temp_v*91/55;
			right_rear.wh_target_vel = +temp_v;
			right_front.wh_target_vel = temp_v;

			
		}
		else{

			left_front.wh_target_vel = temp_v*91/55;
			left_rear.wh_target_vel = temp_v*91/55;
			right_rear.wh_target_vel = -temp_v;
			right_front.wh_target_vel = -temp_v;



		}



	}
	else if((!((msg->linear.y ==0)&&(msg->linear.x ==0)))&&angular_vel==0)//回転がないとき
	{
		

	        
		if(!((msg->linear.y ==0)&&(msg->linear.x ==0)))
		{                 
			
				temp_theta = atan2(msg->linear.y,msg->linear.x);

				//if((temp_theta-now_theta)>M_PI)temp_theta=temp_theta-2*M_PI;
				//if((temp_theta-now_theta)<-M_PI)temp_theta=temp_theta+2*M_PI;
				
		}

		temp_v = v*linear_vel;//linear_vel / WHEEL_RADIUS;
		left_front.st_target_deg = (temp_theta - M_PI*3/4)/M_PI*180;
		left_rear.st_target_deg = (temp_theta + M_PI*3/4)/M_PI*180;
		right_rear.st_target_deg = (temp_theta + M_PI/4)/M_PI*180;
		right_front.st_target_deg = (temp_theta - M_PI/4)/M_PI*180;

		left_front.wh_target_vel = -temp_v;//*0.8;
		left_rear.wh_target_vel = -temp_v;//*2.5;
		right_rear.wh_target_vel = -temp_v;//*2.5;
		right_front.wh_target_vel = -temp_v;//*0.8;
		
	//	if(abs(const_pose-now_pose)>1){
	//		if(const_pose-now_pose>0){
	//			left_front.wh_target_vel = -temp_v;
	////			left_rear.wh_target_vel = -temp_v*0.6;
	//			right_rear.wh_target_vel = -temp_v*0.6;
	//			right_front.wh_target_vel = -temp_v;


//			}
//			if(const_pose-now_pose<0){
//				left_front.wh_target_vel = -temp_v;
//				left_rear.wh_target_vel = -temp_v*0.6;
//				right_rear.wh_target_vel = -temp_v*0.6;
//				right_front.wh_target_vel = -temp_v;


//			}
			

//		}


	}
//	else if(msg->angular.x != 0)//90回転があるとき
//	{
//
//		double target_pose=0;
//		if(msg->angular.x>0) target_pose = const_pose-90;
//		else target_pose = const_pose+90;
//		
//		while(abs(target_pose-now_pose)>1){



//			temp_v =( target_pose-now_pose)/3*2;//angular_vel / WHEEL_RADIUS;
//			temp_theta = 0;

//			if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)<=M_PI)temp_theta=(int(now_theta/(2*M_PI)))*2*M_PI;
//			else if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)>M_PI)temp_theta=(int(now_theta/(2*M_PI)+1))*2*M_PI;
  //  ROS_FATAL("log:%f", temp_v);
			
	//		left_front.st_target_deg = temp_theta/M_PI*180;
	//		left_rear.st_target_deg = temp_theta/M_PI*180;
	//		right_rear.st_target_deg = temp_theta/M_PI*180;
	//		right_front.st_target_deg =temp_theta/M_PI*180;		

	//		left_front.wh_target_vel = -temp_v;
	//		left_rear.wh_target_vel = -temp_v;
	//		right_rear.wh_target_vel = -temp_v;
	//		right_front.wh_target_vel = -temp_v;

	//		left_front_pub.publish(left_front);
	//		left_rear_pub.publish(left_rear);
	//		right_rear_pub.publish(right_rear);
	//		right_front_pub.publish(right_front);

	//		ros::spinOnce();

	//	}
	//	const_pose = now_pose;

	//}
	

	else{


		left_front.wh_target_vel = 0;
		left_rear.wh_target_vel = 0;
		right_rear.wh_target_vel = 0;
		right_front.wh_target_vel = 0;

		const_pose = now_pose;

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
	



	now_theta = temp_theta;

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
	pose_sub = nh.subscribe("imu",10,pose_messageCallback);
	left_front_pub = nh.advertise<custom_msg::wh_msg>("left_front",1);
	left_rear_pub = nh.advertise<custom_msg::wh_msg>("left_rear",1);
	right_front_pub = nh.advertise<custom_msg::wh_msg>("right_front",1);
	right_rear_pub = nh.advertise<custom_msg::wh_msg>("right_rear",1);

	ros::spin();
	return 0;
}
