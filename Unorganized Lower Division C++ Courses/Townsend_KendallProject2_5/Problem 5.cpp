//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.2/Part 5a:Problem 5.cpp
//Due Date	September 13, 2012
//Professor	Ahmadnia
//
//Purpose To find the 34th fibonacci number and find the runtime using 
// a non recursive function
//--------------------------------------------------------------------------

#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;


//function prototype
long int nrfib(int n);

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	//create a timer that will calculate how long it takes to calculate the fibonacci
	time_t start, finish;
	start = clock();
	cout << nrfib(44) << endl;
	finish = clock();
	cout << "Run-time: " << (finish-start)/CLK_TCK << " seconds" << endl;
	
	return 0;
}
//-----------------------------
//name: nrfib
//input: n - the fibonacci number that will be found
//output: the resultant fibonacci
//------------------------------


long int nrfib(int n)
{
	//a non recursive function that calculates fibonacci
	long int a =1, b =1, fn;
	for(int i=3; i<=n; i++)
	{
		fn = a + b;
		a = b;
		b = fn;
	}

	return fn;
}


//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 12 16:57:10 2012

//701408733
//Run-time: 0 seconds
//Press any key to continue . . .