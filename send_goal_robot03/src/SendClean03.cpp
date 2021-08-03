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
	MoveBaseClient ac("tb3_2/move_base",true);

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
	ros::init(argc,argv,"send_clean_node03");
	
	double y;
	double x = 7.5;
	ros::NodeHandle nh;
       
/////////////////////////////////////////RB03//////////	
	moveToposition(7.0,4.0,180);/*UP*/
	moveToposition(6.75,4.0,180);/*TOP DEVEL*/	
 	moveToposition(6.75,1.0,180);/*DOWN*/
	moveToposition(6.5,1.0,180);/*LOW DEVEL*/

       moveToposition(6.5,4.0,180);/*UP*/
	moveToposition(6.25,4.0,180);/*TOP DEVEL*/	
	moveToposition(6.25,1.0,180);/*DOWN*/	
	moveToposition(6.0,1.0,180);/*LOW DEVEL*/

	moveToposition(6.0,4.0,180);/*UP*/
	moveToposition(5.75,4.0,180);/*TOP DEVEL*/	
	moveToposition(5.75,1.0,180);/*DOWN*/	
	moveToposition(5.5,1.0,180);/*LOW DEVEL*/

	moveToposition(5.5,4.0,180);/*UP*/
	moveToposition(5.25,4.0,180);/*TOP DEVEL*/	
	moveToposition(5.25,1.0,180);/*DOWN*/

	moveToposition(7.0,0.0,90);/*DOWN*/
	

	
	
        
	
	
	return 0;
}
