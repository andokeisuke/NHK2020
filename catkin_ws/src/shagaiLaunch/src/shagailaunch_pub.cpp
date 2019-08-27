#include"ros/ros.h"
#include"std_msgs/Int8.h"
#include"std_msgs/String.h"
#include<string>
#include<shagaiLaunch/shagaiLaunch_msg.h>
#include <iostream>
#include <cstdio>
#include<sstream>


int PHASE = 0;
std::string ACTION("push");

//a="";

int main(int argc,char **argv){
	
	//node name "shagaiLaunch_pub"
	ros::init(argc,argv,"shagaiLaunch_pub"); 
	ros::NodeHandle nh;

	//publisher name "pub", select message type "shagaiLaunch_msg", topic name "shagaiLaunch_phase"
	ros::Publisher pub = nh.advertise <shagaiLaunch::shagaiLaunch_msg>("shagaiLaunch_phase",1000);

	ros::Rate loop_rate(10); //loop 10Hz
	while(ros::ok()){

		//message name "msg" 
		shagaiLaunch::shagaiLaunch_msg msg; 

		msg.phase = PHASE;
		msg.action = ACTION;

		pub.publish(msg); //publish msg

		ros::spinOnce;
		loop_rate.sleep();

	}
	return 0;
}
