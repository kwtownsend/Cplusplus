//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.7/Problem 1:Problem1.cpp
//Due Date	October 25, 2012
//Professor	Ahmadnia
//
//Find out whether a phrase is a palindrome or not
//--------------------------------------------------------------------------

#include <iostream>
#include "queuepk.h"
#include "stackpk.h"
#include <ctime>
#include <string>
using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	char y;
	char c;
	int n = 1;
	queuepk<char> q;
	stackpk<char> s;

//loop to enter main program
for(int i = 0; i < n; i++)
	{

		cout << "Enter a phrase: ";
		//put phrase into stack and queue
		while(cin.get(c), c != '\n')
		{
			if (isalpha(c))
			{	 
				c = toupper(c);
				q.pushq(c);
				s.pushs(c);
			}
		}
		//check for palindrome
		char c1, c2;
		while( !q.Emptyq() && !s.Emptys())
		{
			c1 = q.popq(); 
			c2 = s.pops();
			c1 = toupper(c1);
			c2 = toupper(c2);

		if( c1 != c2)
			break;
		}

		if(q.Emptyq() )
			cout << "Palindrome! " << endl;
		else
			cout << "Not a palindrome! " << endl;


		// whether or not to continue
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

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 24 21:10:33 2012

//Enter a phrase: A santa at Nasa
//Palindrome!
//COTINUE(y/n)? y
//Enter a phrase: Borrow or Rob
//Palindrome!
//COTINUE(y/n)? n
//Press any key to continue . . .