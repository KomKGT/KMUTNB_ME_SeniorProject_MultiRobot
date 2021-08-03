#include <bits/stdc++.h>
#include<windows.h>

using namespace std;

class robot_data 
{  
	public : 
	 
		string str_point[40];     
		string str_time[40];  
	
		string str_rfid_x;
		string str_rfid_y;
		
		string str_rx[40];
		string str_ry[40];
				
		
};

int main () 
{
	robot_data robot1;
	robot_data robot2;
	robot_data robot3;
	string str_pos[40];
	string str_x[40];
	string str_y[40];
	
	int i,j,k;
	int a,z ;
	fstream read_schedule("schedule.csv"); if(!read_schedule.is_open()) cout << "FILE SCHEDULE ERROR , PLEASE TRY AGAIN" << endl;
  
	string line ;
	
  	while(getline(read_schedule, line))
	{
		stringstream ss(line);
		
   		getline(ss,robot1.str_point[i], ',');
    	getline(ss,robot1.str_time[i], ',');
    
		getline(ss,robot2.str_point[i], ',');
    	getline(ss,robot2.str_time[i], ',');
   	
		getline(ss,robot3.str_point[i], ',');
    	getline(ss,robot3.str_time[i], '\n');
    
    	i++;
  	}
  	read_schedule.close();
  	
  	fstream read_point_xy("point_xy.csv"); if(!read_point_xy.is_open()) cout << "FILE POINT XY ERROR , PLEASE TRY AGAIN" << endl;
  	i=0;
	while(getline(read_point_xy, line))
	{
		stringstream ss(line);
		
   		getline(ss,str_pos[i], ',');
    	getline(ss,str_x[i], ',');
    	getline(ss,str_y[i], '\n');
    
    	i++;
  	}
  	read_point_xy.close();
  	
  	for(i=0;robot1.str_point[i].length()>0;i++)
  	{
  		for(j=0;(str_pos[j].length()>0);j++)
  		{
  			if(!(robot1.str_point[i].compare(str_pos[j])))
			{
				robot1.str_rx[i] = str_x[j];
				robot1.str_ry[i] = str_y[j];
			}
  		}
	}
  	
  	for(i=0;robot2.str_point[i].length()>0;i++)
  	{
  		for(j=0;(str_pos[j].length()>0);j++)
  		{
  			if(!(robot2.str_point[i].compare(str_pos[j])))
			{
				robot2.str_rx[i] = str_x[j];
				robot2.str_ry[i] = str_y[j];
			}
  		}
	}
  	
  	for(i=0;robot3.str_point[i].length()>0;i++)
  	{
  		for(j=0;(str_pos[j].length()>0);j++)
  		{
  			if(!(robot3.str_point[i].compare(str_pos[j])))
			{
				robot3.str_rx[i] = str_x[j];
				robot3.str_ry[i] = str_y[j];
			}
  		}
	}
  	
  	cout << "Schedule Robot#1 -----------------------------" << endl;
	for(i=1;(robot1.str_point[i].length()>0);i++)
	{
		cout << "Point Robot#1[" << i << "] = "
			 << robot1.str_point[i] 
  			 << " TimeRobot#1[" << i << "] = " 
			 << robot1.str_time[i] << endl;
		robot1.str_time[i].reserve(8);
	}
	cout << " " << endl;
	
	cout << "Schedule Robot#2 -----------------------------" << endl;
	for(i=1;(robot2.str_point[i].length()>0);i++)
	{
		cout << "Point Robot#2[" << i << "] = "
			 << robot2.str_point[i] 
			 << " TimeRobot#2[" << i << "] = " 
			 << robot2.str_time[i] << endl; 
		robot2.str_time[i].reserve(8);
	
	}
	cout << " " << endl;
	
	cout << "Schedule Robot#3 -----------------------------" << endl;
	for(i=1;(robot3.str_point[i].length()>0);i++)
	{
		cout << "Point Robot#3[" << i << "] = "
			 << robot3.str_point[i] 
  			 << " TimeRobot#3[" << i << "] = " 
  			 << robot3.str_time[i] << endl;
		robot3.str_time[i].reserve(8);
	}
	
	

	i=1,j=1,k=1;
		
 	stringstream ss;

	stringstream ss_current_hour;	int current_hour;
	stringstream ss_current_minute; int current_minute;
	stringstream ss_current_second;	int current_second;
	
	string str_start_time;
	string str_current_time;
	
	time_t c_time = time(0);
    tm *local_time = localtime(&c_time);   
 	
	ss  << local_time->tm_hour << ":" 
		<< local_time->tm_min << ":" 
		<< local_time->tm_sec << endl;
		
	str_start_time = ss.str();

	cout << "---------------------------------------------- \n" 
		 << "Time Start : "  << str_start_time 
		 << "---------------------------------------------- \n"
		 << "Running ... " << endl;

	while(1)
	{
		time_t c_time = time(0);
    	tm *local_time = localtime(&c_time);   
 
		ss_current_hour  << local_time->tm_hour <<endl;
		ss_current_minute	<< local_time->tm_min <<endl;
		ss_current_second	<< local_time->tm_sec << endl;
		
		ss_current_hour >> current_hour;
		ss_current_minute >> current_minute;
		ss_current_second >> current_second;
	
		ss << current_hour << ":" 
		   << current_minute << ":" 
		   << current_second << endl;
		
		ss >> str_current_time;
		str_current_time.reserve(8);
		
		fstream read_rfid01("//192.168.1.37/SharedFile/rfid01.csv"); if(!read_rfid01.is_open()) cout << "FILE RFID#1 ERROR , PLEASE TRY AGAIN" << endl;
	  	a=0;
		while(getline(read_rfid01, line))
		{
			stringstream ss(line);
			
	    	getline(ss,robot1.str_rfid_x, ',');
	    	getline(ss,robot1.str_rfid_y, '\n');
	    		
	    	a++;
	  	}
	  	read_rfid01.close();
	  		
	  	fstream read_rfid02("//192.168.1.37/SharedFile/rfid02.csv"); if(!read_rfid02.is_open()) cout << "FILE RFID#2 ERROR , PLEASE TRY AGAIN" << endl;
	  	a=0;
		while(getline(read_rfid02, line))
		{
			stringstream ss(line);
			
	    	getline(ss,robot2.str_rfid_x, ',');
	    	getline(ss,robot2.str_rfid_y, '\n');
	
	    	a++;
	  	}
	  	read_rfid02.close();
	  		
	  	fstream read_rfid03("//192.168.1.37/SharedFile/rfid03.csv"); if(!read_rfid03.is_open()) cout << "FILE RFID#3 ERROR , PLEASE TRY AGAIN" << endl;
	  	a=0;
		while(getline(read_rfid03, line))
		{
			stringstream ss(line);
			
	    	getline(ss,robot3.str_rfid_x, ',');
	    	getline(ss,robot3.str_rfid_y, '\n');
	    
	    	a++;
	  	}
	  	read_rfid03.close();
	  
		if((!(str_current_time.compare(robot1.str_time[2])) && (robot1.str_point[i].length()>0)) || (!(robot1.str_rx[i].compare(robot1.str_rfid_x)) && !(robot1.str_ry[i].compare(robot1.str_rfid_y))))
		{	
			fstream write_sendgoal01("//192.168.1.37/SharedFile/sendgoal01.csv", ios::out | ios::trunc);
			if(!write_sendgoal01.is_open()) cout << "FILE SEND GOAL #1 ERROR , PLEASE TRY AGAIN" << endl;
		
					write_sendgoal01 << "x" << "," << "y" <<"\n"
									  << str_x[i] << "," << str_y[i] << endl;
					cout << "Write Point Robot#1["<<i<<"] = "  
						 << robot1.str_point[i] << " @ "
						 << str_current_time << endl;
					write_sendgoal01.close();
		
			
			i++;
		}
		
		if((!(str_current_time.compare(robot2.str_time[2])) && (robot2.str_point[j].length()>0)) || (!(robot2.str_rx[j].compare(robot2.str_rfid_x)) && !(robot2.str_ry[j].compare(robot2.str_rfid_y))))
		{	
			fstream write_sendgoal02("//192.168.1.37/SharedFile/sendgoal02.csv", ios::out | ios::trunc);
			if(!write_sendgoal02.is_open()) cout << "FILE SEND GOAL#2 ERROR , PLEASE TRY AGAIN" << endl;

					write_sendgoal02 << "x" << "," << "y" <<"\n"
									 << str_x[j] << "," << str_y[j] << endl;
					cout << "Write Point Robot#2["<<j<<"] = "  
						 << robot2.str_point[j] << " @ "
						 << str_current_time << endl;
					write_sendgoal02.close();
				
			
			j++;
		}
		
		if((!(str_current_time.compare(robot3.str_time[2])) && (robot3.str_point[k].length()>0)) || (!(robot3.str_rx[k].compare(robot3.str_rfid_x)) && !(robot3.str_ry[k].compare(robot3.str_rfid_y))))
		{	
			fstream write_sendgoal03("//192.168.1.37/SharedFile/sendgoal03.csv", ios::out | ios::trunc);
			
			if(!write_sendgoal03.is_open()) cout << "FILE SEND GOAL#3 ERROR , PLEASE TRY AGAIN" << endl;

		
					write_sendgoal03 << "x" << "," << "y" <<"\n"
									 << str_x[k] << "," << str_y[k] << endl;
					cout << "Write Point Robot#3["<<k<<"] = "  
						 << robot3.str_point[k] << " @ "
						 << str_current_time << endl;
					write_sendgoal03.close();
				
			
			k++;
		}
		
		if(((robot1.str_point[i].length()==0) && (robot2.str_point[j].length()==0) && (robot3.str_point[k].length()==0)))
		{	
			break;
		}
		Sleep(1000);
		
	}
}


