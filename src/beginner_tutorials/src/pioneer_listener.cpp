#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

int arr = 0;
int E_times = 0;

geometry_msgs::Twist twist;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback_hr(const std_msgs::String::ConstPtr& msg){   
    if(E_times == 0){
        ROS_INFO("I'm in!");
        ros::NodeHandle n;
        ros::Publisher p3dx = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000); 
        geometry_msgs::Twist twist;

        char *c = new char[20];
        strcpy(c,msg->data.c_str());
        
        char dir=c[0];
        int dis=(c[1]-48)*100+((c[2]-48)*10)+(c[3]-48);

        ROS_INFO("direction: %c  distance: %d",dir,dis);

        if(dir == 'E'){
            twist.linear.x = 0;
            twist.angular.z = 0;
            
            ros::Publisher nav_pub = n.advertise<std_msgs::String>("nav", 1000);
            while (nav_pub.getNumSubscribers() < 1) { }

            ros::Rate loop_rate(10);
            std_msgs::String arm;
            std::stringstream ss;
            ss << 'x' ; //xyzrobot activate
            ROS_INFO("Add x into string");
            arm.data = ss.str();
            ROS_INFO("%s", arm.data.c_str());
            nav_pub.publish(arm);
            ros::spinOnce();
            loop_rate.sleep();
    
            sleep(10);

            //go home
            std::stringstream ss1;
            ss1 << 'h' ;
            arm.data = ss1.str();
            ROS_INFO("%s", arm.data.c_str());
            nav_pub.publish(arm);
            ros::spinOnce();
            loop_rate.sleep();
            E_times ++;

        }
        else if(dir == 'F'){ //pioneer correction for finding patient's face
            twist.linear.x = 0;
            twist.angular.z = 0;
        }
        else if(dir == 'L'){
            twist.linear.x = 0;
            twist.angular.z = -0.05;
        }
        else if(dir == 'R'){
            twist.linear.x = 0;
            twist.angular.z = 0.05;
        }
        p3dx.publish(twist);
    
    }   
}


void chatterCallback(const std_msgs::String::ConstPtr& msg){

    char *c = new char[20];
    strcpy(c,msg->data.c_str());

    if(c[0] == 'j'){
        ROS_INFO("I heard: [%c] from nav", c[0]);
        E_times = 0; 
    }
}  

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Subscriber sub_nav = n.subscribe("nav", 1000, chatterCallback);
  ros::Subscriber sub_hr = n.subscribe("hr_data", 1000, chatterCallback_hr);
  ros::Publisher p3dx = n.advertise<geometry_msgs::Twist>("Rosaria/cmd_vel", 1000);
  ros::Publisher nav_pub = n.advertise<std_msgs::String>("nav", 1000);

  ros::spin();

  return 0;
}

