#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{

    ros::init(argc, argv, "talker");


    ros::NodeHandle n;


    ros::Publisher nav_pub = n.advertise<std_msgs::String>("nav", 1000);
    while (nav_pub.getNumSubscribers() < 1) { }
    //gripper setup 
    ros::Rate loop_rate(10);
    std_msgs::String map2arm;
    std::stringstream ss;
    ss << 'j' ; //pioneer calculate
    ROS_INFO("Add j into string");
    map2arm.data = ss.str();
    ROS_INFO("%s", map2arm.data.c_str());
    nav_pub.publish(map2arm);
    ros::spinOnce();
    loop_rate.sleep();

    return 0;
}