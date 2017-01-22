//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.3/Problem 2:Problem2.cpp
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
void RunReverse();

int main()
{	
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;



	char y;
	int n = 1;
	for(int i =0; i < n; i++)
	{

		RunReverse();
		cout << "COTINUE(y/n)? ";
		cin >> y;

		if ( y == 'y' || y == 'Y')
			n++;
		else
			n--;
		cin.ignore(1000, '\n');
	}
	
	return 0;
}
//-----------------------------
//name: RunReverse
//input: the phrase
//output: the phrase in reverse
//------------------------------

void RunReverse()
{
	STACK <char, 80> Reverse; Reverse.MakeStack();
	
	char c;
	cout<<"Enter a Sentence: ";
	//put phrase into a stack
	while(cin.get(c), c != '\n')
	{
		if (isalpha(c))
		{ 
			Reverse.PushStack(c);
		}
		if( c == ' ')
			Reverse.PushStack(c);
	}

	//pop it out and it shows reverse order
	cout << "In reverse order: ";
	char x;
	while(!Reverse.EmptyStack())
	{
		x = Reverse.PopStack();
		cout <<  x;
	}
	cout << endl;
		

}
//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 19 19:39:46 2012

//Enter a Sentence: Computer Science
//In reverse order: ecneicS retupmoC
//COTINUE(y/n)? y
//Enter a Sentence: A Toyota
//In reverse order: atoyoT A
//COTINUE(y/n)?