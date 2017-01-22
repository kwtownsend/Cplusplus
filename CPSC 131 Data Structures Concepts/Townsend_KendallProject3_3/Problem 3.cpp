//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.3/Problem 3:Problem3.cpp
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
bool isvowel(char c);

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	STACK <char, 80> Upper; Upper.MakeStack();
	STACK <char, 80> Lower; Lower.MakeStack();
	STACK <char, 80> Vowel; Vowel.MakeStack();
	char c;
	cout << "Enter a sentence: ";

	//put them in their proper stack
	while(cin.get(c), c != '\n')
	{
		if (isupper(c))
		{ 
			Upper.PushStack(c);
		}
		if(islower(c))
		{
			Lower.PushStack(c);
		}
		if (isvowel(c))
		{
			Vowel.PushStack(c);
		}
	}

	//display them in their proper category
	char x;
	cout << "Uppercase Letters: ";
	while(!Upper.EmptyStack())
	{
		x = Upper.PopStack();
		cout <<  x << " ";
	}
	cout << endl;

	cout << "Lowercase Letters: ";
	while(!Lower.EmptyStack())
	{
		x = Lower.PopStack();
		cout <<  x << " ";
	}
	cout << endl;

	cout << "Vowels: ";
	while(!Vowel.EmptyStack())
	{
		x = Vowel.PopStack();
		cout <<  x << " ";
	}
	cout << endl;
}
//-----------------------------
//name: isvowel
//input: char c
//output: true if its vowel false if not
//------------------------------
bool isvowel(char c)
{
	tolower(c);
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	else
		return false;
}


//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 19 20:11:55 2012

//Enter a sentence: Thr Sep 13, 2012
//Uppercase Letters: S T
//Lowercase Letters: p e r h
//Vowels: e
//Press any key to continue . . .