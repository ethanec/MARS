#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include <sstream>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int goals = 2; //how many goals at a time
int arr = 0;

void pub(int step){
    ros::NodeHandle n;
    ros::Publisher map_pub = n.advertise<std_msgs::String>("mars_arm", 1000);
    while (map_pub.getNumSubscribers() < 1) { }
    //gripper setup 
    ros::Rate loop_rate(10);
    std_msgs::String map2arm;
    std::stringstream ss;
    if(step == 0){
      ss << 'a' ;
    }else if(step == 1){
      ss << 'b' ;
    }
    map2arm.data = ss.str();
    map_pub.publish(map2arm);
    ros::spinOnce();
    loop_rate.sleep();
    sleep(5);
}

void nav(int step){
    MoveBaseClient ac("move_base", true);
    ros::NodeHandle n;
    //wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    //we'll send a goal to the robot to move
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    //entrada do ct-9 12.432 1.699
    //Position(2.606, -0.896, 0.000), Orientation(0.000, 0.000, -0.109, 0.994) = Angle: -0.218
    //Position(4.675, 0.790, 0.000), Orientation(0.000, 0.000, 0.255, 0.967) = Angle: 0.516

    

    float xp[] = {2.606, 4.675};  //-6.668
    float yp[] = {-0.896, 0.790}; //-0.566
    float zo[] = {-0.109, 0.255}; //0.954
    float wo[] = {0.994, 0.967};  //0.299
    
    while(ros::ok() && step < goals && arr == 0){
      
      goal.target_pose.pose.position.x = xp[step];
      goal.target_pose.pose.position.y = yp[step];
  //   goal.target_pose.pose.orientation.x = 0;
  //   goal.target_pose.pose.orientation.y = 0;
      goal.target_pose.pose.orientation.z = zo[step];
      goal.target_pose.pose.orientation.w = wo[step];
      

      ROS_INFO("Sending goal %d" , step+1);
      ac.sendGoal(goal);
      ac.waitForResult();

      if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
          ROS_INFO("Success in target %d" , step+1);
            ros::Publisher map_pub = n.advertise<std_msgs::String>("mars_arm", 1000);
            while (map_pub.getNumSubscribers() < 1) { }
            //gripper setup 
            ros::Rate loop_rate(10);
            std_msgs::String map2arm;
            std::stringstream ss;
            if(step == 0){
              ss << 'a' ;
            }else if(step == 1){
              ss << 'b' ;
            }
            map2arm.data = ss.str();
            map_pub.publish(map2arm);
            ros::spinOnce();
            loop_rate.sleep();
            sleep(5);
            arr = 1;
      }else{
          ROS_INFO("You Fail");
          ros::Duration(2).sleep();
      }
    ROS_INFO("Navigation Success!");
    }
   
}

void chatterCallback(const std_msgs::String::ConstPtr& msg){
  //ROS_INFO("I heard: [%s] from nav", msg->data.c_str());
  char *c = new char[20];
  strcpy(c,msg->data.c_str());

  if(c[0] == 'g'){
    ROS_INFO("I heard: [%c] from nav", c[0]);
    //tell the action client that we want to spin a thread by default
    arr = 0;
    // nav(0);
    pub(0);
  }else if(c[0] == 'h'){
    ROS_INFO("I heard: [%c] from nav", c[0]);
    arr = 0;
    // nav(1);
    pub(1);
  }
}



int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle n;
  ros::Subscriber nav = n.subscribe("nav", 1000, chatterCallback);
  ros::spin();
  return 0;
}
