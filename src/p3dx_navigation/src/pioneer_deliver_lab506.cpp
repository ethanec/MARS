#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include <sstream>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int goals = 4; //how many goals at a time
int arr = 0;
int len = 0;


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
    
    //target:position(x,y,z), orientation(roll, pitch, yaw, w)
    //g1:Position(-0.104, 1.623, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //g2:Position(-0.204, 3.274, 0.000), Orientation(0.000, 0.000, -0.006, 1.000) = Angle: -0.012
    //g3:Position(-0.159, 5.008, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //home:Position(-0.512, -0.320, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //home_p2:Position(-0.734, 0.141, 0.000), Orientation(0.000, 0.000, 1.000, -0.003) = Angle: -3.135




    float xp[] = {-0.104, -0.164, -0.159, -0.734};  
    float yp[] = {1.623, 3.274, 5.008, -0.141};
    float zo[] = {0, -0.006, 0, 1};
    float wo[] = {1, 1, 1, 0};
    
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
            ros::Publisher nav_pub = n.advertise<std_msgs::String>("nav", 1000);
            while (nav_pub.getNumSubscribers() < 1) { }
            //publish a string
            ros::Rate loop_rate(10);
            std_msgs::String map2arm;
            std::stringstream ss;
            if(step != 3){
              ss << 'j' ; 
              ROS_INFO("Add j into string");
            }
            else{
              ss << 'e' ;
              ROS_INFO("Add e into string");
            }
            map2arm.data = ss.str();
            ROS_INFO("%s", map2arm.data.c_str());
            nav_pub.publish(map2arm);
            ros::spinOnce();
            loop_rate.sleep();
            arr = 1;
      }else{
          ROS_INFO("You Fail");
          ros::Duration(2).sleep();
      }
    ROS_INFO("Navigation Success!");
    }
}

void patrol(){ //patrol mode
    MoveBaseClient ac("move_base", true);
    ros::NodeHandle n;
    while(!ac.waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the move_base action server to come up");
    }
    move_base_msgs::MoveBaseGoal goal;
    //we'll send a goal to the robot to move
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();

    //patrol points
    //g1:Position(-1.321, 1.829, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //g2:Position(-1.355, 3.583, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //g2_turn:Position(-1.348, 3.549, 0.000), Orientation(0.000, 0.000, 0.703, 0.712) = Angle: 1.558
    //g3:Position(-1.283, 5.376, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //g3_turn:Position(-1.308, 5.352, 0.000), Orientation(0.000, 0.000, -0.712, 0.702) = Angle: -1.584
    //home_first:Position(-1.081, -0.325, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000
    //home:Position(-0.512, -0.320, 0.000), Orientation(0.000, 0.000, 0.000, 1.000) = Angle: 0.000

    float xp[] = {-1.321, -1.321, -1.355, -1.355, -1.283, -1.283, -1.081, -0.512};  
    float yp[] = {1.829, 1.829, 3.583, 3.583, 5.376, 5.376, -0.32, -0.32};
    float zo[] = {0 , 0.703, 0, 0.703, 0, -0.712, 0, 1};
    float wo[] = {1, 0.712, 1, 0.712, 1, 0.702, 1, 0};
    
    while(ros::ok() && arr == 0){
      
      goal.target_pose.pose.position.x = xp[len];
      goal.target_pose.pose.position.y = yp[len];
      goal.target_pose.pose.orientation.z = zo[len];
      goal.target_pose.pose.orientation.w = wo[len];
      

      ROS_INFO("Sending goal %d" , len+1);
      ac.sendGoal(goal);
      ac.waitForResult();

      if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
            ROS_INFO("Success in patrol target %d" , len+1);
            len++;
            if(len == 8){
              ros::Publisher nav_pub = n.advertise<std_msgs::String>("nav", 1000);
              while (nav_pub.getNumSubscribers() < 1) { }
              ros::Rate loop_rate(10);
              std_msgs::String map2arm;
              std::stringstream ss;
              ss << 'e' ; //arrive signal
              ROS_INFO("Add e into string");
              map2arm.data = ss.str();
              ROS_INFO("%s", map2arm.data.c_str());
              nav_pub.publish(map2arm);
              ros::spinOnce();
              loop_rate.sleep();
              arr = 1;
            }
      }else{
          ROS_INFO("You Fail");
          ros::Duration(2).sleep();
      }
    ROS_INFO("Patrol Success!");
    }
}

void chatterCallback(const std_msgs::String::ConstPtr& msg){
  char *c = new char[20];
  strcpy(c,msg->data.c_str());
  ROS_INFO("I heard: [%c] from nav", c[0]);
  if(c[0] == 'g'){ //pioneer where to go
    arr = 0;
    if(c[1] == '1'){
      nav(0);
    }
    else if(c[1] == '2'){
      nav(1);
    }
    else if(c[1] == '3'){
      nav(2);
    }
  }else if(c[0] == 'h'){
    arr = 0;
    nav(3);
  }else if(c[0] == 'p'){
    arr = 0;
    len = 0;
    patrol();
  }
}



int main(int argc, char** argv){
  ros::init(argc, argv, "simple_navigation_goals");
  ros::NodeHandle n;
  ros::Subscriber nav = n.subscribe("nav", 1000, chatterCallback);
  ros::Publisher nav_pub = n.advertise<std_msgs::String>("nav", 1000);
  ros::spin();
  return 0;
}
