/*
--
-- oo0oo
-- o8888888o
-- 88" . "88
-- (| -_- |)
-- 0\ = /0
-- ___/`---'\___
-- .' \\| |-- '.
-- / \\||| : |||-- \
-- / _||||| -:- |||||- \
-- | | \\\ - --/ | |
-- | \_| ''\---/'' |_/ |
-- \ .-\__ '-' ___/-. /
-- ___'. .' /--.--\ `. .'___
-- ."" '< `.___\_<|>_/___.' >' "".
-- | | : `- \`.;`\ _ /`;.`/ - ` : | |
-- \ \ `_. \_ __\ /__ _/ .-` / /
-- =====`-.____`.___ \_____/___.-`___.-'=====
-- `=---='
--
--
-- │
-- │ │ │
-- ┌──┴──┴──┴──┐
-- │ 香 爐 │
-- │ │
-- ├┬─────────┬┤
-- └┘ └┘
--
-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
--
-- 佛祖保佑 永無bug
--
--
*/


#include "ros/ros.h"
#include "std_msgs/String.h"

#include "tf2_msgs/TFMessage.h"
#include "geometry_msgs/Twist.h"
#include <sstream>
/*
#include<iostream>
#include <string>
using namespace std;
*/
int t;

geometry_msgs::Twist twist;

void speed(float lx,float ly,float lz,float ax,float ay,float az){
    twist.linear.x=lx;
    twist.linear.y=ly;
    twist.linear.z=lz;
    twist.angular.x = ax;
    twist.angular.y = ay;
    twist.angular.z = az;
}

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ros::NodeHandle n;
    ros::Publisher p3dx = n.advertise<geometry_msgs::Twist>("mob_plat/cmd_vel", 1000);
    geometry_msgs::Twist twist;

    char *c = new char[20];
    strcpy(c,msg->data.c_str());

    char dir=c[0];
    int dis=(c[1]-48)*100+((c[2]-48)*10)+(c[3]-48);

    ROS_INFO("direction: %c distance: %d",dir,dis);

    if(dis >= 100){
        if(dir == 'F'){
        // speed(0.1,0,0,0,0,0);
            
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
    t=50;
}

int main(int argc, char **argv){

    ros::init(argc, argv, "mars_contest");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("hr_data", 1000, chatterCallback);
    ros::Publisher test = n.advertise<geometry_msgs::Twist>("mob_plat/cmd_vel", 1000);

    while(1){

        if(t<49){
            for(t=0;t<15;t++){
            speed(0.1,0,0,0,0,0);
            test.publish(twist);
            ros::spinOnce();
            sleep(1);
            }
        }

        for(t=0;t<16;t++){
            speed(0,0,0,0,0,0.1);
            test.publish(twist);
            ros::spinOnce();
            sleep(1);
        }

        if(t<49){
            for(t=0;t<2;t++){
            speed(0,0,0,0,0,0);
            test.publish(twist);
            ros::spinOnce();
            sleep(1);
            }

        }

    }
return 0;
}
