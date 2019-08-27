#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "sensor_msgs/Joy.h"

ros::Subscriber joy_sub;
ros::Publisher twist_pub;


void messageCallback(const sensor_msgs::Joy::ConstPtr& joy){
	
	ROS_INFO("%f",joy->axes[1]);
	
	geometry_msgs::Twist twist;

	twist.linear.x = -joy->axes[0];
	twist.linear.y = joy->axes[1];
	twist.linear.z = 0;

	twist.angular.x = 0;
	twist.angular.y = 0;
	if(joy->buttons[4]==1 || joy->buttons[5]==1){
		if(joy->buttons[4]==1){
			twist.angular.z = -1;
		}		

		if(joy->buttons[5]==1){
			twist.angular.z = 1;
		}
	
	}else{
		twist.angular.z = 0;
	}

	twist_pub.publish(twist);




}

int main(int argc,char **argv){
	ros::init(argc,argv,"joy_twist");
	ros::NodeHandle nh;

	joy_sub = nh.subscribe("joy",10,messageCallback);
	twist_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel",1);

	ros::spin();
	return 0;
}



