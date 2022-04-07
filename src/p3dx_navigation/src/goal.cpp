#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int goals = 4;

int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //we'll send a goal to the robot to move
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  //entrada do ct-9 12.432 1.699

  //Position(-1.909, 0.253, 0.000), Orientation(0.000, 0.000, 0.691, 0.723) = Angle: 1.527
  //Position(-2.208, -3.438, 0.000), Orientation(0.000, 0.000, -0.724, 0.690) = Angle: -1.618

  int i = 0;
  float xp[] = {4.357, 3.154, 1.119, 1.313};  //-6.668
  float yp[] = {1.721, 3.590, 2.001,  0.075}; //-0.566
  float zo[] = {0.310, 0.980, -0.809, 0.197}; //0.954
  float wo[] = {0.951, 0.197, 0.588, 0.980};  //0.299
  
  while(ros::ok() && i < goals ){
    
    goal.target_pose.pose.position.x = xp[i];
    goal.target_pose.pose.position.y = yp[i];
//   goal.target_pose.pose.orientation.x = 0;
//   goal.target_pose.pose.orientation.y = 0;
    goal.target_pose.pose.orientation.z = zo[i];
    goal.target_pose.pose.orientation.w = wo[i];
    

    ROS_INFO("Sending goal %d" , i+1);
    ac.sendGoal(goal);

    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Success in target %d" , i+1);
    else
        ROS_INFO("You Fail");

    ros::Duration(2).sleep();

    i++;
    
  }
 ROS_INFO("Navigation Success!");

  return 0;
}
