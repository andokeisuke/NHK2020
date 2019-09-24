#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listener");

  ros::NodeHandle node;

  
  ros::Publisher spe_pub =node.advertise<geometry_msgs::Twist>("/spe", 10);

  tf::TransformListener tf_listener;
  geometry_msgs::Twist spe ;
  ros::Rate rate(10.0);
  while (node.ok()){

try
{
	tf::StampedTransform trans;
	tf_listener.waitForTransform("map", "base_link", 
			ros::Time(0), ros::Duration(0.5));
	tf_listener.lookupTransform("map", "base_link", 
			ros::Time(0), trans);
	spe.linear.x = trans.getOrigin().x();
	spe.linear.y = trans.getOrigin().y();
	spe.angular.z = tf::getYaw(trans.getRotation())/M_PI*180;
}
catch(tf::TransformException &e)
{
	ROS_WARN("%s", e.what());
}
  spe_pub.publish(spe);
  
  }
  return 0;
};


