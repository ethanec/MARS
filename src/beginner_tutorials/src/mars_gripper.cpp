#include "ros/ros.h"
#include "std_msgs/Bool.h"

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");


  ros::NodeHandle n;


  ros::Publisher chatter_pub = n.advertise<std_msgs::Bool>("gripper/cmd_gripper", 1000);
  while (chatter_pub.getNumSubscribers() < 1) {
        // wait for a connection to publisher
        // you can do whatever you like here or simply do nothing
  }
  ros::Rate loop_rate(10);

  std_msgs::Bool msg;
  msg.data = false;
  
  //ROS_INFO("%s", msg.data.c_str())
  chatter_pub.publish(msg);
  ros::spinOnce();
  loop_rate.sleep();

  return 0;
}
