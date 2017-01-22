#include <iostream>
#include <string>
using namespace std;


class OrderedLL
{
private: struct NODE
		 {
			 string name;
			 int Time;
			 NODE *next;
		 };
		 NODE *list;
public:
	//constructor
	OrderedLL(){list = NULL; }
	//insert item
	void insert(string x, int y)
	{ 
		NODE *p = list, *q = list, *r;
		//create a new node
		r = new(NODE); r-> name = x; r -> Time = y;
		r -> next = NULL;
		//find the insertion place
		while (p != NULL)
			{ q = p; p = p -> next; }
		if (p == list)// x is the first info
			{ list = r; r -> next = p; }
		else if(p == NULL) // x is the last info
			{ q -> next = r; }
		else // x is neither first nor last info
			{ r -> next = p; q -> next = r; }
	}
	//organize item
	void Organize(string x, int y)
	{ 
		NODE *p = list, *q = list, *r;
		//create a new node
		r = new(NODE); r-> name = x; r -> Time = y;
		r -> next = NULL;
		//find the insertion place
		while (p != NULL && p -> Time < y)
			{ q = p; p = p -> next; }
		if (p == list)// x is the first info
			{ list = r; r -> next = p; }
		else if(p == NULL) // x is the last info
			{ q -> next = r; }
		else // x is neither first nor last info
			{ r -> next = p; q -> next = r; }
	}
	//display
	void display()
	{
		NODE *p = list;
		cout << "Waiting List ->";
		while ( p != NULL)
		{
			cout << p -> name << " /" << p -> Time << "-->";
			p = p -> next; 
		}
		cout << "NULL \n";
	}
	
};