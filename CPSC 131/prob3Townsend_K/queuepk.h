#include <iostream>
using namespace std;
template <class T>

class queuepk
{
private: struct node
 {
	 T info;
	 node *next;
 };
 node *front, *rear;
public: queuepk() {front = NULL; rear = NULL;}
		//add a node at the rear of the queue
		void pushq(T x)
		{ node *p;
		  p = new(node); 
		  p -> info = x; 
		  p -> next = NULL;
		if(front == NULL)
		{ 
			front = p; 
			rear = p;
		}
		else
		{
			rear -> next = p; 
			rear = p;}
		}
		// test whether queue is empty or not
		bool Emptyq()
		{ 
			if (front == NULL) 
				return true;
			else 
				return false;
		}
		// pop the first node
		T popq()
		{ 
			node *p = front; 
			T x;
		x = front -> info;
		front = front -> next;
		delete( p );
		return x;
		}

	int count()
	{
		int count = 0;
		T x;
		x = front -> info;
		if ( x -> info == NULL)
			return 0;
		else
		{
			node *p = front;
			x = front -> info;
			front = front -> next;
			delete(p);
			count++;
		}
		return count;
	}



};
