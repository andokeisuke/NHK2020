#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <math.h>
#include <joycon/pub_val2.h>
#include <std_msgs/Float64.h>
int thetachange(float x,float y);

class Joystick{

	public:
		Joystick();
	private:
		void messageCallback(const sensor_msgs::Joy::ConstPtr& joy);
		ros::NodeHandle nh;
		ros::Publisher base1_pub,base2_pub,base3_pub,base4_pub,wheel1_pub,wheel2_pub,wheel3_pub,wheel4_pub;
		ros::Subscriber sub;

};


Joystick::Joystick(){
	
	base1_pub = nh.advertise<std_msgs::Float64>("/my_robo/base1_controller/command",1);
	base2_pub = nh.advertise<std_msgs::Float64>("/my_robo/base2_controller/command",1);
	base3_pub = nh.advertise<std_msgs::Float64>("/my_robo/base3_controller/command",1);
	base4_pub = nh.advertise<std_msgs::Float64>("/my_robo/base4_controller/command",1);
	wheel1_pub = nh.advertise<std_msgs::Float64>("/my_robo/wheel1_controller/command",1);
	wheel2_pub = nh.advertise<std_msgs::Float64>("/my_robo/wheel2_controller/command",1);
	wheel3_pub = nh.advertise<std_msgs::Float64>("/my_robo/wheel3_controller/command",1);
	wheel4_pub = nh.advertise<std_msgs::Float64>("/my_robo/wheel4_controller/command",1);
	sub = nh.subscribe<sensor_msgs::Joy>("joy",10,&Joystick::messageCallback,this);


}







void Joystick::messageCallback(const sensor_msgs::Joy::ConstPtr& joy){

	ROS_INFO("%f",joy->axes[1]);
	joycon::pub_val2 val;
	std_msgs::Float64 r,theta;
	//val.theta = atan(joy->axes[1]/joy->axes[0])*180/M_PI;
	val.theta = thetachange(joy->axes[0],joy->axes[1]);
	val.r = sqrt((joy->axes[0])*(joy->axes[0])+(joy->axes[1])*(joy->axes[1]));
	theta.data=M_PI-val.theta*M_PI/180;
	if(val.r>1 ){
		val.r=1;
		
	}
	if(joy->axes[1]<0){
		val.r=(-1)*val.r;

	}

	r.data=val.r*20;	
	if(joy->buttons[4]==1||joy->buttons[5]==1){

		theta.data=M_PI/4;
		base3_pub.publish(theta);
		base2_pub.publish(theta);
		
		theta.data=M_PI*3/4;
		base1_pub.publish(theta);
		base4_pub.publish(theta);
		
		
		wheel1_pub.publish(r);
		wheel3_pub.publish(r);
		r.data=(-1)*r.data;
		wheel2_pub.publish(r);
		wheel4_pub.publish(r);

		

	}else{
	
	//if(joy->axes[1]<0&&(3<val.theta&&val.theta<177)){val.r = -val.r;}
	//if(!(joy->axes[1]==0&&joy->axes[0]==0)){pub.publish(val);}
	base1_pub.publish(theta);
	base2_pub.publish(theta);
	base3_pub.publish(theta);
	base4_pub.publish(theta);
	

	wheel1_pub.publish(r);
	wheel2_pub.publish(r);
	wheel3_pub.publish(r);
	wheel4_pub.publish(r);




	}

	

	
}


int main(int argc,char **argv){

	ros::init(argc,argv,"joy_con");
	Joystick joystick;
	/*ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<joycon::pub_val>("topic",1);
	ros::Subscriber sub = nh.subscribe<sensor_msgs::Joy>("joy",10,messageCallback);*/
	ros::spin();
	return 0;


}

int thetachange(float x,float y){
	int theta = atan(y/x)*180/M_PI;
		
	if((x<=0&&y>=0) || (x>0&&y<0)){
		
		theta = theta + 180;
	}

	if((0<=theta&&theta<=3&&x>0)||(177<=theta&&theta<=180&&x>0)){

		theta = 0;
	}

	if( (0<=theta&&theta<=3&&x<0)||(177<=theta&&theta<=180&&x<0)){
		theta = 180;

	}


	return theta;

}

