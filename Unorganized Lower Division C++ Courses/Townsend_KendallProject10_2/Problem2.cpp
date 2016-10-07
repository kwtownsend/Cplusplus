//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.10/Problem 2:Problem2.cpp
//Due Date	November 15, 2012
//Professor	Ahmadnia
//
//Read from a .txt file and be able to modify balances
//--------------------------------------------------------------------------

#include <iostream>
#include "BST.h"

#include <fstream>
#include <ctime>
#include <string>
using namespace std;

enum{ DISPLAY = 1, SEARCH, DEPOSIT, WITHDRAW, QUIT};
//function prototype
void Copy(string filename, BST& a);
int GetMenuChoice(int& choice);
void DisplayMenu();

int main()
{
	//print the current time
	time_t b;
	time(&b);
	cout << "Today is " << ctime(&b) << endl;

	BST a;
	
	int choice;

	// read fro data.txt
	Copy("data.txt", a);

	//run enum menu
	while( ( choice = GetMenuChoice(choice) ) !=QUIT)
	{
	if(choice == DISPLAY)
	{
		//header for answer
		cout << setw(10) << left << "ID"
			<< setw(10) << left << "Name"
			<<setw(10) << left << "Balance" << endl;
		a.display();
	}
	if(choice == SEARCH)
	{
		int search;
		cout << "Enter your ID Number: ";
		cin >> search;

		//header for answer
		cout << setw(10) << left << "ID"
			<< setw(10) << left << "Name"
			<<setw(10) << left << "Balance" << endl;

		//search for ID
		a.SearchID(search);
		cout << endl;
	}
	if(choice == DEPOSIT)
	{
		int depositid;
		float deposit;
		cout << "Enter your ID Number: ";
		// get id
		cin >> depositid;
		// how much would you like to deposit
		cout << endl << "How much would you like to deposit ";
		cin >> deposit;

		a.deposit(depositid, deposit);
		cout << endl;
	}
	if(choice == WITHDRAW)
	{
		int withdrawid;
		float withdraw;

		//withdraw id number
		cout << "Enter your ID Number: ";
		cin >> withdrawid;
		//amount to withdraw
		cout << endl << "How much would you like to withdraw: ";
		cin >> withdraw;

		a.withdraw(withdrawid, withdraw);
		cout << endl;
	}
	}

	return 0;
}
//create menu choices
int GetMenuChoice(int& choice)
{
	DisplayMenu();
	cout << setw(13) << left << "Enter 1-5 : ";
	cin >> choice;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;

	return choice;
}
//display menu
void DisplayMenu()
{
	cout << setw(40) << left << "MENU" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "1. Display all records sorted by their ID number" << endl;
	cout << setw(40) << left << "2. Display the name and balance of a person whose ID is given" << endl;
	cout << setw(40) << left << "3. Deposit into account with a given ID" << endl;
	cout << setw(40) << left << "4. Withdraw from an account with a given ID" << endl;
	cout << setw(40) << left << "5. Quit" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
}

// read from data.txt
void Copy(string filename, BST& a)
{
	int ID;
	float balance;
	string name;
	ifstream f;
	f.open("data.txt");
	for(int i = 0; i < 5; i++)
	{
		f >> ID;
		f >> balance;
		f >> name;
		a.insert(ID, name, balance);
	}
	f.close();
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Nov 14 21:35:05 2012

//MENU

//---------------------------------------
//1. Display all records sorted by their ID number
//2. Display the name and balance of a person whose ID is given
//3. Deposit into account with a given ID
//4. Withdraw from an account with a given ID
//5. Quit

//---------------------------------------
//Enter 1-5 :  1

//=======================================
//ID        Name      Balance
//10        Tom       120.1
//20        Bill      130
//30        John      14.14
//40        Mary      222.22
//50        Joann     1000
//MENU

//---------------------------------------
//1. Display all records sorted by their ID number
//2. Display the name and balance of a person whose ID is given
//3. Deposit into account with a given ID
//4. Withdraw from an account with a given ID
//5. Quit

//---------------------------------------
//Enter 1-5 :  2

//=======================================
//Enter your ID Number: 10
//ID        Name      Balance
//10        Tom       120.1
//MENU

//---------------------------------------
//1. Display all records sorted by their ID number
//2. Display the name and balance of a person whose ID is given
//3. Deposit into account with a given ID
//4. Withdraw from an account with a given ID
//5. Quit

//---------------------------------------
//Enter 1-5 :  3

//=======================================
//Enter your ID Number: 30

//How much would you like to deposit 100
//Your balance now is 114.14
//MENU

//---------------------------------------
//1. Display all records sorted by their ID number
//2. Display the name and balance of a person whose ID is given
//3. Deposit into account with a given ID
//4. Withdraw from an account with a given ID
//5. Quit

//---------------------------------------
//Enter 1-5 :  4

//=======================================
//Enter your ID Number: 50

//How much would you like to withdraw: 100
//Your balance now is 900
//MENU

//---------------------------------------
//1. Display all records sorted by their ID number
//2. Display the name and balance of a person whose ID is given
//3. Deposit into account with a given ID
//4. Withdraw from an account with a given ID
//5. Quit

//---------------------------------------
//Enter 1-5 :  5

//=======================================
//Press any key to continue . . .