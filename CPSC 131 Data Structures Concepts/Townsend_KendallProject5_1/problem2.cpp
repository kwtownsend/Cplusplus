//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.5/Problem 2:Problem2.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//Display queue, the odd numbers, and the even numbers.
//--------------------------------------------------------------------------

#include <iostream>
#include "queuepk.h"
#include <ctime>

using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	queuepk <int> temp;
	queuepk <int> q;
	//make predetermined linked list
	q.pushq(11);
	q.pushq(22);
	q.pushq(44);
	q.pushq(77);
	q.pushq(33);
	q.pushq(99);
	q.pushq(66);

	//display all members of linked list
	while(!q.Emptyq())
	{
		int x = q.popq();
		cout << x << "->";
		temp.pushq(x);
	}
	//find whether its even or odd
	cout << endl << "Even: ";
	while(!temp.Emptyq())
	{
		int y = temp.popq();
			if( y % 2 == 0)
				cout  << y << " ";
			q.pushq(y);
	}
	cout << endl << "Odd: ";
	while(!q.Emptyq())
	{
		int y = q.popq();
		if ( y % 2 != 0)
			cout << y << " ";
	}
	cout << endl;

	return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 10 16:54:18 2012

//11->22->44->77->33->99->66->
//Even: 22 44 66
//Odd: 11 77 33 99
//Press any key to continue . . .