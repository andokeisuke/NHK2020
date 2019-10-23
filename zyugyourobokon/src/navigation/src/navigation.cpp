#include <ros/ros.h>  // rosで必要はヘッダーファイル
#include <geometry_msgs/Twist.h> // ロボットを動かすために必要




double x = 0;
double y  = 0;
double theta = 0;
double b = 0;
double k;

double margin;
float status =1;
double pretheta = 0;
float prestatus;
double count =0;

struct target_point{

	double x;
	double y;

};
geometry_msgs::Twist comand;
ros::Publisher comand_pub;

void auto_turn(int state);

void spe_Callback(const geometry_msgs::Twist::ConstPtr& twist)
   {
	x = twist->linear.x;
	y = twist->linear.y;
	if((twist->angular.z/180*M_PI-pretheta)>M_PI)theta = theta +(twist->angular.z/180*M_PI-pretheta-2*M_PI);
	else theta = theta +(twist->angular.z/180*M_PI-pretheta);
	pretheta = theta;
   }






int main(int argc, char **argv){
    ros::init(argc, argv, "navigation");
    ros::NodeHandle n;

    ros::Subscriber spe_sub = n.subscribe<geometry_msgs::Twist>("/spe", 1, spe_Callback);
    comand_pub = n.advertise<geometry_msgs::Twist>("/sub",1000);
    ros::Rate r(30.0);


    
    struct target_point first_point,second_point,third_point,forth_point;
    n.getParam("navigation/first_point_x", first_point.x);
    n.getParam("navigation/first_point_y", first_point.y);
    n.getParam("navigation/second_point_x", second_point.x);
    n.getParam("navigation/second_point_y", second_point.y);
    n.getParam("navigation/third_point_x", third_point.x);
    n.getParam("navigation/third_point_y", third_point.y);
    n.getParam("navigation/forth_point_x", forth_point.x);
    n.getParam("navigation/forth_point_y", forth_point.y);

    n.getParam("navigation/k", k);
    n.getParam("navigation/margin", margin);

    first_point.x = first_point.x ;//-0.6;
    first_point.y = first_point.y-0.4;// -0.6;
    second_point.x = second_point.x-0.4;//-0.6;
    second_point.y = second_point.y;//-0.6;

    third_point.x = third_point.x;//-0.6;
    third_point.y = third_point.y+0.4;//-0.6;

    forth_point.x = forth_point.x+0.4;//-0.6;
    forth_point.y = forth_point.y;//-0.6;

    while(n.ok()){
	   //ros::spinOnce();
 

	if(status ==1){
		b = atan2((first_point.y-y),(first_point.x-x));
				   ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand.angular.y = -k*theta*180/M_PI;


		comand_pub.publish(comand);
		if((fabs(first_point.y-y)<margin)&&(fabs(first_point.x-x)<margin)){
			prestatus = status;
			status = -1;
			comand.linear.z = 1;
			comand_pub.publish(comand);

			ros::Time start = ros::Time::now();
			ros::Time now = ros::Time::now();
			while(!((now - start) > ros::Duration(3.0))){
			now = ros::Time::now();
		}

		}
	}

	if(status ==1.5){
		status =2;
ROS_ERROR("log:%f", fabs(first_point.y-y));


		b = atan2((second_point.y-y),(second_point.x-x));
		   ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta)/100;
		comand.linear.y = sin(b-theta)/100;
		comand_pub.publish(comand);

		ros::Time start = ros::Time::now();
		ros::Time now = ros::Time::now();

		while(!((now - start) > ros::Duration(3.0))){

			now = ros::Time::now();
		}

	}
		
	
	
	if(status ==2){
		b = atan2((second_point.y-y),(second_point.x-x));
		   ROS_ERROR("log:%f", status);

		
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand.angular.y = k*(-90-theta*180/M_PI);
		comand_pub.publish(comand);
		
		if((fabs(second_point.y-y)<margin)&&(fabs(second_point.x-x)<margin)){
			prestatus = status;
			status = -1;
			comand.linear.z = 1;
			comand_pub.publish(comand);

			ros::Time start = ros::Time::now();
			ros::Time now = ros::Time::now();
			while(!((now - start) > ros::Duration(3.0))){
			now = ros::Time::now();
		}
		}

	}

	if(status == 2.5){
		status =3;
		b = atan2((third_point.y-y),(third_point.x-x));
		    ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta)/100;
		comand.linear.y = sin(b-theta)/100;
		comand_pub.publish(comand);


		ros::Time start = ros::Time::now();
		ros::Time now = ros::Time::now();

		while(!((now - start) > ros::Duration(3.0))){
			now = ros::Time::now();
		}

	}	
	

	if(status ==3){
		b = atan2((third_point.y-y),(third_point.x-x));
		 ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand.angular.y = k*(-180-theta*180/M_PI);
		comand_pub.publish(comand);
		
		if((fabs(third_point.y-y)<margin)&&(fabs(third_point.x-x)<margin)){
			prestatus = status;
			status = -1;
			comand.linear.z = 1;
			comand_pub.publish(comand);

			ros::Time start = ros::Time::now();
			ros::Time now = ros::Time::now();
			while(!((now - start) > ros::Duration(3.0))){
			now = ros::Time::now();
		}
		}
	}

	if(status == 3.5){
		status =4;
		b = atan2((forth_point.y-y),(forth_point.x-x));
	  ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta)/100;
		comand.linear.y = sin(b-theta)/100;
		comand_pub.publish(comand);



		ros::Time start = ros::Time::now();
		ros::Time now = ros::Time::now();

		while(!((now - start) > ros::Duration(3.0))){

			now = ros::Time::now();
		}

	}	


	if(status ==4){
		b = atan2((forth_point.y-y),(forth_point.x-x));
		 ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta);
		comand.linear.y = sin(b-theta);
		comand.angular.y = k*(-270-theta*180/M_PI);
		comand_pub.publish(comand);
		
		if((fabs(forth_point.y-y)<margin)&&(fabs(forth_point.x-x)<margin)){
			prestatus = status;
			status = -1;
			comand.linear.z = 1;
			comand_pub.publish(comand);

			ros::Time start = ros::Time::now();
			ros::Time now = ros::Time::now();
			while(!((now - start) > ros::Duration(3.0))){
			now = ros::Time::now();
		}

		}
		
	}
	
	if(status == 4.5){

		count++;
		status = 1;
		theta = theta +2*M_PI;
		pretheta = 0;
		if(count ==3){
			status =0;
		}
		b = atan2((first_point.y-y),(first_point.x-x));
		 ROS_ERROR("log:%f", status);
		comand.linear.x = cos(b-theta)/100;
		comand.linear.y = sin(b-theta)/100;
		comand_pub.publish(comand);



		ros::Time start = ros::Time::now();
		ros::Time now = ros::Time::now();
		while(!((now - start) > ros::Duration(3.0))){
			now = ros::Time::now();
		}


	}	
	


	if(status==-1){

		comand.linear.x = 1;
		comand.linear.y = 0;
		comand.linear.z = 1;
		comand_pub.publish(comand);
 ROS_ERROR("log:%f", status);
		if(theta<-double(prestatus)*M_PI/16*7){

			status = prestatus+0.5;
			comand.linear.x = 0;
			comand.linear.z = 0;
			comand_pub.publish(comand);




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


