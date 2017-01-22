//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.11/Problem 1:Problem1.cpp
//Due Date	November 29, 2012
//Professor	Ahmadnia
//
//Read from a .txt file and be able to search for a month and output the days in it
//--------------------------------------------------------------------------

#include <iostream>
#include "Hashing.h"

#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//function protype
void Copy(string filename, HASH& h);

int main()
{
		//print the current time
	time_t b;
	time(&b);
	cout << "Today is " << ctime(&b) << endl;

	HASH h;
	string month;

	//read from txt file
	Copy("data.txt", h);
	
	//ask for month name and search for it
	cout << "Insert month name: ";
	cin  >> month;
	h.searchMonth(month);
}

//read from data.txt
void Copy(string filename, HASH& h)
{
	string month;
	int days;
	ifstream f;
	f.open("data.txt");
	for(int i = 0; i < 13; i++)
	{
		f >> month;
		f >> days;
		h.insert(month, days);
	}
	f.close();
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Nov 28 21:30:16 2012

//Insert month name: December
//The amount of days in December is 31
//Press any key to continue . . .