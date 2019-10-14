#include <ros/ros.h>  // rosで必要はヘッダーファイル
#include <std_msgs/Int64.h>
#include <std_msgs/Int16.h>
#include <geometry_msgs/Twist.h> // ロボットを動かすために必要
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>
#include <tf/tf.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_datatypes.h>
#include <gazebo_msgs/ModelStates.h> 
#include <sensor_msgs/JointState.h>
#include <iostream>

double state_odom_x=0.0;//オドメトリX座標[m]
double state_odom_y=0.0;//オドメトリY座標[m]
double state_odom_th=0.0; //オドメトリ姿勢[rad]
double predistance = 0;
double preenc = 0;
double x = 0;
double y  = 0;
double z = 0;
double w = 0;
double r = 0;
double th = 0;
double th_pre = 0;
double th_init = 0;
double a = 0;
double b = 0;
    
double X = 0;
double Y = 0;
double Z = 0;
double W = 0;
int init = 0;
int flag = 1;

double roll,pitch,yaw;


geometry_msgs::Quaternion odom_quat;
void twist_Callback(const geometry_msgs::Twist::ConstPtr& twist)
   {
	x = twist->linear.x;
	y = twist->linear.y;
	z = twist->linear.z;
	w = twist->angular.z;
	init = twist->angular.x;
        r = sqrt(x*x+y*y);



   }

void imu_Callback(const std_msgs::Int16::ConstPtr& imu)
   {

	double theta = double(imu->data)/180*M_PI-th_pre; 

	if(fabs(theta)>=M_PI){
		if(theta > 0) theta = theta + 2 * M_PI;
		else theta = theta - 2*M_PI;


	}
	th = th +(double(imu->data)/180*M_PI-th_pre);
	 //ROS_ERROR("log:%f", th_init);
        odom_quat = tf::createQuaternionMsgFromYaw(th-th_init);

	th_pre = th;
		

   }

void enc_Callback(const std_msgs::Int64::ConstPtr& enc)
   {

	double left_rear_enc = enc->data; // 右車軸の位置[rad]
	double distance = left_rear_enc/3700;//1084*M_PI*0.064;//３７００：１ｍあたりのエンコーダ増加量
	a = atan2(y,x);		

	if(z != 0){//旋回の時
		b = -(enc->data-preenc)/2600*(M_PI/2*0.35)/0.35;

		
		state_odom_x=state_odom_x+0.7*sin(b/2)*cos(b/2+th-th_init);
     		state_odom_y=state_odom_y+ 0.7*sin(b/2)*sin(b/2+th-th_init);
		//th =th+b;


	}
	else{

	     if(w == 0&&r !=0){//回転せず止まっていない時



	     	state_odom_x= state_odom_x+(distance-predistance)*cos(a+th-th_init);
	     	state_odom_y= state_odom_y+ (distance-predistance)*sin(a+th-th_init);
	     }
	       //th = th- (enc->data-preenc)/700*M_PI/2* abs(w);//７００：９０度あたりのエンコーダの増加量
	      // odom_quat = tf::createQuaternionMsgFromYaw(th);

	}
	predistance  = distance;
	preenc = enc->data;
 
   }





int main(int argc, char **argv){
    ros::init(argc, argv, "odom");
    ros::NodeHandle n;
    tf::TransformBroadcaster odom_broadcaster;
    ros::Time current_time;
    current_time = ros::Time::now();
    ros::Subscriber enc_sub = n.subscribe<std_msgs::Int64>("/enc", 1, enc_Callback);
    ros::Subscriber imu_sub = n.subscribe<std_msgs::Int16>("/imu", 1, imu_Callback);
    ros::Subscriber twist_sub = n.subscribe<geometry_msgs::Twist>("/sub", 1, twist_Callback);
    ros::Publisher odm_pub = n.advertise<geometry_msgs::TransformStamped>("/odometry",1000);
    ros::Publisher pose_pub = n.advertise<geometry_msgs::Twist>("/pose",1000);
    ros::Rate r(30.0);
    geometry_msgs::TransformStamped odom_trans;
    geometry_msgs::Twist pose_trans;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";

    while(n.ok()){

    current_time = ros::Time::now();
    
    odom_trans.header.stamp = current_time;

    ros::spinOnce();
    if(init == 1){
	state_odom_x = 0;
	state_odom_y = 0;
	//odom_quat = tf::createQuaternionMsgFromYaw(0);
	th_init = th;
	th_pre =th;


    }



    odom_trans.transform.translation.x = state_odom_x;
    odom_trans.transform.translation.y = state_odom_y;
    odom_trans.transform.translation.z = 0.0;

    pose_trans.linear.x = state_odom_x;
    pose_trans.linear.y = state_odom_y;
    pose_trans.linear.z = 0;
    

    odom_trans.transform.rotation = odom_quat;



    pose_trans.angular.x = a;
    pose_trans.angular.z = (th-th_init)/M_PI*180;

    odom_broadcaster.sendTransform(odom_trans);
    odm_pub.publish(odom_trans);
    pose_pub.publish(pose_trans);

    ros::spinOnce();
    r.sleep();
    }
}
