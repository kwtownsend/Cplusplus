//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.3/Problem 4:Problem4.cpp
//Due Date	September 20, 2012
//Professor	Ahmadnia
//
//Take in a phrase and printing it back in reverse
//--------------------------------------------------------------------------

#include <iostream>
#include "STACK.h"
#include <ctime>

using namespace std;

//function prototype
bool isodd(int c);
bool iseven(int c);

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;
	bool valid = true;
	STACK <int, 20> Even; Even.MakeStack();
	STACK <int, 20> Odd; Odd.MakeStack();
	int c;
	cout << "Enter a group of scores with -1 at the end: ";
	do
	{
		cin >> c;
		//put them in their proper stack
		if(c == -1)
		{
			valid = false;
			break;
		}
		else
			valid = true;
		if (iseven(c))
		{ 
			Even.PushStack(c);
		}
		else if(isodd(c))
		{
			Odd.PushStack(c);
		}
	}while(valid);

	//display them in their proper category
	int x;
	cout << "Even Numbers: ";
	while(!Even.EmptyStack())
	{
		x = Even.PopStack();
		cout <<  x << " ";
	}
	cout << endl;

	cout << "Odd Numbers: ";
	while(!Odd.EmptyStack())
	{
		x = Odd.PopStack();
		cout <<  x << " ";
	}
	cout << endl;

	return 0;
}

//-----------------------------
//name: isodd
//input: char c
//output: returns whether or not its even
//------------------------------

bool iseven(int c)
{
	if( c % 2 == 0)
		return true;
	else
		return false;
}

//-----------------------------
//name: isodd
//input: char c
//output: returns whether or not its odd
//------------------------------
bool isodd(int c)
{
	if(c % 2 != 0)
		return true;
	else
		return false;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 19 21:00:09 2012

//Enter a group of scores with -1 at the end: 44 77 55 22 88 11 -1
//Even Numbers: 88 22 44
//Odd Numbers: 11 55 77
//Press any key to continue . . .