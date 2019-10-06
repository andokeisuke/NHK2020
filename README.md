# NHK2020


パッケージをビルドするのに必要なもの



navigation_stack
joy_node
urg_node

sudo apt-get install ros-kinetic-gmapping
sudo apt-get install ros-kinetic-openslam-gmapping
sudo apt-get install ros-kinetic-slam-gmapping
sudo apt-get install ros-kinetic-map-server
sudo apt-get install ros-kinetic-amcl
sudo apt-get install ros-kinetic-move-base

sudo apt-get install ros-${ROS_DISTRO}-urg-node
 sudo apt-get install ros-indigo-rosserial-arduino
 sudo apt-get install ros-indigo-rosserial
 
 sudo apt-get install ros-kinetic-joy
sudo apt-get install ros-kinetic-joystick-drivers

catkin_makeの際<wh_msg.h>がないと怒られたら、tf_twistのパッケージをsrcから取り除いてcatkin_makeし、その後tf_twistをいれなおしてcatkin_makeする

sudo usermod -a -G dialout <username>
