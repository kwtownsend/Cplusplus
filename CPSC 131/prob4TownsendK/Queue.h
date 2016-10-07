#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class queuepk
{
private: struct node
 {
	 string description;
	 int idnumber;
	 node *next;
 };
 node *front, *rear;
public: queuepk() {front = NULL; rear = NULL;}
		//add a node at the rear of the queue
		void pushq(string description, int idnumber)
		{ node *p;
		  p = new(node);
		  p -> description = description; 
		  p -> idnumber = idnumber;
		  p -> next = NULL;
		if(front == NULL)
		{ 
			front = p; 
		    rear = p;
		}
		else if ( idnumber < p-> idnumber)
		{
			front -> next = p; 
			front = p;}
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
		void popq(int x)
		{ 
			node *p = front; 

			if ( p -> idnumber = x)
			{
				delete(p);
				front = p -> next;
			}
			else if( p -> idnumber != x)
			{
				p = p -> next;
			}
			else if( p -> next == NULL)
			{
				cout << "Part number not found" << endl;
			}

		}

	void SearchPart(node* p, int x)
	{
		if (p == NULL)
		{
			cout << "Part" << x << " does not exist" << endl;
		}
		else if (x == p -> idnumber)
		{
			cout << setw(10) << left<< "Part Number: " << p -> idnumber << endl;
			cout << setw(10) << left << "Description "<< p -> description;
		}
		else
		{
			SearchPart(p -> next, x);
		}
	}

	void SearchPart(int x)
	{
		SearchPart(front, x);
	}
	void DisplayAll()
	{
		DisplayAll(front);
	}

	void insert(node* &p, string description, int idnumber )
	{
			if( p == NULL ) 
			{
				p = new(node); p -> description = description; p -> idnumber = idnumber; 
				p -> next = NULL;
			}
			else if(p != NULL )
			{
				insert(p -> next, description, idnumber);
			}
		}
		void insert(string description, int idnumber)
		{
			insert(front, description, idnumber);
	}
	//can't get to work fully
	void DisplayAll(node* p)
	{
		if(p != NULL)
		{
			cout << "Part Number: " << p -> idnumber << endl;
			cout << "Description: " << p -> description << endl;
			p = p -> next;
			DisplayAll( p);
		}
	}
};



