#include <ros/ros.h>
#include <std_msgs/Float64.h>

//pub side
#include"ros/ros.h"
#include"std_msgs/String.h"
#include<geometry_msgs/Twist.h>
#include<math.h>
#include<sstream>
int thetachange(float x,float y);
double pretheta;
int speed;
ros::Subscriber sub;
ros::Publisher kudou1_pub,kudou2_pub,kudou3_pub,kudou4_pub,yaw1_pub,yaw2_pub,yaw3_pub,yaw4_pub;

void messageCallback(const geometry_msgs::Twist::ConstPtr& msg){
	//pub side
	std_msgs::Float64 v,theta;
	if(msg->angular.z==0){
			//theta.data= thetachange(msg->linear.x,msg->linear.y)*M_PI/180;
		if(msg->linear.y==0&&msg->linear.x==0){
			theta.data = pretheta;
		
		}else{
			theta.data =thetachange(msg->linear.x,msg->linear.y)*M_PI/180;

		}
		
		v.data=sqrt((msg->linear.x)*(msg->linear.x)+(msg->linear.y)*(msg->linear.y));

		v.data=speed*v.data;
		
			kudou1_pub.publish(v);
			kudou2_pub.publish(v);
			kudou3_pub.publish(v);
			kudou4_pub.publish(v);
			yaw1_pub.publish(theta);
			yaw2_pub.publish(theta);
			yaw3_pub.publish(theta);
			yaw4_pub.publish(theta);
			
			pretheta = theta.data;

	}else{

		if(msg->angular.z>0){
			theta.data = M_PI*3/4;
			yaw1_pub.publish(theta);
			theta.data = -M_PI*3/4;
			yaw2_pub.publish(theta);
			theta.data = -M_PI/4;
			yaw3_pub.publish(theta);
			theta.data = M_PI/4;
			yaw4_pub.publish(theta);		
			

		}else{
			theta.data = -M_PI/4;
			yaw1_pub.publish(theta);
			theta.data = M_PI/4;
			yaw2_pub.publish(theta);
			theta.data = M_PI*3/4;
			yaw3_pub.publish(theta);
			theta.data = -M_PI*3/4;
			yaw4_pub.publish(theta);



		}

		v.data = speed;
		kudou1_pub.publish(v);
		kudou2_pub.publish(v);
		kudou3_pub.publish(v);
		kudou4_pub.publish(v);



	}

	









}

int main(int argc,char **argv){
	ros::init(argc,argv,"tf_twist");
	ros::NodeHandle nh;
	nh.getParam("twist_gazebo/speed", speed);

	sub = nh.subscribe("cmd_vel",10,messageCallback);
	kudou1_pub = nh.advertise<std_msgs::Float64>("/assemble/kudou1_velocity_controller/command",1);
	kudou2_pub = nh.advertise<std_msgs::Float64>("/assemble/kudou2_velocity_controller/command",1);
	kudou3_pub = nh.advertise<std_msgs::Float64>("/assemble/kudou3_velocity_controller/command",1);
	kudou4_pub = nh.advertise<std_msgs::Float64>("/assemble/kudou4_velocity_controller/command",1);
	yaw1_pub = nh.advertise<std_msgs::Float64>("/assemble/yaw1_position_controller/command",1);
	yaw2_pub = nh.advertise<std_msgs::Float64>("/assemble/yaw2_position_controller/command",1);
	yaw3_pub = nh.advertise<std_msgs::Float64>("/assemble/yaw3_position_controller/command",1);
	yaw4_pub = nh.advertise<std_msgs::Float64>("/assemble/yaw4_position_controller/command",1);

	ros::spin();
	return 0;
}




int thetachange(float x,float y){
	int theta = atan(y/x)*180/M_PI;

	if(x<0&&y>=0){

		theta = theta + 180;
	}

	if(x<0&&y<0){

		theta = theta + 180;
	}
	if(x>=0&&y<0){

		theta = theta + 360;
	}


	return theta;

}
