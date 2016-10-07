//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab07.cpp
//Credits: Lisa, Elliot

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//function proto
int GetMenuChoice(int& choice);
void ProcessUser(int ids[], string names[], int choice, int& count);
void GetID(int &id);
void AddUser(int ids[], string names[], int& count);
void GetName( string &name);
void PrintAll(int ids[], string names[], int count);
void ReadFile(int ids[], string names[], int& count);
void WriteFile(int ids[], string names[], int count);
void WrittenFile(ostream& out, int ids[], string names[], int count);
void DisplayMenu();

const int MAX = 50;
enum{ADD = 1, PRINT, QUIT};

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

	ReadFile(ids, names, count);

	while( ( choice = GetMenuChoice(choice) ) !=QUIT)
		ProcessUser(ids, names, choice, count);
	if ( choice == QUIT);
	{
		WriteFile(ids, names, count);
	}
	return 0;
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

void ReadFile(int ids[], string names[], int& count)
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
			infile >> ids[count];
			getline(infile, names[count]);
			
			if(infile.fail())
			{
				valid = false;
			}
			else if(ids[count] <= 0 || names[count] == "")
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

void WriteFile(int ids[], string names[], int count)
{
	ofstream outfile;
	string filename;
	filename = "users.txt";
	outfile.open(filename.c_str());
	if(outfile && outfile.is_open())
	{
		WrittenFile(outfile, ids, names, count);
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

void WrittenFile(ostream& out, int ids[], string names[], int count)
{

	for (int i = 0; i < count; i++)
	{
		out << ids[i] << " " <<  names[i] << '\n';
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
	cout << setw(13) << left << "Enter 1-3 : ";
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
	cout << setw(40) << left << "2. Print All" << endl;
	cout << setw(40) << left << "3. Exit" << endl;
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

void ProcessUser(int ids[], string names[], int choice, int& count)
{
	if (choice == ADD)
		AddUser(ids, names, count);
	else if (choice == PRINT)
		PrintAll(ids, names, count);
}

//Function Name: AddUser
//Purpose: to get the ID and name for an additional user
//Return type: void
//Input parameters: ids, names, count 
//Output paramters: ids, names, count
//User inputs: none
//User outputs: none
//Functions called: GetID, GetName
//Error messages: none

void AddUser(int ids[], string names[], int& count)
{

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "ADD USER" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	GetID(ids[count]);
	GetName(names[count]);
	count++;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
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

void PrintAll(int ids[], string names[], int count)
{

	cout << setw(40) << left << "PRINT ALL" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;

	for (int i = 0; i < count; i++)
	{
		cout << setw(8) << left << ids[i] << setw(42) << names[i] << endl;
	}
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}