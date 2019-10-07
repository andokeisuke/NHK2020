#include <ros/ros.h>  // rosで必要なヘッダーファイル
#include <geometry_msgs/Twist.h> // ロボットを動かすために必要

/*
フラグ変数(status, flag)の説明

フラグの絶対値は次の目標地点に対応
フラグ変数が０より大きいときは直進
０より小さい場合はターン
*/

//自機の座標
double x = 0;
double y  = 0;
//w座標軸における自機の角度（x軸との偏角）
double theta = 0;
//w座標軸における目的地の角度（x軸との偏角）
double b = 0;

//曲がり角の座標
struct target_point destination[5];	//一番最初の要素は空き
destination[1].x = 0.0;
destination[1].y = 2.5;
destination[2].x = 0.6;
destination[2].y = 2.5;
destination[3].x = 0.6;
destination[3].y = 0.0;
destination[4].x = 0.0;
destination[4].y = 0.0;

//許容できる目標との誤差
double margin = 0.01;	//距離
double margin_a = 5.0;	//角度

struct target_point{
	double x;
	double y;
};


//自機の位置、角度の更新
void spe_Callback(const geometry_msgs::Twist::ConstPtr& twist){
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

    geometry_msgs::Twist comand;	//動作指示用変数
    int status = 1;	//動作指定用のフラグ

    while(n.ok()){	//Main Loop
 
	ROS_ERROR("log:%i", status);

	if(status > 0)	//直進
		comand_pub.publish(automove(&status));
	else if(status < 0)	//ターン
		comand_pub.publish(autoturn(&status));
	else if(fabs(status) > 4){
		comand.linear.x = 0;
		comand.linear.y = 0;
		comand_pub.publish(comand);
		status = 1;
	}

    ros::spinOnce();
    r.sleep();
    }
}

/*
 * 自立走行関数
 * automove,autoturn
 * 引数：フラグ変数のアドレス
 * 戻り値：subトピックにpublishする動作指示
*/
geometry_msgs::Twist automove(int *flag){	//自立走行；直進
	geometry_msgs::Twist order;

	b = atan2((destination[flag].y-y),(destination[flag].x-x));
	
	order.linear.x = cos(b-theta);
	order.linear.y = sin(b-theta);
	order.linear.z = 0;

	if((fabs(destination[flag].y-y)<margin)&&(fabs(destination[flag].x-x)<margin)){
		flag = -flag;
	}
	return order;
}


geometry_msgs::Twist autoturn(int *flag){	//自立走行；ターン
	geometry_msgs::Twist order;

	order.linear.z = 1;	//右回りでターン

	if((fabs(destination[-flag + 1].y - destination[-flag].y) < margin_a) && (fabs(destination[-flag + 1].x - destination[-flag].x) < margin_a)){
		flag = -flag + 1;
	}
	return order;
}
