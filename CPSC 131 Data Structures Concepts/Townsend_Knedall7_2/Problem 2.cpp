//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.7/Problem 1:Problem1.cpp
//Due Date	October 25, 2012
//Professor	Ahmadnia
//
//Find out whether a phrase is a palindrome or not
//--------------------------------------------------------------------------

#include <iostream>
#include "queuepk.h"

#include <ctime>
#include <string>
using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;
	int coefficient = 1, exponent = 1;
	
	int s;
	queuepk<int> q;

	while( coefficient != 0 && exponent != 0)
	{
		cout << "Enter the coefficient and exponent, (0,0) to stop: ";
		cin >> coefficient;
		cin >> exponent;

		if ( coefficient == 0 && exponent == 0)
		{
			break;
		}
		q.pushq(coefficient, exponent);
	}

	cout << "Enter the a value to find f(a): ";
	cin >> s;
	int total = 0;
	while(!q.Emptyq())
	{
		int b = q.popcoefficientq();
		int c = q.popexponentq();
		total += b * s^c;
	}
		cout << "F(" << s << ") = " << total << endl;

		return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 24 22:25:56 2012

//Enter the coefficient and exponent, (0,0) to stop: 5 4
//Enter the coefficient and exponent, (0,0) to stop: 2 3
//Enter the coefficient and exponent, (0,0) to stop: 3 1
//Enter the coefficient and exponent, (0,0) to stop: 0 0
//Enter the a value to find f(a): 2
//F(2) = 28
//Press any key to continue . . .