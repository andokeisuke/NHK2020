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
float v ,w,X,Y,init_pose;

int now_pose,const_pose;

ros::Subscriber sub,imu_sub,spe_sub;
ros::Publisher	left_front_pub,
				left_rear_pub,
				right_front_pub,
				right_rear_pub;


custom_msg::wh_msg left_front,left_rear,right_front,right_rear;

void imu_messageCallback(const std_msgs::Int16::ConstPtr& imu){

	now_pose = imu->data;

}

void spe_messageCallback(const geometry_msgs::Twist::ConstPtr& spe){

	now_pose = spe->angular.z;

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

	w = -msg->angular.y;

	if(angular_vel != 0)//回転があるとき
	{


		temp_v = v*linear_vel;//angular_vel / WHEEL_RADIUS;
		temp_theta = 0;

		//if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)<=M_PI)temp_theta=(int(now_theta/(2*M_PI)))*2*M_PI;
		//else if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)>M_PI)temp_theta=(int(now_theta/(2*M_PI)+1))*2*M_PI;

			
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


		temp_v = 40;//angular_vel / WHEEL_RADIUS;
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
	else if(!((msg->linear.y ==0)&&(msg->linear.x ==0)&&(w ==0))&&angular_vel==0)//軸入力があった時
		{	

		
		

			if(!((msg->linear.y ==0)&&(msg->linear.x ==0)))
			{                 
			
				temp_theta = atan2(msg->linear.y,msg->linear.x);// - (now_pose-init_pose)/180*M_PI;

								
				if((temp_theta)>2*M_PI)temp_theta=temp_theta-2*M_PI;
				if((temp_theta)<-2*M_PI)temp_theta=temp_theta+2*M_PI;

				X = cos(temp_theta);
				Y = sin(temp_theta);




				
			}else if((msg->linear.y ==0)&&(msg->linear.x ==0)&&(w !=0)){

				X = 0;

				Y = 0;

			}

			ROS_ERROR("log:%f", now_pose-init_pose);
		

			//double error = -(now_pose-init_pose);
			//if(error<0)w = -0.001;
			//if(error>0)w = 0.001;
			//w = K*(0 - error);

			//if((now_pose-init_pose)>M_PI)w = K*(static_pose - ((now_pose-init_pose)-2*M_PI));
			//if((now_pose-init_pose)<-M_PI)w = K*(static_pose - ((now_pose-init_pose)+2*M_PI));

			//if(now_pose<-10)w = 0.01;
			//if(now_pose>10)w = -0.01;

		        //w = 0.01*now_pose;
		
			temp_v = v*linear_vel;
			left_front.st_target_deg = (atan2(Y + w/sqrt(2),X - w/sqrt(2)) - M_PI*3/4)/M_PI*180;//(temp_theta - M_PI*3/4)/M_PI*180;
			left_rear.st_target_deg = (atan2(Y - w/sqrt(2),X - w/sqrt(2)) + M_PI*3/4)/M_PI*180;//(temp_theta + M_PI*3/4)/M_PI*180;
			right_rear.st_target_deg = (atan2(Y - w/sqrt(2),X + w/sqrt(2)) + M_PI/4)/M_PI*180;//(temp_theta + M_PI/4)/M_PI*180;
			right_front.st_target_deg = (atan2(Y + w/sqrt(2),X + w/sqrt(2)) - M_PI/4)/M_PI*180;//(temp_theta - M_PI/4)/M_PI*180;

			//ROS_ERROR("log:%f", (atan2(Y + w/sqrt(2),X - w/sqrt(2)) - M_PI*3/4)/M_PI*180);

			left_front.wh_target_vel = -v*hypotf(Y - w/sqrt(2),X - w/sqrt(2));
			left_rear.wh_target_vel = -v*hypotf(Y + w/sqrt(2),X + w/sqrt(2));
			right_rear.wh_target_vel = -v*hypotf(Y + w/sqrt(2),X - w/sqrt(2));
			right_front.wh_target_vel = -v*hypotf(Y - w/sqrt(2),X - w/sqrt(2));

		}

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
	imu_sub = nh.subscribe("imu",10,imu_messageCallback);
	spe_sub = nh.subscribe("spe",10,spe_messageCallback);
	left_front_pub = nh.advertise<custom_msg::wh_msg>("left_front",1);
	left_rear_pub = nh.advertise<custom_msg::wh_msg>("left_rear",1);
	right_front_pub = nh.advertise<custom_msg::wh_msg>("right_front",1);
	right_rear_pub = nh.advertise<custom_msg::wh_msg>("right_rear",1);

	ros::spin();
	return 0;
}
