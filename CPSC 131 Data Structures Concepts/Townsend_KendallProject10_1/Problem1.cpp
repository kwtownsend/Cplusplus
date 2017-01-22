//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.10/Problem 1:Problem1.cpp
//Due Date  November 15, 2012
//Professor	Ahmadnia
//
// Read in an array and find various things about it
//--------------------------------------------------------------------------

#include <iostream>
#include "BST.h"

#include <ctime>
#include <string>
using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t b;
	time(&b);
	cout << "Today is " << ctime(&b) << endl;

	BST a;
	//insert array into nodes
	a.insert(22);
	a.insert(11);
	a.insert(88);
	a.insert(9);
	a.insert(15);
	a.insert(50);
	a.insert(90);
	a.insert(95);


	//display array
	a.display();

	int n = 0;
	a.CountNodes(n);
	cout << endl << "The number of leaves is " << n-1 << "." << endl;
	int m = 0;
	a.TwoChildren(m);
	cout << "The number of parents with two children is " << m << "." << endl;
	a.Search(30);
	cout << "The number of nodes is " << n << "." << endl;


	return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Nov 14 21:38:33 2012

//9       11      15      22      50      88      90      95
//The number of leaves is 7.
//The number of parents with two children is 3.
//Node 30 does not exist
//The number of nodes is 8.
//Press any key to continue . . .