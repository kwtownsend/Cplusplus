//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.4/Problem 2:Problem 2.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//Take in a phrase and decide whether or not its a palindrome
//--------------------------------------------------------------------------

#include <iostream>
#include "STACK.h"
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;



int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	STACK <int, 20> Operands; Operands.MakeStack();
	
	string item;
	
	int x, y, r = 0;

	cout << "Enter a postfix expression: ";

	do
	{
		cin >> item;
		if(item == "+")
		{
			x = Operands.PopStack();
			y = Operands.PopStack();
			r = y + x;
			Operands.PushStack(r);
		}
		if(item == "-")
		{
			x = Operands.PopStack();
			y = Operands.PopStack();
			r = y - x;
			Operands.PushStack(r);
		}
		if(item == "*")
		{
			x = Operands.PopStack();
			y = Operands.PopStack();
			r = y * x;
			Operands.PushStack(r);
		}
		if(item == "/")
		{
			x = Operands.PopStack();
			y = Operands.PopStack();
			r = y / x;
			Operands.PushStack(r);
		}
		else
		{
			x = atoi(item.c_str());
			Operands.PushStack(x);
		}
	}while(item != "$");

	int answer;
	while(!Operands.EmptyStack())
	{
		answer = Operands.PopStack();
		cout << "Value = " << answer << endl;
	}


	return 0;
}

//------------------------------------
//Run Results
// Info: I was unable to get the Stack to work correctly
// most notably when i popped the stack it would leave the previous value as 0
// and cause my program to just repeatedly do the last two which would contain 0 and nothing would change.
//------------------------------------
//Today is Wed Sep 26 21:52:49 2012

//Enter a postfix expression: 5 5 5 + + $
//Value = 0
//Value = 0
//Value = 10
//Value = 5
//Press any key to continue . . .