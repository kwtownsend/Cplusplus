#include <iostream>
#include <string>
using namespace std;



class HASH
{
private: struct node
		 {
			 string MonthName; int day; node* next;
		 };
		 node* H[5];

public: HASH(){ for(int i=0; i<5; ++i) H[i] = NULL; }		
		int HashFun(string MonthName)
		{ return( int(toupper(MonthName[0])) +
				  int(toupper(MonthName[1])) +
				  int(toupper(MonthName[2])) ) % 5;
		}
		void insert(string a, int b)
		{
			int i= HashFun(a);
			node* p;
			p = new(node); p -> MonthName =  a; p -> day = b;
			p -> next = H[i];
			H[i] = p;
		}
		void Display()
		{
			node* p;
			for(int i=0; i< 5; ++i)
			{
				p = H[i]; cout << "H[" << i << "]-->";
				while (p != NULL)
				{
					cout << p -> MonthName << "-" << p -> day << "-->";
					p = p -> next;
				}
				cout << "NULL \n";
			}
		}
		void searchMonth(string x)
		{
			int i= HashFun(x);
			node* p = H[i];
			while( p!= NULL && p -> MonthName != x)
				p = p -> next;
			if(p == NULL)
				cout << x << "does not exit \n";
			else cout << "The amount of days in " << x << " is " << p -> day << endl;
		}

};