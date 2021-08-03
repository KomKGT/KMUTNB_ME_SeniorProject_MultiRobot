#include <nav_msgs/Odometry.h> // Needed for accessing Odometry data
#include <ros/ros.h>           // Needed for creating the node, etc
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int NumberOfDataTruth = 1;  
int NumberOfDataOdom = 1;
// This functions get called when a new odometry message gets to the subscriber
// It automatically gets the odometry message as a parameter
// It prints out various parts of the message
void counterCallback(const nav_msgs::Odometry::ConstPtr &msg) //Write Truth Path from GAZEBO
{
  // ROS_INFO("%s", msg->header.frame_id.c_str());
  // ROS_INFO("%f", msg->twist.twist.linear.x);
  //ROS_INFO("%f", msg->pose.pose.position.x);
  char buff[100];
  time_t now = time (0);
  strftime (buff, 100, "%Y%m%d %H:%M:%S", localtime (&now));	//YYYYMMDD HH:MM:SS 
  
  
  ofstream writefile("/home/SharedFile/truth03.csv",ios::app);
  //writefile.open("/home/SharedFile/log01.csv");
  //writefile<<"x"<<","<<"y"<<"\n";
  
  writefile<<NumberOfDataTruth<<","<<buff<<","<<msg->pose.pose.position.x<<","<<msg->pose.pose.position.y<<endl;
  NumberOfDataTruth++;
  cout<<"Collecting Truth Robot03 Data ...."<<endl;
  //cout<<msg->pose.pose.position.x<<endl;
  //cout<<msg->pose.pose.position.y<<endl;
}
void counterCallback2(const nav_msgs::Odometry::ConstPtr &msg) //Write Odometry From Robot01
{
  // ROS_INFO("%s", msg->header.frame_id.c_str());
  // ROS_INFO("%f", msg->twist.twist.linear.x);
  //ROS_INFO("%f", msg->pose.pose.position.x);
  char buff[100];
  time_t now = time (0);
  strftime (buff, 100, "%Y%m%d %H:%M:%S", localtime (&now));      //YYYYMMDD HH:MM:SS 
  
  
  ofstream writefile("/home/SharedFile/log03.csv",ios::app);
  //writefile.open("/home/SharedFile/log01.csv");
  //writefile<<"x"<<","<<"y"<<"\n";
  
  writefile<<NumberOfDataOdom<<","<<buff<<","<<msg->pose.pose.position.x<<","<<msg->pose.pose.position.y<<endl;
  NumberOfDataOdom++;
  cout<<"Collecting Odom Robot03 Data ...."<<endl;
  //cout<<msg->pose.pose.position.x<<endl;
  //cout<<msg->pose.pose.position.y<<endl;
}

int main(int argc, char **argv) {
  // Create a node to run the code
  ros::init(argc, argv, "log03&truth03");
  ros::NodeHandle nh;
  

  // create a subscriber to the "/odom" topic so we can get the odometry message
  ros::Subscriber sub = nh.subscribe("/tb3_2/ground_truth/state", 1000, counterCallback);
  ros::Subscriber sub2 = nh.subscribe("/tb3_2/odom", 1000, counterCallback2);
  
  // Run program until manually stopped
  ros::spin();

  return 0;
}
