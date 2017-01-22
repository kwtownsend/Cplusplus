//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.6/Problem 3:Problem3.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//Take in names, and times for appointment and organize them
//--------------------------------------------------------------------------

#include <iostream>
#include "OrderedLL.h"
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

	OrderedLL wlist;
	OrderedLL newlist;
	string name; 
	int Time;
	int count = 0;
	//collect name and time
	while(count < 5)
	{
		
		cout << "Enter Name:";
		getline(cin, name);
		cout << "Enter Time: ";
		cin >> Time;

		wlist.insert(name, Time);
		newlist.Organize(name, Time);
		cin.ignore(1000, '\n');
			count++;
	}
	//display waitlist
	wlist.display();
	
	//display organized list
	cout << "New ";
	newlist.display();

	
	return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 17 19:41:03 2012

//Enter Name:Smith, Tina
//Enter Time: 5
//Enter Name:Adam, Joe
//Enter Time: 4
//Enter Name:Jones, Bill
//Enter Time: 6
//Enter Name:Coe, Ana
//Enter Time: 3
//Enter Name:Zhu, Yan
//Enter Time: 8
//Waiting List ->Smith, Tina /5-->Adam, Joe /4-->Jones, Bill /6-->Coe, Ana /3-->Zh
//u, Yan /8-->NULL
//New Waiting List ->Coe, Ana /3-->Adam, Joe /4-->Smith, Tina /5-->Jones, Bill /6-
//->Zhu, Yan /8-->NULL
//Press any key to continue . . .