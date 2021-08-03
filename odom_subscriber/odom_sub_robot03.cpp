#include <nav_msgs/Odometry.h> // Needed for accessing Odometry data
#include <ros/ros.h>           // Needed for creating the node, etc
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
// This functions get called when a new odometry message gets to the subscriber
// It automatically gets the odometry message as a parameter
// It prints out various parts of the message
void counterCallback(const nav_msgs::Odometry::ConstPtr &msg) {
  // ROS_INFO("%s", msg->header.frame_id.c_str());
  // ROS_INFO("%f", msg->twist.twist.linear.x);
  //ROS_INFO("%f", msg->pose.pose.position.x);
  ofstream writefile;
  writefile.open("/home/SharedFile/rfid03.csv");
  writefile<<"x"<<","<<"y"<<"\n";
  writefile<<msg->pose.pose.position.x<<","<<msg->pose.pose.position.y;
  writefile.close();
  cout<<"Collecting Robot03 Data ...."<<endl;
  //cout<<msg->pose.pose.position.x<<endl;
  //cout<<msg->pose.pose.position.y<<endl;
}

int main(int argc, char **argv) {
  // Create a node to run the code
  ros::init(argc, argv, "odom_sub_node03");
  ros::NodeHandle nh;

  // create a subscriber to the "/odom" topic so we can get the odometry message
  ros::Subscriber sub = nh.subscribe("/tb3_2/odom", 1000, counterCallback);
  
  
  // Run program until manually stopped
  ros::spin();

  return 0;
}
