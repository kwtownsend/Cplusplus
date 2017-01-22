//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.2/Part 3:Problem 3.cpp
//Due Date	September 13, 2012
//Professor	Ahmadnia
//
//Purpose To write a recursive frunction to compute 2^1 + 2^2 + 2^3..+2^n.
//--------------------------------------------------------------------------

#include<iostream>
#include<cmath>
#include <ctime>

using namespace std;

//function prototype
int sum(int n);

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	//print the sum of the 10th of the terms
	cout << "The tenth digit of the function 2^1+2^2+2^3+...+2^n is: "
		<< sum(10) << endl;


	return 0;
}

//-----------------------------
//name: sum
//input: n - the determinent of how many terms
//output: the result of the sum of the numbers 2^1+2^2+2^3+...+2^n
//------------------------------
int sum(int n)
{
	if ( n==1)
		return 2;
	else return pow(2.0, n)+sum(n-1);

	return n;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 12 17:27:55 2012

//The tenth digit of the function 2^1+2^2+2^3+...+2^n is: 2046
//Press any key to continue . . .