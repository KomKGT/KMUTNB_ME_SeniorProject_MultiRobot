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
	MoveBaseClient ac("tb3_0/move_base",true);

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
	ros::init(argc,argv,"send_clean_node01");
	
	double y;
	double x = 7.5;
	ros::NodeHandle nh;
       

/////////////////////////////////////////////////////////////RB01///	
	moveToposition(0.5,1,90);/*LOW DEVEL*/

	moveToposition(0.5,2,90);/*UP*/
	moveToposition(0.5,3,90);/*TOP DEVEL*/	
	moveToposition(0.5,4,90);/*DOWN*/	
	moveToposition(0.5,4.5,90);/*LOW DEVEL*/

	moveToposition(0.75,4.5,90);/*UP*/
	moveToposition(0.75,4,90);/*TOP DEVEL*/	
	moveToposition(0.75,3.75,90);/*DOWN*/	

	moveToposition(1,3.75,90);/*LOW DEVEL*/

	moveToposition(1,4.5,90);/*UP*/
	moveToposition(1.25,4.5,90);/*TOP DEVEL*/	
	moveToposition(1.25,3.75,90);/*DOWN*/	
	moveToposition(1.5,3.75,90);/*LOW DEVEL*/

	moveToposition(1.5,4.5,90);/*UP*/
	moveToposition(1.75,4.5,90);/*TOP DEVEL*/	
	moveToposition(1.75,3.75,90);/*DOWN*/	
	moveToposition(2,3.75,90);/*LOW DEVEL*/

	moveToposition(2,4.5,90);/*UP*/
	moveToposition(2.25,4.5,90);/*TOP DEVEL*/	
	
	moveToposition(2.5,3.75,90);/*station RB1*/

	moveToposition(2.5,0.5,90);
	moveToposition(2.25,0.5,90);
	moveToposition(2.25,1.5,90);
	moveToposition(2,1.5,90);
	moveToposition(2,0.5,90);
	moveToposition(1.75,0.5,90);
	moveToposition(1.75,1.5,90);
	moveToposition(1.5,1.5,90);
	moveToposition(1.5,0.5,90);
	moveToposition(1.25,0.5,90);
	moveToposition(1.25,1.5,90);
	moveToposition(1,1.5,90);

	moveToposition(1,0.5,90);
	moveToposition(0.75,0.5,90);
	moveToposition(0.75,1.5,90);
	moveToposition(0.5,0.5,90);
	moveToposition(5,0,90);
	
	/*for(y=0;y<=4;y=y+0.25)
	{
	  x=6.75;
	  //if(y>4)
	   //{
		//break;
          //}
	  if(x==6.75&&y==4){
 		moveToposition(x,y,180);
		break;
         }
         moveToposition(x,y,90);
	}
	for(y=4;y>=0.5;y=y-0.25)
	{
	  x=6.5;
	  //if(y<0.5)
         //{
		//break;
	  //}
	  if(x==6.5&&y==0.5)
	  {	
 		moveToposition(x,y,180);
		break;
	  }
	  moveToposition(x,y,90);
	}
	for(y=0;y<=4;y=y+0.25)
	{
	  x=6.25;//
	  //if(y>4)
	   //{
		//break;
          //}
	  if(x==6.25&&y==4){//
 		moveToposition(x,y,180);
		break;
         }
         moveToposition(x,y,90);
	}
	for(y=4;y>=0.5;y=y-0.25)
	{
	  x=6.0;//
	  //if(y<0.5)
         //{
		//break;
	  //}
	  if(x==6.0&&y==0.5)//
	  {	
 		moveToposition(x,y,180);
		break;
	  }
	  moveToposition(x,y,90);
	}*/
	

	//moveToposition(x1,y1,theta);

	//moveToposition(x2,y2,theta);

	//moveToposition(x3,y3,theta);
	
	
        
	
	
	return 0;
}
