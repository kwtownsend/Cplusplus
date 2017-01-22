#include <iostream>
using namespace std;
template <class T>
class queuepk
{
private: struct node
{
	 int coefficient;
	 int exponent;
	 node *next;
};
node *front, *rear;
public: queuepk() { front = NULL; rear = NULL; }
// add a node at the rear of queue
void pushq(int x, int y)
{ 
	node *p;
	p = new(node);
	p -> coefficient = x;
	p -> exponent = y;
	p -> next = NULL;
	if(front == NULL)
	{front = p; rear = p; }
	else
	{rear -> next = p; rear = p; }
}
// test whether queue is empty or not
bool Emptyq()
{ if (front == NULL ) return true;
else return false;
}
// pop the first node
T popcoefficientq()
{
	node *p = front; T x;
	x = front -> coefficient;
	return x;
}
T popexponentq()
{
	node *p = front; T x;
	x = front -> exponent;
	front = front -> next;
	delete (p);
	return x;
}
};