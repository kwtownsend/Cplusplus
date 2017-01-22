//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.5/Problem 1:Problem1.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//Using a predetermined list find the amount of odd, even numbers, and add them all together.
//--------------------------------------------------------------------------

#include <iostream>
#include "stackpk.h"
#include <ctime>

using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;
	
	
	stackpk<int> temp;
	stackpk<int> q;
	//make predetermined linked list
	q.pushs(11);
	q.pushs(22);
	q.pushs(44);
	q.pushs(77);
	q.pushs(33);
	q.pushs(99);
	q.pushs(66);
	//display list
	while(!q.Emptys())
	{
		int x = q.pops();
		cout << x << "->";
		temp.pushs(x);
	}

	//display how many are even and odd
	int evencounter = 0;
	int totalamount = 0;
	cout << endl << "Amount of Even Numbers: ";
	while(!temp.Emptys())
	{
		int y = temp.pops();
			if( y % 2 == 0)
				evencounter++;
			totalamount += y;
			q.pushs(y);
	}
	cout << evencounter;

	int oddcounter = 0;
	cout << endl << "Amount of Odd Numbers: ";
	while(!q.Emptys())
	{
		int y = q.pops();
		if ( y % 2 != 0)
			oddcounter++;
	}
	cout << oddcounter << endl;
	cout << "Total Amount: " << totalamount << endl;
	return 0;
}
//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 10 16:53:20 2012

//66->99->33->77->44->22->11->
//Amount of Even Numbers: 3
//Amount of Odd Numbers: 4
//Total Amount: 352
//Press any key to continue . . .