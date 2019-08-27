#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <math.h>
#include <joycon/pub_val2.h>
int thetachange(float x,float y);

class Joystick{

	public:
		Joystick();
	private:
		void messageCallback(const sensor_msgs::Joy::ConstPtr& joy);
		ros::NodeHandle nh;
		ros::Publisher pub;
		ros::Subscriber sub;

};


Joystick::Joystick(){
	
	pub = nh.advertise<joycon::pub_val2>("topic",1);
	sub = nh.subscribe<sensor_msgs::Joy>("joy",10,&Joystick::messageCallback,this);


}







void Joystick::messageCallback(const sensor_msgs::Joy::ConstPtr& joy){

	ROS_INFO("%f",joy->axes[1]);
	joycon::pub_val2 val;
	//val.theta = atan(joy->axes[1]/joy->axes[0])*180/M_PI;
	val.theta = thetachange(joy->axes[0],joy->axes[1]);
	val.r = sqrt((joy->axes[0])*(joy->axes[0])+(joy->axes[1])*(joy->axes[1]));

	if(val.r>1){
		val.r=1;
		
	}
	
	if(joy->axes[1]<0&&(3<val.theta&&val.theta<177)){val.r = -val.r;}
	//if(!(joy->axes[1]==0&&joy->axes[0]==0)){pub.publish(val);}
	pub.publish(val);


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

