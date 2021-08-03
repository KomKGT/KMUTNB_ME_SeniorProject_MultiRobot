#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_datatypes.h>
using namespace std;

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>MoveBaseClient;
double transform(double angle)
{
	double result = angle * (M_PI/180);
	return result;
}
void moveToposition(double a,double b,double theta)
{
	MoveBaseClient ac("tb3_1/move_base",true);

 	ROS_INFO("Waiting for the move_base action server");
	ac.waitForServer(ros::Duration(60));
	ROS_INFO("Connected to move base server");
	move_base_msgs::MoveBaseGoal goal;
	goal.target_pose.pose.position.x = a;
	goal.target_pose.pose.position.y = b;
	goal.target_pose.header.frame_id = "map";
	goal.target_pose.header.stamp = ros::Time::now();
	double radians = transform(theta);
	tf::Quaternion quaternion;
	quaternion = tf::createQuaternionFromYaw(radians);

	geometry_msgs::Quaternion qMsg;
	tf::quaternionTFToMsg(quaternion, qMsg);

	goal.target_pose.pose.orientation = qMsg;
	ROS_INFO("Sending robot to: x = %f, y = %f, theta = %f",a,b,theta);
	ac.sendGoal(goal);

	ac.waitForResult();

	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
	  ROS_INFO("You have reached the goal!");
	else
	  ROS_INFO("The base failed for some reason");
}
int main(int argc,char** argv)
{	
	ros::init(argc,argv,"send_clean_node02");
	
	double y;
	double x = 7.5;
	ros::NodeHandle nh;
       

//////////////////////////////////////////////////RB02//////	
	moveToposition(6,0,90);/*LOW DEVEL*/
	moveToposition(2.5,1,90);
	moveToposition(2.25,4.5,90);
	moveToposition(2.5,4.5,90);
	moveToposition(2.5,3.75,90);
	moveToposition(2.75,3.75,90);
	moveToposition(2.75,4.5,90);/*LOW DEVEL*/
	moveToposition(3,4.5,90);
	moveToposition(3,3.75,90);
	moveToposition(3.25,3.75,90);
	moveToposition(3.25,4.5,90);
	moveToposition(3.5,4.5,90);
	moveToposition(3.5,3.75,90);/*LOW DEVEL*/
	moveToposition(3.75,3.75,90);
	moveToposition(3.75,4.5,90);
	moveToposition(4,4.5,90);
	moveToposition(4,3.75,90);
	moveToposition(4.25,3.75,90);
	moveToposition(4.25,4.5,90);/*LOW DEVEL*/
	moveToposition(4.5,4.5,90);
	moveToposition(4.5,3.75,90);
	moveToposition(4.75,3.75,90);
	moveToposition(4.75,4.5,90);
	moveToposition(5,4.5,90);
	moveToposition(5,3.75,90);/*LOW DEVEL*/
	moveToposition(5.25,3.75,90);
	moveToposition(5.25,4.5,90);
	moveToposition(5.5,4.5,90);
	moveToposition(5.5,0.5,90);
	moveToposition(5.25,0.5,90);
	moveToposition(5.25,1.5,90);/*LOW DEVEL*/
	moveToposition(5,1.5,90);
	moveToposition(5,0.5,90);
	moveToposition(4.75,0.5,90);
	moveToposition(4.75,1.5,90);
	moveToposition(4.5,1.5,90);
	moveToposition(4.5,0.5,90);/*LOW DEVEL*/
	moveToposition(4.25,0.5,90);
	moveToposition(4.25,1.5,90);
	moveToposition(4,1.5,90);
	moveToposition(4,0.5,90);
	moveToposition(3.75,0.5,90);
	moveToposition(3.75,1.5,90);
	moveToposition(3.5,1.5,90);
	moveToposition(3.5,0.5,90);
	moveToposition(3.25,0.5,90);
	moveToposition(3.25,1.5,90);
	moveToposition(3,1.5,90);
	moveToposition(3,0.5,90);
	moveToposition(2.75,0.5,90);
	moveToposition(2.75,1.5,90);
	moveToposition(2.5,1.5,90);
	moveToposition(2.5,0.5,90);
	moveToposition(6,0,90);


	
        
	
	
	return 0;
}
