//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//HW03.cpp
//Credits: Lisa, Elliot

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//function proto
int GetMenuChoice(int& choice);
void ProcessUser(int ids[], string names[], double balances[], int choice, int& count);
void GetID(int &id);
void AddUser(int ids[], string names[], double balances[], int& count);
void GetName( string &name);
void PrintAll(int ids[], string names[], double balances[], int count);
void DisplayMenu();
void SearchUser(int ids[], string names[], double balances[], int choice, int count);
void GetBalance(double &balance);

const int MAX = 50;
enum{ADD = 1, SEARCH, PRINT, QUIT};

//Function Name: main
//Purpose: To call menu choice, and readfile, and writefile
//Return type: int
//Input parameters: none 
//Output paramters: none
//User inputs: none
//User outputs: none
//Functions called: GetMenuChoice(), ReadFile(), WriteFile()
//Error messages: none


int main()
{
	int ids[MAX], count = 0, choice;
	string names[MAX];
	double balances[MAX];

	while( ( choice = GetMenuChoice(choice) ) !=QUIT)
		ProcessUser(ids, names, balances, choice, count);
	if ( choice == QUIT)
	return 0;
}

//Function Name: GetMenuChoice
//Purpose: to print menu and ask for choice
//Return type: int
//Input parameters: choice 
//Output paramters: choice
//User inputs: choice
//User outputs: none
//Functions called: none
//Error messages: none

int GetMenuChoice(int& choice)
{
	DisplayMenu();
	cout << setw(13) << left << "Enter 1-4 : ";
	cin >> choice;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;

	return choice;
}

//Function Name: DisplayMenu
//Purpose: to display the menu
//Return type: void
//Input parameters: none 
//Output paramters:none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void DisplayMenu()
{
	cout << setw(40) << left << "MENU" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "1. Add User" << endl;
	cout << setw(40) << left << "2. Search by ID" << endl;
	cout << setw(40) << left << "3. Print All" << endl;
	cout << setw(40) << left << "4. Exit" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
}

//Function Name: ProcessUser
//Purpose: void
//Return type: none
//Input parameters: ids, names, choice, count 
//Output paramters: ids, names, count
//User inputs: none
//User outputs: none
//Functions called: AddUsers, PrintAll
//Error messages: none

void ProcessUser(int ids[], string names[], double balances[], int choice, int& count)
{
	if (choice == ADD)
		AddUser(ids, names, balances, count);
	else if (choice == SEARCH)
		SearchUser(ids, names, balances, choice, count);
	else if (choice == PRINT)
		PrintAll(ids, names, balances, count);
}

//Function Name: SearchUser
//Purpose: to search for already inputted users by ID, and print their information
//Return type: void
//Input parameters: ids, names, balances, choice, count
//Output paramters: none
//User inputs: ids[]
//User outputs: names, balances
//Functions called: none
//Error messages: Customer ID "" not found

void SearchUser(int ids[], string names[], double balances[], int choice, int count)
{
	int search;
	bool valid;

	cout << setw(4) << left << "ID: " ;
	
	do
		{
			cin >> search;

				if(cin.fail())
			{
				cout << "Invalid ID" << endl;
				cin.clear();
			}

			if (search < 1)
			{
				cout << "Invalid ID" << endl;
				cout << "ID: ";
				valid = false;
			}
			else
			{
				valid = true;
			}
			cin.ignore(1000, '\n');
			}while(!valid);

	for (int i = 0; i < count; i++)
	{
		if (search == ids[i])
		{
			cout << "Found Customers for ID " << search << endl; 
			cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
			cout << setw(10) << left << "ID" << setw(19) << left << "Name" << setw(11) << right << "Balance" << endl;
			cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
			cout << setw(10) << left << ids[i] << setw(19) << left << names[i] << setw(4) << left << "$" << setw(10) << fixed << setprecision(2) << balances[i] << endl;
			cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
		}
		else if ( i == (count - 1) )
			cout << "Customer ID " << search << " not found" <<  endl; 
	}
}

//Function Name: AddUser
//Purpose: to get the ID and name for an additional user
//Return type: void
//Input parameters: ids, names, balances, count 
//Output paramters: ids, names, balances, count
//User inputs: none
//User outputs: none
//Functions called: GetID, GetName, GetBalance
//Error messages: none

void AddUser(int ids[], string names[], double balances[], int& count)
{

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "ADD USER" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	GetID(ids[count]);
	GetName(names[count]);
	GetBalance(balances[count]);
	count++;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}

//Function Name: GetBalance
//Purpose: to get the users account balance
//Return type: void
//Input parameters: balance 
//Output paramters: none
//User inputs: balance
//User outputs: none
//Functions called: none
//Error messages: Invalid Balance

void GetBalance(double& balance)
{
	bool valid;
	cout << setw(4) << left << "Balance: ";
	
	do
	{
		cin >> balance;

		if(cin.fail())
		{
			cout << "Invalid Balance" << endl;
			cin.clear();
		}
		if (balance < 1)
		{
			cout << "Invalid Balance" << endl;
			cout << "Balance: ";
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);

}

//Function Name: GetID
//Purpose: to get the ID
//Return type:  void
//Input parameters: id
//Output paramters: id
//User inputs: id
//User outputs: none
//Functions called: none
//Error messages: none

void GetID(int& id)
{
	bool valid;
	cout << setw(4) << left << "ID: " ;
	
	do
	{
		cin >> id;

		if(cin.fail())
		{
			cout << "Invalid ID" << endl;
			cin.clear();
		}
		if (id < 1)
		{
			cout << "Invalid ID" << endl;
			cout << "ID: ";
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);

}

//Function Name: GetName
//Purpose: Get the Name
//Return type: void
//Input parameters: names 
//Output paramters: names
//User inputs: names
//User outputs: none
//Functions called: none
//Error messages: none

void GetName( string& names)
{
	bool valid;
	cout << setw(6) << left << "Name:" ;
	
		getline(cin, names);
		

}

//Function Name: PrintAll
//Purpose: to Print all the names and ids
//Return type: void
//Input parameters:  
//Output paramters:
//User inputs:
//User outputs:
//Functions called:
//Error messages:

void PrintAll(int ids[], string names[], double balances[], int count)
{

	cout << setw(40) << left << "Fullerton Bank" << endl;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(10) << left << "ID" << setw(19) << left << "Name" << setw(11) << right << "Balance" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
		
	for (int i = 0; i < count; i++)
	{
		cout << setw(10) << left << ids[i] << setw(19) << left << names[i] << setw(4) << left << "$" << setw(10) << fixed << setprecision(2) << balances[i] << endl;
	}

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}