//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallHW04.cpp
//Credits: Lisa, Elliot

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

struct Customer
{
	int ids;
	string names;
	double balances;
};

//function proto
int GetMenuChoice(int& choice);
void ProcessUser(Customer customers[], int choice, int& count);
void GetID(int &id);
void AddUser(Customer customers[], int& count);
void GetName( string &name);
void PrintAll(Customer customers[], int count);
void DisplayMenu();
void SearchUser(Customer customers[], int choice, int count);
void GetBalance(double &balance);
void ReadFile(Customer customers[], int& count);
void WriteFile(Customer customers[], int count);
void WrittenFile(ostream& out, Customer customers[], int count);

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
//Input parameters: ids, names, count 
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
//Input parameters: ids, names, count 
//Output paramters: none
//User inputs: none
//User outputs: none
//Functions called: WrittenFile
//Error messages: can't open file

void WriteFile(Customer customers[], int count)
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
//Input parameters:  ostream, ids, names, count
//Output paramters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void WrittenFile(ostream& out, Customer customers[], int count)
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
//Input parameters: ids, names, choice, count 
//Output paramters: ids, names, count
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
//Input parameters: ids, names, balances, choice, count
//Output paramters: none
//User inputs: ids[]
//User outputs: names, balances
//Functions called: none
//Error messages: Customer ID "" not found

void SearchUser(Customer customers[], int choice, int count)
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
			cout << setw(10) << left << customers[i].ids << setw(19) << left << customers[i].names << setw(4) << left << "$" << setw(10) << fixed << setprecision(2) << customers[i].balances << endl;
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
//Input parameters: ids, names, balances, count 
//Output paramters: ids, names, balances, count
//User inputs: none
//User outputs: none
//Functions called: GetID, GetName, GetBalance
//Error messages: none

void AddUser(Customer customers[], int& count)
{

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "ADD USER" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	GetID(customers[count].ids);
	GetName(customers[count].names);
	GetBalance(customers[count].balances);
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
	
	
	do
	{
		cout << setw(4) << left << "Balance: ";
		cin >> balance;

		if(cin.fail())
		{
			cout << "Invalid Balance" << endl;
			cin.clear();
			valid = false;
		}
		else if (balance < 1)
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

	
	do
	{
		cout << setw(4) << left << "ID: " ;
		cin >> id;

		if(cin.fail())
		{
			cout << "Invalid ID" << endl;
			cin.clear();
			valid = false;
		}
		else if (id < 1)
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

void PrintAll(Customer customers[], int count)
{

	cout << setw(40) << left << "Fullerton Bank" << endl;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(10) << left << "ID" << setw(19) << left << "Name" << setw(11) << right << "Balance" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
		
	for (int i = 0; i < count; i++)
	{
		cout << setw(10) << left << customers[i].ids << setw(19) << left << customers[i].names << setw(4) << left << "$" << setw(10) << fixed << setprecision(2) << customers[i].balances << endl;
	}

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}