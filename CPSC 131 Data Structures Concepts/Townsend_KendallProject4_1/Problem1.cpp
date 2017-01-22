//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.4/Problem 1:Problem1.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//Take in a phrase and decide whether or not its a palindrome
//--------------------------------------------------------------------------

#include <iostream>
#include "STACK.h"
#include <ctime>

using namespace std;

//function prototype
void RunPalindrome();

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

		RunPalindrome();
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
//name: RunPalindrome
//input: the phrase or word
//output: Whether it is a palindrome or not
//------------------------------

void RunPalindrome()
{
	STACK <char, 80> LR; LR.MakeStack();
	STACK <char, 80> Temp; Temp.MakeStack();
	STACK <char, 80> RL; RL.MakeStack();
	
	char c;

	cout<<"Enter a Sentence: ";
	//put phrase into a stack, and a backup
	while(cin.get(c), c != '\n')
	{
		if (isalpha(c))
		{ 
			c = toupper(c);
			LR.PushStack(c);
			Temp.PushStack(c);
		}
	}
	//copy temp into RL in reverse order
	while(!Temp.EmptyStack())
	{
		c = Temp.PopStack();
		RL.PushStack(c);
	}
		
	int a, b;
	//Now check for palindrome
	while(!LR.EmptyStack())
	{
		a = LR.PopStack();
		b = RL.PopStack();
		if (a != b)
			break;
	}
	if (LR.EmptyStack())
		cout << "This statement is a Palindrome" << endl;
	else
	cout << "This statement is not a Palindrome" << endl;

}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 26 12:49:21 2012

//Enter a Sentence: sit ona potato pan otis
//This statement is a Palindrome
//COTINUE(y/n)? y
//Enter a Sentence: exam one is coming
//This statement is not a Palindrome
//COTINUE(y/n)? n
//Press any key to continue . . .