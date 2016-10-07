//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.5/Problem 3:Problem3.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//display all the nodes of two list, find the average, and how many are above average.
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

	stackpk<int> p;
	stackpk<int> q;
	stackpk<int> tempp;
	stackpk<int> tempq;
	
	p.pushs(11);
	p.pushs(22);
	p.pushs(44);
	p.pushs(77);
	p.pushs(33);
	p.pushs(99);
	p.pushs(66);

	q.pushs(66);
	q.pushs(99);
	q.pushs(33);
	q.pushs(77);
	q.pushs(44);
	q.pushs(22);
	q.pushs(11);
	int count = 0;
	int total = 0;
	
	// display nodes and find total
	cout << "All Nodes: ";
	while(!p.Emptys())
	{
		int s = p.pops();
		tempp.pushs(s);
		cout << s << " ";
		total += s;
		count++;
	}

	while(!q.Emptys())
	{
		int s = q.pops();
		tempq.pushs(s);
		cout << s << " ";
		total += s;
		count++;
	}

	//find average
	int average = total/count;
	cout << endl << "Average: " << average << endl;
	int aboveaverage = 0;
	//find numbers above average
	cout << "Numbers Above Average: ";
		while(!tempp.Emptys())
	{
		int s = tempp.pops();
		if (s > average)
		{
			aboveaverage++;
		}
	}

		while(!tempq.Emptys())
	{
		int s = tempq.pops();
		if (s > average)
		{
			aboveaverage++;
		}
	}
		cout << aboveaverage << endl;

		return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 10 17:22:42 2012

//All Nodes: 66 99 33 77 44 22 11 11 22 44 77 33 99 66
//Average: 50
//Numbers Above Average: 6
//Press any key to continue . . .