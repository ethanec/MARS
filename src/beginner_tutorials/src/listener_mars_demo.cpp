#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

int arr = 0;

geometry_msgs::Twist twist;
void speed(float lx,float ly,float lz,float ax,float ay,float az);
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback_hr(const std_msgs::String::ConstPtr& msg)
{   if(arr == 1){
        ROS_INFO("I'm in!");
        ros::NodeHandle n;
        ros::Publisher p3dx = n.advertise<geometry_msgs::Twist>("mob_plat/cmd_vel", 1000); 
        geometry_msgs::Twist twist;

        char *c = new char[20];
        strcpy(c,msg->data.c_str());
        
        char dir=c[0];
        int dis=(c[1]-48)*100+((c[2]-48)*10)+(c[3]-48);

        ROS_INFO("direction: %c  distance: %d",dir,dis);

        if(dis >= 80){
            if(dir == 'F'){
                // speed(0.1,0,0,0,0,0);
                twist.linear.x = 0.1;
            }
            else if(dir == 'L'){
                // speed(0.05,0,0,0,0,-0.05);
                twist.linear.x = 0.05;
                twist.angular.z = -0.05;
            }
            else if(dir == 'R'){
                // speed(0.05,0,0,0,0,0.05);
                twist.linear.x = 0.05;
                twist.angular.z = 0.05;
            }
        }
        else{
            twist.linear.x = 0;
            twist.angular.z = 0;
        }
        ROS_INFO("cmd_vel:%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\n ",
            twist.linear.x,
            twist.linear.y,
            twist.linear.z,
            twist.angular.x, 
            twist.angular.y, 
            twist.angular.z);

        p3dx.publish(twist);
    }   
}


void chatterCallback(const std_msgs::String::ConstPtr& msg){

    char *c = new char[20];
    strcpy(c,msg->data.c_str());

    if(c[0] == 'g'){
        ROS_INFO("I heard: [%c] from nav", c[0]);
        arr = 1; 
    }
}  

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Subscriber sub_nav = n.subscribe("nav", 1000, chatterCallback);
  ros::Subscriber sub_hr = n.subscribe("hr_data", 1000, chatterCallback_hr);
  ros::Publisher p3dx = n.advertise<geometry_msgs::Twist>("mob_plat/cmd_vel", 1000);

  ros::spin();

  return 0;
}

void speed(float lx,float ly,float lz,float ax,float ay,float az){
  twist.linear.x=lx;
  twist.linear.y=ly;
  twist.linear.z=lz;
  twist.angular.x = ax; 
  twist.angular.y = ay; 
  twist.angular.z = az;
}