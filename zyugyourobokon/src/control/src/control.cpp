#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Bool.h>

#include <geometry_msgs/Twist.h>




#define MAX_VEL 			1.0//m/s //launchファイルでなにも指定しなかったときの値
#define MIN_VEL 			-1.0//m/s
#define MAX_ANGULAR_VEL 	1.0//m/s
#define MIN_ANGULAR_VEL 	-1.0//m/s

ros::Publisher twist_pub;

ros::Subscriber joy_sub;


	std_msgs::Int16 deg;



float map(float x, float in_min, float in_max, float out_min, float out_max);

class Joystick
{
public:
	float linear_x;
	float linear_y;
	float spin;
	float right_spin;
	float left_spin;
	float initial;
	int axes_x;
	int axes_y;
	float right_turn;
	float left_turn;
	int right_90;
	int left_90;

};

Joystick Joystick;

void joy_Callback(const sensor_msgs::Joy& joy){

  Joystick.linear_x = -joy.axes[0];//左のスティック上下
  Joystick.linear_y = joy.axes[1];//左のスティック左右


  Joystick.right_90 = joy.buttons[3];//4ボタン(コントローラの5番)
  Joystick.left_90  = joy.buttons[0];//1ボタン(コントローラの6番)

  Joystick.right_spin = joy.buttons[4];//L1ボタン(コントローラの5番)
  Joystick.left_spin  = joy.buttons[5];//R1ボタン(コントローラの6番)
  Joystick.right_turn = joy.buttons[6];//L2ボタン(コントローラの5番)
  Joystick.left_turn  = joy.buttons[7];//R2ボタン(コントローラの6番)

  Joystick.initial = joy.buttons[8];//Lスティック押し込み

  Joystick.axes_x = -joy.axes[4];//上のスティック上下
  Joystick.axes_y = joy.axes[5];//上の左のスティック左右

  Joystick.spin = joy.axes[2];//右スティックの左右



  geometry_msgs::Twist twist;
  
  twist.linear.x =  Joystick.linear_x;
  twist.linear.y =  Joystick.linear_y;
  //twist.linear.x = map(Joystick.linear_x,-1,1,MIN_VEL,MAX_VEL);
  //twist.linear.y = map(Joystick.linear_y,-1,1,MIN_VEL,MAX_VEL);

  if(Joystick.right_spin == 1)
  {
	twist.angular.z = MIN_ANGULAR_VEL;
  }    
  else if(Joystick.left_spin == 1)
  {
	twist.angular.z = MAX_ANGULAR_VEL;
  }


  if(Joystick.right_turn == 1)
  {
	twist.linear.z = 1;
  }    
  else if(Joystick.left_turn == 1)
  {
	twist.linear.z = -1;
  }

  if(Joystick.initial)twist.angular.x=1;
  else twist.angular.x=0;

    if(Joystick.right_90 == 1)
  {
	twist.angular.x = 1;
  }    
  else if(Joystick.left_90 == 1)
  {
	twist.angular.x = -1;
  }

  if(Joystick.axes_x != 0){
		twist.linear.x = Joystick.axes_x;
		twist.linear.y = 0;


  }

  if(Joystick.axes_y != 0){
		twist.linear.y = Joystick.axes_y;
		twist.linear.x = 0;

 
  }


  twist.angular.y = Joystick.spin;

	

  twist_pub.publish(twist);

}


float map(float x, float in_min, float in_max, float out_min, float out_max)
{//arduinoのmap関数と同じ
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "joy");

	ros::NodeHandle n;
	ros::NodeHandle pn("~");

	float MAX_VEL_param=MAX_VEL;
	float MIN_VEL_param=MIN_VEL;
	float MAX_ANGULAR_VEL_param=MAX_ANGULAR_VEL;
	float MIN_ANGULAR_VEL_param=MIN_ANGULAR_VEL;

	pn.getParam("MAX_VEL",MAX_VEL_param);
	pn.getParam("MIN_VEL",MIN_VEL_param);
	pn.getParam("MAX_ANGULAR_VEL",MAX_ANGULAR_VEL_param);
	pn.getParam("MIN_ANGULAR_VEL",MIN_ANGULAR_VEL_param);

	joy_sub = n.subscribe("joy", 1, joy_Callback);
	
	twist_pub = n.advertise<geometry_msgs::Twist>("sub",1);
	


	ros::Rate r(10.0);

	while(n.ok()){

		ros::spinOnce();

		r.sleep();



	}

}
