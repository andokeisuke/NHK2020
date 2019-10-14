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
double static_pose = 0;
double init_pose = 0;
int flag = 1;

double linear_x,linear_y,linear_z,angular_x;
float linear_vel , angular_vel;

double K = 0.07;

double now_pose,const_pose,X,Y,w;

ros::Subscriber sub,imu_sub,spe_sub;
ros::Publisher	left_front_pub,
				left_rear_pub,
				right_front_pub,
				right_rear_pub;



custom_msg::wh_msg left_front,left_rear,right_front,right_rear;

void imu_messageCallback(const std_msgs::Int16::ConstPtr& imu){

	//now_pose = imu->data;

}

void spe_messageCallback(const geometry_msgs::Twist::ConstPtr& spe){

	now_pose = spe->angular.z;

}
void messageCallback(const geometry_msgs::Twist::ConstPtr& msg){

	//pub side





	linear_x = msg->linear.x;
	linear_y = msg->linear.y;
	linear_z = msg->linear.z;
	linear_vel = hypotf(linear_x,linear_y);

	angular_x = msg->angular.x;
	angular_vel = msg->angular.z;
	w = -msg->angular.y;


}

int main(int argc,char **argv){
	ros::init(argc,argv,"sub_pub");
	ros::NodeHandle nh;
	nh.getParam("tf_twist/speed", v);

	sub = nh.subscribe("sub",10,messageCallback);
	spe_sub = nh.subscribe("spe",1,spe_messageCallback);
	imu_sub = nh.subscribe("imu",1,imu_messageCallback);
	left_front_pub = nh.advertise<custom_msg::wh_msg>("left_front",1);
	left_rear_pub = nh.advertise<custom_msg::wh_msg>("left_rear",1);
	right_front_pub = nh.advertise<custom_msg::wh_msg>("right_front",1);
	right_rear_pub = nh.advertise<custom_msg::wh_msg>("right_rear",1);
	ros::Rate loop_rate(10);

	while(ros::ok()){

		float temp_v = 0;
		
		ros::spinOnce();
		
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

			static_pose = now_pose-init_pose;

		}
	


		else if(linear_z != 0)//旋回があるとき
		{


			temp_v = v*linear_vel;//angular_vel / WHEEL_RADIUS;
			temp_theta = 0;

			if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)<=M_PI)temp_theta=(int(now_theta/(2*M_PI)))*2*M_PI;
			else if(abs((int(now_theta/(2*M_PI)))*2*M_PI-now_theta)>M_PI)temp_theta=(int(now_theta/(2*M_PI)+1))*2*M_PI;

			
			left_front.st_target_deg = temp_theta/M_PI*180+(atan(455/75)-M_PI/4)/M_PI*180;
			left_rear.st_target_deg = temp_theta/M_PI*180-(atan(455/75)-M_PI/4)/M_PI*180;
			right_rear.st_target_deg = temp_theta/M_PI*180-(atan(275/75)-M_PI*3/4)/M_PI*180;
			right_front.st_target_deg =temp_theta/M_PI*180+(atan(275/75)-M_PI*3/4)/M_PI*180;		

		        if(linear_z>0){

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
			static_pose = now_pose-init_pose;


		}
		else if(!((linear_y ==0)&&(linear_x ==0)&&(w ==0))&&angular_vel==0)//軸入力があった時
		{	if(flag==1){

				static_pose =now_pose-init_pose;
				flag = 0;
			}
		
		
		

			if(!((linear_y ==0)&&(linear_x ==0)))
			{                 
			
				temp_theta = atan2(linear_y,linear_x);// - (now_pose-init_pose)/180*M_PI;

								
				if((temp_theta)>2*M_PI)temp_theta=temp_theta-2*M_PI;
				if((temp_theta)<-2*M_PI)temp_theta=temp_theta+2*M_PI;

				X = cos(temp_theta);
				Y = sin(temp_theta);




				
			}else if((linear_y ==0)&&(linear_x ==0)&&(w !=0)){

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

			static_pose = now_pose-init_pose;

		}

		if(angular_x){

			left_front.st_target_deg = 0;
			left_rear.st_target_deg = 0;
			right_rear.st_target_deg = 0;
			right_front.st_target_deg = 0;
			left_front.wh_target_vel = 0;
			left_rear.wh_target_vel = 0;
			right_rear.wh_target_vel = 0;
			right_front.wh_target_vel = 0;
			init_pose = now_pose;
			flag = 1;


		}
	



		now_theta = temp_theta;
		loop_rate.sleep();
		left_front_pub.publish(left_front);
		left_rear_pub.publish(left_rear);
		right_rear_pub.publish(right_rear);
		right_front_pub.publish(right_front);


	}
	return 0;
}
