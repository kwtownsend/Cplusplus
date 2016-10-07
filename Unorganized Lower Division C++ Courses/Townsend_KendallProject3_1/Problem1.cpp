//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.3/Problem 1:Problem1.cpp
//Due Date	September 20, 2012
//Professor	Ahmadnia
//
//Purpose to read a positive integer number and convert it to base 2, 8, and 16
//--------------------------------------------------------------------------

#include <iostream>
#include "STACK.h"
#include <ctime>

using namespace std;

//function prototype
void FindBaseTwo(int c);
void FindBaseEight(int c);
void FindBaseSixteen(int c);


int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	//to get the starting positive integer number
	int c;
	cout << "Enter a positive integer number: " << endl;
	cin >> c;

	//to find base 2
	FindBaseTwo(c);
	//to find base 8 
	FindBaseEight(c);
	//to find base 16
	FindBaseSixteen(c);
	return 0;
}

//-----------------------------
//name: FindBaseTwo
//input: the starting integer that it will find base two for
//output: the resulting numbers from base two
//------------------------------

void FindBaseTwo(int c)
{
	STACK <int, 20> Rem;
	//to intialize stack
	Rem.MakeStack();
	cout << c << " base 10 is ";
	while(c != 0)
	{
		//to find the remainder and the next digit
		Rem.PushStack(c % 2);
			c = c / 2;
	}

	int x;

	//to print the results
	while(!Rem.EmptyStack())
	{
		x = Rem.PopStack();
		if (x<=9) cout <<  x << " ";
		else switch (x)
		{
		case 10:cout << 'A';
			break;
		case 11: cout << 'B';
			break;
		case 12: cout << 'C';
			break;
		case 13: cout << 'D';
			break;
		case 14: cout << 'E';
			break;
		case 15: cout << 'F';
			break;
		case 16: cout << 'G';
			break;
		case 17: cout << 'H';
			break;
		case 18: cout << 'I';
			break;
		case 19: cout << 'J';
			break;
		case 20: cout << 'K';
			break;
		}
	}
	cout << "base 2" << endl;
}
//-----------------------------
//name: FindBaseEight
//input: the starting integer that it will find base eight for
//output: the resulting numbers from base eight
//------------------------------

void FindBaseEight(int c)
{
	STACK <int, 20> Rem;
	//to intialize stack
	Rem.MakeStack();
	cout << c << " base 10 is ";
	while(c != 0)
	{
		//to find the remainder and the next digit
		Rem.PushStack(c % 8);
			c = c / 8;
	}

	int x;

	//to print the results
	while(!Rem.EmptyStack())
	{
		x = Rem.PopStack();
		if (x<=9) cout <<  x << " ";
		else switch (x)
		{
		case 10:cout << 'A';
			break;
		case 11: cout << 'B';
			break;
		case 12: cout << 'C';
			break;
		case 13: cout << 'D';
			break;
		case 14: cout << 'E';
			break;
		case 15: cout << 'F';
			break;
		case 16: cout << 'G';
			break;
		case 17: cout << 'H';
			break;
		case 18: cout << 'I';
			break;
		case 19: cout << 'J';
			break;
		case 20: cout << 'K';
			break;
		}
	}
	cout << "base 8" << endl;
}
//-----------------------------
//name: FindBaseSixteen
//input: the starting integer that it will find base sixteen for
//output: the resulting numbers from base sixteen
//------------------------------
void FindBaseSixteen(int c)
{
STACK <int, 20> Rem;
	//to intialize stack
	Rem.MakeStack();
	cout << c << " base 10 is ";
	while(c != 0)
	{
		//to find the remainder and the next digit
		Rem.PushStack(c % 16);
			c = c / 16;
	}

	int x;

	//to print the results
	while(!Rem.EmptyStack())
	{
		x = Rem.PopStack();
		if (x<=9) cout <<  x << " ";
		else switch (x)
		{
		case 10:cout << 'A';
			break;
		case 11: cout << 'B';
			break;
		case 12: cout << 'C';
			break;
		case 13: cout << 'D';
			break;
		case 14: cout << 'E';
			break;
		case 15: cout << 'F';
			break;
		case 16: cout << 'G';
			break;
		case 17: cout << 'H';
			break;
		case 18: cout << 'I';
			break;
		case 19: cout << 'J';
			break;
		case 20: cout << 'K';
			break;
		}
	}
	cout << "base 16" << endl;
}
//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Sep 19 18:04:41 2012

//Enter a positive integer number:
//162
//162 base 10 is 1 0 1 0 0 0 1 0 base 2
//162 base 10 is 2 4 2 base 8
//162 base 10 is A2 base 16
//Press any key to continue . . .