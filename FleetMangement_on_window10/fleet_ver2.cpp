#include<bits/stdc++.h>
using namespace std;

 class robot_data 
{  
	public : 
	 
		string str_point[20]; 		int point[20];
		string str_time[20];     	int time[20];
		string str_dist[20];		int dist[20];
		
		int source;
		int dest;
		int speed;
		
		string str_hour[20]; 		int hour[20];
		string str_minute[20]; 		int minute[20];
		string str_second[20]; 		int second[20] ;
		long time_sec[20];
};

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w, int weight); // adds an edge
  
    // finds shortest path from source vertex ‘s’ to
    // destination vertex ‘d’.
    int findShortestPath(int s, int d ,int r);
  
    // print shortest path from a source vertex ‘s’ to
    // destination vertex ‘d’.
    int printShortestPath(int parent[], int s, int d,int robot);
};
  
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[2*V];
}

std::string convert_time_sec(int time) 
{
	stringstream ss;
	int hour,min,sec ;
	string hms ;
    hour = time/3600;
    time = time%3600;
    min = time/60;
    time = time%60;
    sec = time;

	ss << hour << ":" << min << ":" << sec ; 
	hms = ss.str();
	return hms ;
}


void routing()
{
	robot_data robot1;	
	robot_data robot2;	
	robot_data robot3;	 
	
	robot1.speed = 2;
	robot2.speed = 2;
	robot3.speed = 2;

	string line ;
	int i,j,sum;
	string joinpoint;
	int timewait=10;
	
	fstream read_schedule("schedule.csv");
  	if(!read_schedule.is_open()) cout << "FILE SCHEDULE ERROR , PLEASE TRY AGAIN" << endl;
  	i=0;
  	while(getline(read_schedule, line))
	{
		stringstream ss(line);
   		getline(ss,robot1.str_point[i], ',');
    	getline(ss,robot1.str_time[i], ',');
    	getline(ss,robot2.str_point[i], ',');
    	getline(ss,robot2.str_time[i], ',');
    	getline(ss,robot3.str_point[i], ',');
    	getline(ss,robot3.str_time[i], '\n');
    	
    	stringstream ssx(robot1.str_time[i]);
   		getline(ssx,robot1.str_hour[i], ':');
    	getline(ssx,robot1.str_minute[i], ':');
    	getline(ssx,robot1.str_second[i], '\n');
		stringstream convert1(robot1.str_hour[i]);			convert1 >> robot1.hour[i];
		stringstream convert2(robot1.str_minute[i]);		convert2 >> robot1.minute[i];
		stringstream convert3(robot1.str_second[i]);		convert3 >> robot1.second[i];
		robot1.time_sec[i] = robot1.hour[i]*3600 + robot1.minute[i]*60 + robot1.second[i];

		
		stringstream ssy(robot2.str_time[i]);
   		getline(ssy,robot2.str_hour[i], ':');
    	getline(ssy,robot2.str_minute[i], ':');
    	getline(ssy,robot2.str_second[i], '\n');
		stringstream convert4(robot2.str_hour[i]);			convert4 >> robot2.hour[i];
		stringstream convert5(robot2.str_minute[i]);		convert5 >> robot2.minute[i];
		stringstream convert6(robot2.str_second[i]);		convert6 >> robot2.second[i];
		robot2.time_sec[i] = robot2.hour[i]*3600 + robot2.minute[i]*60 + robot2.second[i];
		
		stringstream ssz(robot3.str_time[i]);
   		getline(ssz,robot3.str_hour[i], ':');
    	getline(ssz,robot3.str_minute[i], ':');
    	getline(ssz,robot3.str_second[i], '\n');
		stringstream convert7(robot3.str_hour[i]);			convert7 >> robot3.hour[i];
		stringstream convert8(robot3.str_minute[i]);		convert8 >> robot3.minute[i];
		stringstream convert9(robot3.str_second[i]);		convert9 >> robot3.second[i];
		robot3.time_sec[i] = robot3.hour[i]*3600 + robot3.minute[i]*60 + robot3.second[i];

    	
    	i++;
  	}
  	read_schedule.close();
 	
 
  	for(i=2;(robot1.str_point[i].length()>0);i++)
	{
		robot1.dist[i]=100;
	}
	
	for(i=2;(robot2.str_point[i].length()>0);i++)
	{
		robot2.dist[i]=100;
	}
	
	for(i=2;(robot3.str_point[i].length()>0);i++)
	{
		robot3.dist[i]=100;
	}
	
	sum=0;
	cout << "\n----------------------------------------------------------" << endl;
	cout << "Schedule Robot#1 -----------------------------------------" << endl;
  	for(i=1;robot1.str_point[i].length()>0;i++)
	{
		cout << "\tPath Robot#1[" << i << "] = ";
		cout << robot1.str_point[i] ;
		sum += robot1.dist[i];
  		robot1.time_sec[i] = robot1.time_sec[1] + sum/robot1.speed;
  		cout << "\tTime Robot#1[" << i << "] = ";
		cout <<  convert_time_sec(robot1.time_sec[i])<< endl;
	}
	
 	sum=0;
 	cout << "\nSchedule Robot#2 -----------------------------------------" << endl;
  	for(i=1;robot2.str_point[i].length()>0;i++)
	{
		cout << "\tPath Robot#2[" << i << "] = ";
		cout << robot2.str_point[i] ;
		sum += robot2.dist[i];
  		robot2.time_sec[i] = robot2.time_sec[1] + sum/robot2.speed;
  		cout << "\tTime Robot#2[" << i << "] = ";
		cout <<  convert_time_sec(robot2.time_sec[i])<< endl;
	}
	
	sum=0;
	cout << "\nSchedule Robot#3 -----------------------------------------" << endl;
  	for(i=1;robot3.str_point[i].length()>0;i++)
	{
		cout << "\tPath Robot#3[" << i << "] = ";
		cout << robot3.str_point[i] ;
		sum += robot3.dist[i];
  		robot3.time_sec[i] = robot3.time_sec[1] + sum/robot3.speed;
  		cout << "\tTime Robot#3[" << i << "] = ";
		cout <<  convert_time_sec(robot3.time_sec[i])<< endl;
	}
	
	for(i=1;robot1.str_point[i].length()>0;i++)
	{
		for(j=1;robot2.str_point[j].length()>0;j++)
		{	
		
			if((abs(robot1.time_sec[i] - robot2.time_sec[j]) < 10) && robot1.str_point[i] == robot2.str_point[j])
				{
					cout << "----------------------------------------------------------" << endl;
					joinpoint = robot2.str_point[j];
					cout << "Joint Point Robot 1-2 At " ;
					cout <<  joinpoint << endl ;
					cout << "----------------------------------------------------------" << endl;
					while (robot2.str_point[j].length()>0)
					{
						robot2.time_sec[j] += timewait;
						cout << "\tTimeRobot#2[" << j << "] + "<<timewait<< endl ;
						j++;
					}
	           		cout << "----------------------------------------------------------" << endl;
				}	
		}
	      
	}
	
	for(i=1;robot1.str_point[i].length()>0;i++)
	{
		for(j=1;robot3.str_point[j].length()>0;j++)
		{	
		
			if((abs(robot1.time_sec[i] - robot3.time_sec[j]) < 10) && robot1.str_point[i] == robot3.str_point[j])
				{
					cout << "----------------------------------------------------------" << endl;
					joinpoint = robot3.str_point[j];
					cout << "Joint Point Robot 1-3 At " ;
					cout <<  joinpoint << endl ;
					cout << "----------------------------------------------------------" << endl;
					while (robot3.str_point[j].length()>0)
					{
						robot3.time_sec[j] += timewait;
						cout << "\tTime Robot#3[" << j << "] + "<<timewait<< endl ;
						j++;
					}
	           		cout << "----------------------------------------------------------" << endl;
				}	
		}
	      
	}
	
	for(i=1;robot2.str_point[i].length()>0;i++)
	{
		for(j=1;robot3.str_point[j].length()>0;j++)
		{	
		
			if((abs(robot2.time_sec[i] - robot3.time_sec[j]) < 10) && robot2.str_point[i] == robot3.str_point[j])
				{
					cout << "----------------------------------------------------------" << endl;
					joinpoint = robot3.str_point[j];
					cout << "Joint Point Robot 2-3 At " ;
					cout <<  joinpoint << endl ;
					cout << "----------------------------------------------------------" << endl;
					while (robot3.str_point[j].length()>0)
					{
						robot3.time_sec[j] += timewait;
						cout << "\tTime Robot#3[" << j << "] + "<<timewait<< endl ;
						j++;
					}
	           		cout << "----------------------------------------------------------" << endl;
				}	
		}
	      
	}
	
	cout << "New Schedule Robot#1 -------------------------------------" << endl;
	for(i=1;robot1.str_point[i].length()>0;i++)
	{
		cout << "\tPath Robot#1[" << i << "] = ";
		cout <<  robot1.str_point[i] ;
		robot1.str_time[i] = convert_time_sec(robot1.time_sec[i]);
		cout << "\tTime Robot#1[" << i << "] = ";
		cout <<  robot1.str_time[i] << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	
	cout << "New Schedule Robot#2 -------------------------------------" << endl;
		
	for(i=1;robot2.str_point[i].length()>0;i++)
	{
		cout << "\tPath Robot#2[" << i << "] = ";
		cout <<  robot2.str_point[i] ;
		robot2.str_time[i] = convert_time_sec(robot2.time_sec[i]);
		cout << "\tTime Robot#2[" << i << "] = ";
		cout <<  robot2.str_time[i] << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	
	cout << "New Schedule Robot#3 -------------------------------------" << endl;
	for(i=1;robot3.str_point[i].length()>0;i++)
	{
		cout << "\tPath Robot#3[" << i << "] = ";
		cout <<  robot3.str_point[i] ;
		robot3.str_time[i] = convert_time_sec(robot3.time_sec[i]);
		cout << "\tTime Robot#3[" << i << "] = ";
		cout <<  robot3.str_time[i] << endl;
	}
	cout << "----------------------------------------------------------" << endl;
	
	fstream write_schedule("schedule.csv", ios::out | ios::trunc);
  	if(!write_schedule.is_open()) cout << "FILE SCHEDULE ERROR , PLEASE TRY AGAIN" << endl;
  	
	write_schedule <<"Path_1"<<","
			   <<"Time_1"<<","
			   <<"Path_2"<<","
			   <<"Time_2"<<","
			   <<"Path_3"<<","
			   <<"Time_3"<<endl;
			   
	for(i=1;robot1.str_point[i].length()>0;i++)
	{
		write_schedule <<robot1.str_point[i]<< "," <<robot1.str_time[i] << ","<<","<<","<<","<<endl;
	}
	
	for(i=1;robot2.str_point[i].length()>0;i++)
	{
		write_schedule <<","<< "," <<robot2.str_point[i]<< "," <<robot2.str_time[i] << ","<<","<<endl;
	}	
	
	for(i=1;robot3.str_point[i].length()>0;i++)
	{
		write_schedule <<","<< "," <<","<< "," <<robot3.str_point[i]<<","<<robot3.str_time[i]<<endl;  
	}
		
	write_schedule.close();
}	

  
void Graph::addEdge(int v, int w, int weight)
{
    // split all edges of weight 2 into two
    // edges of weight 1 each.  The intermediate
    // vertex number is maximum vertex number + 1,
    // that is V.
    if (weight==2)
    {
        adj[v].push_back(v+V);
        adj[v+V].push_back(w);
    }
    else // Weight is 1
        adj[v].push_back(w); // Add w to v’s list.
}

  
int Graph::printShortestPath(int parent[], int s, int d,int robot)
{
    robot_data robot1;	
	robot_data robot2;	
	robot_data robot3;
	string line ;
	static int level = 0;
	int i;
  	fstream write_schedule("schedule.csv", ios::app);
	if(!write_schedule.is_open()) cout << "FILE SCHEDULE ERROR , PLEASE TRY AGAIN" << endl;
	
	switch(robot) 
	{
  	case 1:
  	i=0;
    if (parent[s] == -1)
    {
    	cout << "Enter Time Start Robot#1 :";	
		cin >> robot1.str_time[1];
        cout << "Path Robot#1 :"<< s << " ";
        write_schedule <<"\n"<< s <<","<< robot1.str_time[1] <<"," <<","<<","<<"," ;
        robot1.point[1]=s;
        i++;
		return 0;
    }
    
    printShortestPath(parent, parent[s], d,robot);
  
    level++;
    if (s < V)
    {
		cout << s << " ";
  		write_schedule <<"\n"<<s<<"," <<","<<","<<","<<"," ;
	}
	write_schedule.close(); 
	
	return 0;
	break;
	
	
  	case 2:
  	i=0;
    if (parent[s] == -1)
    {
    	cout << "Enter Time Start Robot#2 :";	
		cin >> robot2.str_time[1];
        cout << "Path Robot#2 :"<< s << " ";
        write_schedule <<"\n"<<","<<","<< s <<","<< robot2.str_time[1] <<","<<"," ;
        robot2.point[1]=s;
        i++;
		return 0;
    }
    
    printShortestPath(parent, parent[s], d,robot);
  
    level++;
    if (s < V)
    {
		cout << s << " ";
  		write_schedule <<"\n"<<","<<","<< s <<","<<","<<"," ;
	}
	write_schedule.close(); 
	
	return 0;
	break;
	
	
	case 3:
  	i=0;
    if (parent[s] == -1)
    {
    	cout << "Enter Time Start Robot#3 :";	
		cin >> robot3.str_time[1];
        cout << "Path Robot#3 :"<< s << " ";
        write_schedule <<"\n"<<","<<","<<","<<","<< s <<","<< robot3.str_time[1] ;
        robot3.point[1]=s;
        i++;
		return 0;
    }
    
    printShortestPath(parent, parent[s], d,robot);
  
    level++;
    if (s < V)
    {
		cout << s << " ";
  		write_schedule <<"\n"<<","<<","<<","<<","<<s<<"," ;
	}
	write_schedule.close(); 
	
	return 0;
	break;
	
	}
}
  

int Graph::findShortestPath(int src, int dest, int robot)
{
	
    bool *visited = new bool[2*V];
    int *parent = new int[2*V];
  
    // Initialize parent[] and visited[]
    for (int i = 0; i < 2*V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
  
    // Create a queue for BFS
    list<int> queue;
  
    // Mark the current node as visited and enqueue it
    visited[src] = true;
    queue.push_back(src);
  
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
  
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int s = queue.front();
  
        if (s == dest)
            return printShortestPath(parent, s, dest,robot);
  
        queue.pop_front();
  

        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i] = s;
            }
        }
    }
}
 



void set_csv()
{
	string c1[50] ;
	string c2[50] ;
	string c3[50] ;
	string c4[50] ;
	string c5[50] ;
	string c6[50] ;
	string line ;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	int a4 = 0;
	int a5 = 0;
	int a6 = 0; 
	int i;
	
	fstream read_schedule("schedule.csv");
  	if(!read_schedule.is_open()) cout << "FILE SCHEDULE ERROR , PLEASE TRY AGAIN" << endl;
  	i=0;
  	while(getline(read_schedule, line))
	{
		stringstream ss(line);
   		getline(ss,c1[i], ',') ;
    	getline(ss,c2[i], ',');
    	getline(ss,c3[i], ',');
    	getline(ss,c4[i], ',');
    	getline(ss,c5[i], ',');
    	getline(ss,c6[i], '\n');
    	i++;
    	
  	}
  	
  	read_schedule.close();
  
  
	i=1;
	while(c1[i].length()==0){a1++;i++;}

	i=1;
	while(c2[i].length()==0){a2++;i++;}

	i=1;
	while(c3[i].length()==0){a3++;i++;}

	i=1;
	while(c4[i].length()==0){a4++;i++;}

	i=1;
	while(c5[i].length()==0){a5++;i++;}

	i=1;
	while(c6[i].length()==0){a6++;i++;}


	
  	fstream write_schedule("schedule.csv", ios::out | ios::trunc);
  	if(!write_schedule.is_open()) cout << "FILE SCHEDULE ERROR , PLEASE TRY AGAIN" << endl;
  	
	write_schedule <<"Path_1"<<","
			   <<"Time_1"<<","
			   <<"Path_2"<<","
			   <<"Time_2"<<","
			   <<"Path_3"<<","
			   <<"Time_3"<<endl;
	
	for(i=1;(c1[i+a1].length()>0 || c2[i+a2].length()>0 || c3[i+a3].length()>0 || c4[i+a4].length()>0 || c5[i+a5].length()>0 || c6[i+a6].length()>0);i++) 
	{
		write_schedule << c1[a1+i] << "," << c2[a2+i] << ","<< c3[a3+i] << "," << c4[a4+i] << ","<< c5[a5+i] << ","<< c6[a6+i] << "\n";
	}
	write_schedule.close();
}


int main()
{
	robot_data robot1;	
	robot_data robot2;	
	robot_data robot3;	 
	
	int robot ;
	int i,j,k,v,sum;
	
	string str_from[300] ;	int from[300];
	string str_to[300];		int to[300];
	string str_dist[300];	int dist[300];
	string str_angle[300];	int angle[300];
	
	string line ;
	
	cout << "----------------------------------------------------------" << endl;
	cout << "                     FLEET MANAGEMENT                     " << endl;
	cout << "----------------------------------------------------------" << endl;

    
	fstream read_path_data("path_data.csv");
  	if(!read_path_data.is_open()) cout << "FILE PATH DATA ERROR , PLEASE TRY AGAIN" << endl;
  	i=0;
  	while(getline(read_path_data, line))
	{
		stringstream ss(line);
   		getline(ss,str_from[i], ',') ;
    	getline(ss,str_to[i], ',');
    	getline(ss,str_dist[i], ',');
    	getline(ss,str_angle[i], '\n');
    	
    	stringstream convert1(str_from[i]);		convert1 >> from[i];	
		stringstream convert2(str_to[i]);		convert2 >> to[i];
    	stringstream convert3(str_dist[i]);		convert3 >> dist[i];	
		stringstream convert4(str_angle[i]);	convert4 >> angle[i];
    	v = i ;
    	i++;
  	}
  	read_path_data.close();
  	
  	
  	Graph g(v);
  	
  	for(i=1;i<v;i++)
	{
		g.addEdge(from[i],to[i],dist[i]);
	}

	

	fstream write_schedule("schedule.csv", ios::out | ios::trunc);
	if(!write_schedule.is_open()) cout << "FILE PATH ERROR , PLEASE TRY AGAIN" << endl;
	write_schedule.close(); 
	
	robot = 1;
    cout << "\nEnter Source Robot#1 :";	cin >> robot1.source; 
    cout << "Enter Destination Robot#1 :";	cin >> robot1.dest;
	g.findShortestPath(robot1.source,robot1.dest,robot);
	
	robot = 2;
    cout << "\nEnter Source Robot#2 :";	cin >> robot2.source; 
    cout << "Enter Destination Robot#2 :";	cin >> robot2.dest;
	g.findShortestPath(robot2.source,robot2.dest,robot);
	
	robot = 3;
    cout << "\nEnter Source Robot#3 :";	cin >> robot3.source; 
    cout << "Enter Destination Robot#3 :";	cin >> robot3.dest;
	g.findShortestPath(robot3.source,robot3.dest,robot);
	
	set_csv(); 
	routing();
	set_csv();  

	
  	return 0;

  
}
