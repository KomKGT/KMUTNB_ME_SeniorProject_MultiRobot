#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <tf/transform_datatypes.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/*Function Prototype declaration*/
double dconvertstringTodoubleOfx(string sx);
double dconvertstringTodoubleOfy(string sy);
void vreadCSVfile(void);
double dtransform(double ddegree);
void vmoveToposition(double dx,double dy,double dtheta);
/*End of Function Prototype declaration*/

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction>MoveBaseClient;

/*Global Variable*/
string str_x[2];
string str_y[2];

double dx[2];
double dy[2];

double x;
double y;
double dtheta = 0;

int icount = 0;
/*End Of Global Variable*/

double dconvertstringTodoubleOfx(string sx)
{
    if(icount==1)
	{
		stringstream convertx(str_x[icount]);
		convertx >> dx[icount];
        return dx[icount];
	}
    
}
double dconvertstringTodoubleOfy(string sy)
{
    if(icount==1)
	{
		stringstream converty(str_y[icount]);
		converty >> dy[icount];
        return dy[icount];
	}
}

void vreadCSVfile(void)
{
    ifstream MyReadFile1("/home/SharedFile/sendgoal03.csv");
    if(!MyReadFile1.is_open())
			cout<<"FILE SENDGOAl ROBOT3 CAN'T OPEN PLEASE CHECK FILE LOCATION"<<endl;
    
    string line;
	
	
	while(getline(MyReadFile1,line))
	{
		stringstream ss(line);
		
		getline(ss,str_x[icount],',');
		getline(ss,str_y[icount],'\n');

        dx[1]=dconvertstringTodoubleOfx(str_x[icount]);
        dy[1]=dconvertstringTodoubleOfy(str_y[icount]);
		icount++;
		cout<<"Now icount = "<<icount<<endl;
		if(icount==2)
			icount = 0;
    }
}

double dtransform(double ddegree)
{
    double result = ddegree*(M_PI/180);
    return result;
}

void vmoveToposition(double dx,double dy,double dtheta)
{
    MoveBaseClient ac("tb3_2/move_base",true);
	
 		ROS_INFO("Waiting for the move_base action server");
		ac.waitForServer(ros::Duration(60));
		ROS_INFO("Connected to move base server");

 		move_base_msgs::MoveBaseGoal goal;
		goal.target_pose.header.frame_id = "map";
		goal.target_pose.header.stamp = ros::Time::now();

		goal.target_pose.pose.position.x = dx;
		goal.target_pose.pose.position.y = dy;

		double radians = dtransform(dtheta);
		tf::Quaternion quaternion;
		quaternion = tf::createQuaternionFromYaw(radians);

		geometry_msgs::Quaternion qMsg;
		tf::quaternionTFToMsg(quaternion, qMsg);

		goal.target_pose.pose.orientation = qMsg;

		ROS_INFO("Sending robot to: x = %f, y = %f, theta = %f",dx,dy,dtheta);
		ac.sendGoal(goal);

		ac.waitForResult();

		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
		{
			ofstream writefile;
			writefile.open("/home/SharedFile/rfid03.csv");
			writefile<<"id"<<"\n";
			writefile<<"789";
			writefile.close();
			ROS_INFO("You have reached the goal!");
		}
		else
	  		ROS_INFO("The base failed for some reason");
}

int main(int argc,char** argv)
{	
	ros::init(argc,argv,"Robot03_From_CSV");
	ros::NodeHandle nh;
	while(nh.ok())
       {
 		vreadCSVfile();
        x = dx[1];
		y = dy[1];	
        vmoveToposition(x,y,dtheta);
       }
	return 0;
}
