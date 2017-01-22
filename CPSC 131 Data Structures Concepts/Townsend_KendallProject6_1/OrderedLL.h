#include <iostream>
using namespace std;

template <class T >
class OrderedLL
{
private: struct NODE
		 {
			 T info;
			 NODE *next;
		 };
		 NODE *list;
public:
	//constructor
	OrderedLL(){list = NULL; }
	//insert item
	void insert(T x)
	{ 
		NODE *p = list, *q = list, *r;
		//create a new node
		r = new(NODE); r-> info = x;
		r -> next = NULL;
		//find the insertion place
		while (p != NULL && p->info < x)
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
		while ( p != NULL)
		{
			cout << p -> info << "-->"; p = p -> next; 
		}
		cout << "NULL \n";
	}
	//delete x from the linked list
	void DeleteNode(T x)
	{
		NODE *p = list, *r = list;
		while (p -> info != x)
		{
			r = p;
			p = p -> next;
		}
		if ( p == list)
		{//delete first node
			list = p -> next; delete(p);
		}
		else
		{
			r -> next = p -> next;
			delete(p);
		}
	}
};