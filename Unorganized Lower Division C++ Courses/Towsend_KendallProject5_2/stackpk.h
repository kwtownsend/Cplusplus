#include <iostream>
using namespace std;
template <class T>

class stackpk
{
private: struct node
 {
	 T info;
	 node *next;
 };
 node *stack;
public: stackpk() {stack = NULL; }
		//add a node at the front of list
		void pushs(T x)
		{	node*p;
			p = new(node); p -> info = x; p -> next = NULL;
			if (stack == NULL)
			{stack = p; }
			else
			{p -> next = stack; stack = p; }
		}
		//test whetehr stack is empty or not
		bool Emptys()
		{if (stack == NULL) return true;
		else return false;
		}
		//pop the first node
		T pops()
		{
			node *p = stack; T x;
			x = stack -> info;
			stack = stack -> next;
			delete (p);
			return x;
		}
};
