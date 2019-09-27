#include <ros/ros.h>  // rosで必要はヘッダーファイル
#include <geometry_msgs/Twist.h> // ロボットを動かすために必要




double x = 0;
double y  = 0;
double theta = 0;
double b = 0;

double margin = 0.01;
int status =1;

struct target_point{

	double x;
	double y;

};



void spe_Callback(const geometry_msgs::Twist::ConstPtr& twist)
   {
	x = twist->linear.x;
	y = twist->linear.y;
	theta = twist->angular.z/180*M_PI;
   }






int main(int argc, char **argv){
    ros::init(argc, argv, "navigation");
    ros::NodeHandle n;

    ros::Subscriber spe_sub = n.subscribe<geometry_msgs::Twist>("/spe", 1, spe_Callback);
    ros::Publisher comand_pub = n.advertise<geometry_msgs::Twist>("/sub",1000);
    ros::Rate r(30.0);

    geometry_msgs::Twist comand;
    
    struct target_point first_point,second_point,third_point,forth_point;

    first_point.x = 0.0;
    first_point.y = 2.5;
    second_point.x = 0.6;
    second_point.y = 2.5;

    third_point.x = 0.6;
    third_point.y = 0.0;

    forth_point.x = 0.0;
    forth_point.y = 0.0;

    while(n.ok()){
	   //ros::spinOnce();
 
ROS_ERROR("log:%i", status);
	if(status ==1){
		b = atan2((first_point.y-y),(first_point.x-x));
		
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);


		comand_pub.publish(comand);
		if((fabs(first_point.y-y)<margin)&&(fabs(first_point.x-x)<margin)){
			status =2;
ROS_ERROR("log:%f", fabs(first_point.y-y));
		}
		
	
	}

	if(status ==2){
		b = atan2((second_point.y-y),(second_point.x-x));
		  // ROS_ERROR("log:%i", status);
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand_pub.publish(comand);
		
		if((fabs(second_point.y-y)<margin)&&(fabs(second_point.x-x)<margin)){
			status =3;

		}	
	}

	if(status ==3){
		b = atan2((third_point.y-y),(third_point.x-x));
		
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand_pub.publish(comand);
		
		if((fabs(third_point.y-y)<margin)&&(fabs(third_point.x-x)<margin)){
			status =4;

		}	
	}

	if(status ==4){
		b = atan2((forth_point.y-y),(forth_point.x-x));
		
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand_pub.publish(comand);
		
		if((fabs(forth_point.y-y)<margin)&&(fabs(forth_point.x-x)<margin)){
			status =0;

		}	
	}

	if(status == 0){
		
		comand.linear.x = 0;
		comand.linear.y = 0;
		comand_pub.publish(comand);
		

	}

    ros::spinOnce();
    r.sleep();
    }
}
