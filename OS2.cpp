 //taking linked list pointer as globle variable

#include<iostream>
#include<time.h>
using namespace std;

int PNS = 0;			// process no which we give to upcoming student process
int PNF = 0;			// process no which we give to upcoming faculty process
int TOTAL_TIME = 0;		// Total time
int NOF_PROCESS = 0;		// NOF_PROCESS : total no of process
int TBT = 0;                    // Total burst time
int TRT = 0;                    // Total running time

struct Node{
	int pno;      // pno : process number
	int bt;       // bt : burst time
	int at;       // at : arival time
	int pt;       // pt : process type (1: student , 2:faculty)
	Node *link;   // link to next node
}*new_node ,*start_stud = NULL, *start_faculty = NULL, *start = NULL, *ptr;   // *start is for common Linked List


void insert(int process,int no,int burst,int arival)
{
	new_node = new Node;
	new_node->pt = process;
	new_node->pno = no;
	new_node->bt = burst;
	new_node->at = arival;
	new_node->link = NULL;
	if (start == NULL)
		start = new_node;
	else
	{
		ptr = start;
		while(ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = new_node;
	}
}
void insert2(int process,int no,int burst,int arival)
{
	new_node = new Node;
	new_node->pt = process;
	new_node->pno = no;
	new_node->bt = burst;
	new_node->at = arival;
	new_node->link = NULL;
	if(process ==1){
		if (start_stud == NULL)
			start_stud = new_node;
		else
		{
			ptr = start_stud;
			while(ptr->link != NULL)
				ptr = ptr->link;
			ptr->link = new_node;
		}
	}
	else if(process ==2){
		if (start_faculty == NULL)
			start_faculty = new_node;
		else
		{
			ptr = start_faculty;
			while(ptr->link != NULL)
				ptr = ptr->link;
			ptr->link = new_node;
		}
	}
}



void show()
{
	ptr = start;
	cout<<"\n      PROCESS                 ARIVAL TIME                  BURST TIME\n";
	cout<<"----------------------------------------------------------------------------\n";

	while (ptr != NULL)
	{	if(ptr->pt == 1)
			cout<<"      P_S"<<ptr->pno;
		else
			cout<<"      P_F"<<ptr->pno;
		cout<<"\t\t\t"<<ptr->at<<"\t\t\t\t"<<ptr->bt<<endl;
		ptr = ptr->link;
	}
}



int main()
{	
	int arive_t = 0,nop,p_type[3],p_bt[3];        		// nop :no of process generated , p_type :(student, faculty), p_bt :process burst time
	int sum_bt = 0,sleep_t = 0,sum_st = 0;        		// sum_bt : sum of burst time, sum_st : sum of sleep time
	srand(time(0));
	nop = rand()%4;				      		// no of process generate at perticular time
	for(int i =0;i<nop;i++)
	{
		p_type[i] = ((rand()%2)+1);           		// define the type of each process process (1 : student or 2 : faculty)
		p_bt[i] = ((rand()%6)+1);	      		// defines burst time of each process  (min 1 , max 6)
		arive_t = arive_t+sleep_t;			// calculating arival time for process
		//sum_bt = 					//  will be used for comperision purpose to calculate totaltime process run
                NOF_PROCESS = NOF_PROCESS + 1;          	// incrementing in total no of process
		if (p_type[i] == 1)                   		// checking for process to be of student type
		{				      		// (if true)
			PNS = PNS + 1;				// incrementing in total no of student process
			insert2(1 , NOF_PROCESS , p_bt[i], arive_t);	// calling to incert in queue of student process
			insert(1 , PNS , p_bt[i] , arive_t);		// calling to incert in total process queue
		}
		else						// if process is of faculty type
              	{
                        PNF = PNF + 1;				// incrementing in total no of faculty process
                        insert2(2 , NOF_PROCESS , p_bt[i], arive_t);	//calling to incert faculty process queue
                        insert(2 , PNF , p_bt[i] , arive_t);		//calling to incert in total process queue
                }

	}
	
	show();
	return 0;
}
