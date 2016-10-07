//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.2/Part 5b:Problem 5b.cpp
//Due Date	September 13, 2012
//Professor	Ahmadnia
//
//Purpose To find the 34th fibonacci number and find the runtime using 
// a recursive function
//--------------------------------------------------------------------------

#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;


//function prototype
long int rfib(int n);

int main()
{
	// Print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	// create a timer that wil calculate how long it takes to calculate the fibonacci
	time_t start, finish;
	start = clock();
	cout << rfib(44) << endl;
	finish = clock();
	cout << "Run-time: " << (finish-start)/CLK_TCK << " seconds" << endl;
	
	return 0;
}
//-----------------------------
//name: rfib
//input: n - the fibonacci number that will be found
//output: the resultant fibonacci
//------------------------------


long int rfib(int n)
{
	// a recursive function that calculates fibonacci
	if(n==1 || n==2) return 1;
	else return rfib(n-1) + rfib(n-2);

}

//---------------------------------------
// Run Results
//---------------------------------------
//Today is Wed Sep 12 16:52:54 2012

//701408733
//Run-time: 58 seconds
//Press any key to continue . . .