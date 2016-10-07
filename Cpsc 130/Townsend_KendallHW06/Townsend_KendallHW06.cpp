//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallHW06.cpp
//Credits:

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
#include "customer.h"
using namespace std;


//function proto
int GetMenuChoice(int& choice);
void ProcessUser(Customer customers[], int choice, int& count);
void GetID(int &id);
void AddUser(Customer customers[], int& count);
string GetFirstName(string& firstname);
string GetLastName(string& lastname);
void GetName(Customer customers[], string firstname, string lastname, int count);
void PrintAll(Customer customers[], int count);
void DisplayMenu();
void SearchUser(const Customer customers[], int choice, int count);
void GetBalance(double &balance);
void ReadFile(Customer customers[], int& count);
void WriteFile(const Customer customers[], int count);
void WrittenFile(ostream& out, const Customer customers[], int count);


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
	int count = 0, choice;
	Customer customers[MAX];

	ReadFile(customers, count);

	while( ( choice = GetMenuChoice(choice) ) !=QUIT)
		ProcessUser(customers, choice, count);
	if ( choice == QUIT)
	{
		WriteFile(customers, count);
	}
}

//Function Name: ReadFile
//Purpose: to read a previous file
//Return type: void
//Input parameters: customers[], count 
//Output paramters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void ReadFile(Customer customers[], int& count)
{
	ifstream infile;
	infile.open("users.txt");

	if(!infile || !infile.is_open())
	{
		count = 0;
	}
	else
	{
		bool valid = true;
		while(!infile.eof() && valid)
		{
			infile >> customers[count].ids;
			infile >> customers[count].balances;
			getline(infile, customers[count].names);

			if(infile.fail())
			{
				valid = false;
			}
			else if(customers[count].ids <= 0 || customers[count].names == "")
			{
				valid = false;
			}
			else
			{
				count++;
			}
		}
	}

	infile.close();
}

//Function Name: WriteFile
//Purpose: Create a .txt file
//Return type: void
//Input parameters: customers[], count 
//Output paramters: none
//User inputs: none
//User outputs: none
//Functions called: WrittenFile
//Error messages: can't open file

void WriteFile(const Customer customers[], int count)
{
	ofstream outfile;
	string filename;
	filename = "users.txt";
	outfile.open(filename.c_str());
	if(outfile && outfile.is_open())
	{
		WrittenFile(outfile, customers, count);
	}
	else
	{
		cout << "can't open file" << endl;
	}
}

//Function Name: WrittenFile
//Purpose: to write to .txt file
//Return type:  void
//Input parameters:  ostream, customers[], count
//Output paramters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void WrittenFile(ostream& out, const Customer customers[], int count)
{

	for (int i = 0; i < count; i++)
	{
		out << customers[i].ids << " " <<  customers[i].balances << " " << customers[i].names << '\n';
	}


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
//Input parameters: customers[], choice, count 
//Output paramters: customers[], count
//User inputs: none
//User outputs: none
//Functions called: AddUsers, PrintAll
//Error messages: none

void ProcessUser(Customer customers[], int choice, int& count)
{
	if (choice == ADD)
		AddUser(customers, count);
	else if (choice == SEARCH)
		SearchUser(customers, choice, count);
	else if (choice == PRINT)
		PrintAll(customers, count);
}

//Function Name: SearchUser
//Purpose: to search for already inputted users by ID, and print their information
//Return type: void
//Input parameters: customers[], choice, count
//Output paramters: none
//User inputs: ids[]
//User outputs: names, balances
//Functions called: none
//Error messages: Customer ID "" not found

void SearchUser(const Customer customers[], int choice, int count)
{
	int search;
	bool valid;

	
	
	do
		{
			cout << setw(4) << left << "ID: " ;
			cin >> search;

				if(cin.fail())
			{
				cout << "Invalid ID" << endl;
				cin.clear();
				valid = false;
				}

			else if (search < 1)
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
	valid = false;
	for (int i = 0; i < count; i++)
	{
		if (search == customers[i].ids)
		{
			valid = true;
			cout << "Found Customers for ID " << search << endl; 
			cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
			cout << setw(10) << left << "ID" << setw(19) << left << "Name" << setw(11) << right << "Balance" << endl;
			cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
			cout << customers[i];
			cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
		}
	}
	if (valid == false)
	{
		cout << "Customer ID " << search << " not found" <<  endl; 
	}
}

//Function Name: AddUser
//Purpose: to get the ID and name for an additional user
//Return type: void
//Input parameters: customers, count 
//Output paramters: customers, count
//User inputs: none
//User outputs: none
//Functions called: GetID, GetName, GetBalance
//Error messages: none

void AddUser(Customer customers[], int& count)
{
	string firstname, lastname;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "ADD USER" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	for(int i = 0; i < count; i++)
	{
		cin >> customers[i];
	}
	count++;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}


//Function Name: PrintAll
//Purpose: to Print all the names and ids
//Return type: void
//Input parameters:  customers[], count
//Output paramters: none
//User inputs: none
//User outputs:none
//Functions called: none
//Error messages: none

void PrintAll(Customer customers[], int count)
{

	cout << setw(40) << left << "Fullerton Bank" << endl;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(10) << left << "ID" << setw(19) << left << "Name" << setw(11) << right << "Balance" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
		
	for (int i = 0; i < count; i++)
	{
		cout << customers[i];
	}

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}