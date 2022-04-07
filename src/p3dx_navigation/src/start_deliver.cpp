#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int goals = 2; //how many goals at a time
int arr = 0;

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

    //go Position(-5.209, -0.639, 0.000), Orientation(0.000, 0.000, 0.718, 0.696) = Angle: 1.601
    //back Position(-5.090, -5.139, 0.000), Orientation(0.000, 0.000, -0.733, 0.681) = Angle: -1.644

    float xp[] = {-5.209, -5.090};  //-6.668
    float yp[] = {-0.639, -5.139}; //-0.566
    float zo[] = {0.718, -0.733}; //0.954
    float wo[] = {0.696, 0.681};  //0.299
    
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

      if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
          ROS_INFO("Success in target %d" , step+1);
          if(step == 0){
            ros::Publisher map_pub0 = n.advertise<std_msgs::Bool>("arm_move", 1000);
            while (map_pub0.getNumSubscribers() < 1) { }
            //gripper setup 
            ros::Rate loop_rate(10);
            std_msgs::Bool map2arm;
            map2arm.data = true;
            map_pub0.publish(map2arm);
            ros::spinOnce();
            loop_rate.sleep();
            arr = 1;
          }else if(step == 1){
            ros::Publisher map_pub1 = n.advertise<std_msgs::Bool>("nav_fin", 1000);
            while (map_pub1.getNumSubscribers() < 1) { }
            //gripper setup 
            ros::Rate loop_rate(10);
            std_msgs::Bool nav_fin;
            nav_fin.data = true;
            map_pub1.publish(nav_fin);
            ros::spinOnce();
            loop_rate.sleep();
            arr = 1;
          }
      else
          ROS_INFO("You Fail");

      ros::Duration(2).sleep();
    }
  ROS_INFO("Navigation Success!");
   
}

void chatterCallback(const std_msgs::String::ConstPtr& msg){
  //ROS_INFO("I heard: [%s] from nav", msg->data.c_str());
  char *c = new char[20];
  strcpy(c,msg->data.c_str());

  if(c[0] == 'g'){
    ROS_INFO("I heard: [%c] from nav", c[0]);
    //tell the action client that we want to spin a thread by default
    arr = 0;
    nav(0);
  }else if(c[0] == 'h'){
    ROS_INFO("I heard: [%c] from nav", c[0]);
    arr = 0;
    nav(1);
  }
}



int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle n;
  ros::Subscriber nav = n.subscribe("nav", 1000, chatterCallback);
  ros::spin();
  return 0;
}
