//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.2/Part 4:Problem 4.cpp
//Due Date	September 13, 2012
//Professor	Ahmadnia
//
//Purpose To write a recursive frunction to compute 2^1 + 2^2 + 2^3..+2^n.
//--------------------------------------------------------------------------

#include<iostream>
#include<cmath>
#include<ctime>


using namespace std;


//function prototype
int sum(int n);

int main()
{

	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	// print out the sum of the functions 13th term
	cout << "The tenth digit of the function 2^5+3^5+4^5+...+n^5 is: "
		<< sum(13) << endl;

	return 0;
}

//-----------------------------
//name: sum
//input: n - the determinent of how many terms
//output: the result of the sum of the numbers 2^5+3^5+4^5+...+n^5
//------------------------------

int sum(int n)
{
	if ( n==1)
		return 2;
	else return pow(n, 5.0) + sum(n-1);

	return n;
}


//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 12 17:29:30 2012

//The tenth digit of the function 2^5+3^5+4^5+...+n^5 is: 1002002
//Press any key to continue . . .