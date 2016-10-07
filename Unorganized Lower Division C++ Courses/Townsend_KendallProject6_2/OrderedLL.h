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
		while (p != NULL && p -> info < x)
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
	template <class T>
	friend void CombineNode(OrderedLL <T> a, OrderedLL <T> b, OrderedLL <T>& aub)
	{
		while(a.list != NULL && b.list != NULL)
		{
			if(a.list -> info == b.list -> info)
			{
				aub.insert(a.list -> info);
				a.list = a.list -> next;
				b.list = b.list -> next;
			}
			else if(b.list -> info < a.list -> info)
			{
				aub.insert(b.list -> info);
				b.list = b.list -> next;
			}
			else
			{
				aub.insert(a.list -> info);
				a.list = a.list -> next;
			}
		}	
	}

	
};