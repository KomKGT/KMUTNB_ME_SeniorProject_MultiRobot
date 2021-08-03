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
	moveToposition(5.0,1.0,180);/*LOW DEVEL*/

	moveToposition(5.0,4.0,180);/*UP*/
	moveToposition(4.75,4.0,180);/*TOP DEVEL*/	
	moveToposition(4.75,1.0,180);/*DOWN*/	
	moveToposition(4.5,1.0,180);/*LOW DEVEL*/
	 
	moveToposition(4.5,4.0,180);/*UP*/
	moveToposition(4.25,4.0,180);/*TOP DEVEL*/	
	moveToposition(4.25,1.0,180);/*DOWN*/	
	moveToposition(4.0,1.0,180);/*LOW DEVEL*/

	moveToposition(4.0,4.0,180);/*UP*/
	moveToposition(3.75,4.0,180);/*TOP DEVEL*/	
	moveToposition(3.75,1.0,180);/*DOWN*/	
	moveToposition(3.5,1.0,180);/*LOW DEVEL*/

	moveToposition(3.5,4.0,180);/*UP*/
	moveToposition(3.25,4.0,180);/*TOP DEVEL*/	
	moveToposition(3.25,1.0,180);/*DOWN*/
 
	moveToposition(6.0,0.0,90);/*DOWN*/

	
        
	
	
	return 0;
}
