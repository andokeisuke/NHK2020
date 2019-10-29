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
double next_theta;
double v;

int flag = 1;

float trapez_margin;
float alpha;

struct target_point{
	double x;
	double y;
	double theta;
};

geometry_msgs::Twist comand;
ros::Publisher comand_pub;

void spe_Callback(const geometry_msgs::Twist::ConstPtr& twist){
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
	struct target_point top_point;	//forth_pointとthird_pointの中点
	n.getParam("navigation/first_point_x", first_point.x);
	n.getParam("navigation/first_point_y", first_point.y);
	n.getParam("navigation/first_point_theta", first_point.theta);

	n.getParam("navigation/second_point_x", second_point.x);
	n.getParam("navigation/second_point_y", second_point.y);
	n.getParam("navigation/second_point_theta", second_point.theta);

	n.getParam("navigation/third_point_x", third_point.x);
	n.getParam("navigation/third_point_y", third_point.y);
	n.getParam("navigation/third_point_theta", third_point.theta);

	n.getParam("navigation/forth_point_x", forth_point.x);
	n.getParam("navigation/forth_point_y", forth_point.y);
	n.getParam("navigation/third_point_theta", forth_point.theta);

	n.getParam("navigation/top_point_x", top_point.x);
	n.getParam("navigation/top_point_y", top_point.y);
	n.getParam("navigation/top_point_theta", top_point.theta);

	n.getParam("navigation/k", k);
	n.getParam("navigation/margin", margin);
	n.getParam("navigation/trapez_margin", trapez_margin);
	n.getParam("navigation/alpha", alpha);
	n.getParam("navigation/speed", v);

	first_point.x = first_point.x ;//-0.6;
	first_point.y = first_point.y-0.4;// -0.6;
	second_point.x = second_point.x-0.4;//-0.6;
	second_point.y = second_point.y;//-0.6;

	third_point.x = third_point.x;//-0.6;
	third_point.y = third_point.y+0.4;//-0.6;

	forth_point.x = forth_point.x+0.4;//-0.6;
	forth_point.y = forth_point.y;//-0.6;

    //top_point.x = (forth_point.x + third_point.x)/2;
    //top_point.y = (forth_point.y + third_point.y)/2;

	//台形制御用の時間
	ros::Time base, prezent;

	int ftrapez = 0;
	ros::Time start,now;

	while(n.ok()){

		now = ros::Time::now();
//ROS_ERROR("ROS: %u.%u",ros::Duration(3.0).sec,now.sec );
	   	ros::spinOnce();
		ROS_ERROR("status:%f theta:%f",status,theta);

		

		if(status==-1){

			flag = 1;

			comand.linear.x = 0;
			comand.linear.y = 0;
			comand.linear.z = 1;
			comand_pub.publish(comand);

			
			//ROS_ERROR("log:%f", theta);
			if(theta<(next_theta)/180*M_PI){

				status = prestatus+0.5;
				comand.linear.x = 0;
				comand.linear.z = 0;
				comand_pub.publish(comand);

			}
		}




		

		if(status ==1){
			b = atan2((first_point.y-y),(first_point.x-x));
			//ROS_ERROR("log:%f", status);
			comand.linear.x = cos(b-theta);
			comand.linear.y = sin(b-theta);
			comand.angular.y = k*(first_point.theta-theta*180/M_PI);

			//台形制御
			if((fabs(first_point.y-y)<trapez_margin)&&(fabs(first_point.x-x)<trapez_margin)){
				if(ftrapez == 0){
					ftrapez = 1;
					base = ros::Time::now();
				}
				prezent = ros::Time::now();
				comand.linear.x = comand.linear.x/alpha;//std::pow(prezent.sec-base.sec, 2)*alpha;
				comand.linear.y = comand.linear.y/alpha;//std::pow(prezent.sec-base.sec, 2)*alpha;
			}

	

			if((fabs(first_point.y-y)<margin)&&(fabs(first_point.x-x)<margin)){
				prestatus = status;
				next_theta = second_point.theta;

				//comand_pub.publish(comand);

				if(flag == 1){
				        start = ros::Time::now();
					comand.linear.x = 0;
					comand.linear.y = 0;
					comand.angular.x = 2;
					comand.linear.z = 1;
					comand_pub.publish(comand);

					flag = 0;				
				}


			}

			now = ros::Time::now();


			if((now.sec - start.sec) > ros::Duration(0.5).sec&& flag ==0){
				status = -1;
				comand.angular.x = 0;
			}

			comand_pub.publish(comand);
		}









		if(status ==1.5){
			ftrapez = 0;	//台形制御フラグのリセット
			
			//ROS_ERROR("log:%f", fabs(first_point.y-y));

			b = atan2((second_point.y-y),(second_point.x-x));
			//ROS_ERROR("log:%f", status);
			comand.linear.x = cos(b-theta)/1000;
			comand.linear.y = sin(b-theta)/1000;
			comand.angular.x = 2;
			comand_pub.publish(comand);



			if(flag == 1){
				start = ros::Time::now();
				flag = 0;				
			}
				
			now = ros::Time::now();
			if((now.sec - start.sec) > ros::Duration(0.5).sec){
				flag = 1;
				status = 2;
				comand.angular.x = 0;
			}
		}
	








		if(status ==2){
			b = atan2((second_point.y-y),(second_point.x-x));
			//ROS_ERROR("log:%f", status);
		
			comand.linear.x = cos(b-theta);
			comand.linear.y = sin(b-theta);
			comand.angular.y = k*(second_point.theta-theta*180/M_PI);
			//台形制御
			if((fabs(second_point.y-y)<trapez_margin)&&(fabs(second_point.x-x)<trapez_margin)){
				if(ftrapez == 0){
					ftrapez = 1;
					base = ros::Time::now();
				}
				prezent = ros::Time::now();
				comand.linear.x = comand.linear.x/alpha;//std::pow(prezent.sec-base.sec, 2)*alpha;
				comand.linear.y = comand.linear.y/alpha;//std::pow(prezent.sec-base.sec, 2)*alpha;
			}

			
		
			if((fabs(second_point.y-y)<margin)&&(fabs(second_point.x-x)<margin)){
				prestatus = status;
				next_theta = top_point.theta;


				if(flag == 1){
					start = ros::Time::now();
					flag = 0;
					comand.linear.x = 0;
					comand.linear.y = 0;
					comand.angular.x = 2;
					comand.linear.z = 1;
					comand_pub.publish(comand);				
				}
				
			
			}
			now = ros::Time::now();

			if((now.sec - start.sec) > ros::Duration(0.5).sec && flag ==0){

				status = -1;
				comand.angular.x = 0;					
			}

			comand_pub.publish(comand);
		}
		//ここから改変（三角形のルートに）
		//third_pointとforth_pointの中点、top_pointを取る







		if(status == 2.5){
			ftrapez = 0;	//台形制御フラグのリセット
			b = atan2((top_point.y-y),(top_point.x-x));
			//ROS_ERROR("log:%f", status);
			comand.linear.x = cos(b-theta)/1000;
			comand.linear.y = sin(b-theta)/1000;
			comand.angular.x = 2;
			comand_pub.publish(comand);



			if(flag == 1){
				start = ros::Time::now();
				flag = 0;				
			}
				
			now = ros::Time::now();
			if((now.sec - start.sec) > ros::Duration(0.5).sec){
				flag = 1;
				comand.angular.x = 0;
				status = 3;
			}
		}	









		if(status ==3){

			b = atan2((top_point.y-y),(top_point.x-x));
			//ROS_ERROR("log:%f", status);
			comand.linear.x = cos(b-theta);
			comand.linear.y = sin(b-theta);
			comand.angular.y = k*(top_point.theta-theta*180/M_PI);


			//台形制御
			if((fabs(top_point.y-y)<trapez_margin)&&(fabs(top_point.x-x)<trapez_margin)){
				if(ftrapez == 0){
					ftrapez = 1;
					base = ros::Time::now();
				}
				prezent = ros::Time::now();
				comand.linear.x = comand.linear.x/alpha;//std::pow(prezent.sec-base.sec, 2)*alpha;
				comand.linear.y = comand.linear.y/alpha;//std::pow(prezent.sec-base.sec, 2)*alpha;
			}

		
			if((fabs(top_point.y-y)<margin)&&(fabs(top_point.x-x)<margin)){
				prestatus = status;
				next_theta = first_point.theta-360;


				if(flag == 1){
					start = ros::Time::now();
					flag = 0;
					comand.linear.x = 0;
					comand.linear.y = 0;
					comand.linear.z = 1;
					comand.angular.x = 2;
					comand_pub.publish(comand);				
				}


			}
			now = ros::Time::now();


			if((now.sec - start.sec) > ros::Duration(0.5).sec&& flag ==0){
				status = -1;
				comand.angular.x = 0;
			}
			comand_pub.publish(comand);
		}
	







		if(status == 3.5){
			ftrapez = 0;	//台形制御フラグのリセット

			b = atan2((first_point.y-y),(first_point.x-x));
			//ROS_ERROR("log:%f", status);
			comand.linear.x = cos(b-theta)/1000;
			comand.linear.y = sin(b-theta)/1000;
			comand.angular.x = 2;
			comand_pub.publish(comand);


			if(flag == 1){
				start = ros::Time::now();
				flag = 0;				
			}
				
			now = ros::Time::now();
			if((now.sec - start.sec) > ros::Duration(0.5).sec){
				flag = 1;
				status = 1;
				count++;
				theta = theta +2*M_PI;
				pretheta = 0;
				comand.angular.x = 0;

			}

			if(count ==3){
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
