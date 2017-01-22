//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallHW05
//Credits:

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//function proto
int GetMenuChoice(int& choice);
void ProcessUser(int ids[], double productOne[], double productTwo[], double productThree[], int choice, int& count);
void GetID(int &id);
void AddUser(int ids[], double productOne[], double productTwo[], double productThree[], int& count);
void PrintAll(int ids[], double productOne[], double productTwo[], double productThree[], int count);
void DisplayMenu();
void GetProduct(double& product, int count);
void CheckForFailure(double& a);
void CheckForFailureInt(int& a);

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
	double productOne[MAX], productTwo[MAX], productThree[MAX];

	while( ( choice = GetMenuChoice(choice) ) !=QUIT)
		ProcessUser(ids, productOne, productTwo, productThree, choice, count);
	if ( choice == QUIT)
		cout << "Bye!" << endl;
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
	cout << setw(40) << left << "1. Enter Sales" << endl;
	cout << setw(40) << left << "2. Print All" << endl;
	cout << setw(40) << left << "3. Exit" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
}

//Function Name: ProcessUser
//Purpose: void
//Return type: none
//Input parameters: ids, productOne, productTwo, productThree, choice, count 
//Output paramters: ids, productOne, productTwo, productThree, count
//User inputs: none
//User outputs: none
//Functions called: AddUser, PrintAll
//Error messages: none

void ProcessUser(int ids[], double productOne[], double productTwo[], double productThree[], int choice, int& count)
{
	if (choice == ADD)
		AddUser(ids, productOne, productTwo, productThree, count);
	else if (choice == PRINT)
		PrintAll(ids, productOne, productTwo, productThree, count);
}

//Function Name: AddUser
//Purpose: to get the ID and name for an additional user
//Return type: void
//Input parameters: ids, productOne, productTwo, productThree, count 
//Output paramters: ids, productOne, productTwo, productThree, count
//User inputs: none
//User outputs: none
//Functions called: GetID, GetProduct
//Error messages: none

void AddUser(int ids[], double productOne[], double productTwo[], double productThree[], int& count)
{

	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(40) << left << "ADD USER" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
	GetID(ids[count]);
	GetProduct(productOne[count], count);
	GetProduct(productTwo[count], count);
	GetProduct(productThree[count], count);
	count++;
	cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
}

//Function Name: GetProduct
//Purpose: to get the users product net gross
//Return type: void
//Input parameters: product, count
//Output paramters: product
//User inputs: product
//User outputs: none
//Functions called: none
//Error messages: none

void GetProduct(double& product, int count)
{
	cout << setw(17) << left << "Sales of Product " << setw(1) << count+1 << setw(2) << left << ": ";
	CheckForFailure(product);
}

//Function Name: CheckForFailure
//Purpose: to prevent the program from crashing
//Return type:void
//Input parameters: a
//Output paramters: a
//User inputs: a
//User outputs: none
//Functions called: none
//Error messages: Invalid Product Sales

void CheckForFailure(double& a)
{
	bool valid;
		do
	{
		cin >> a;
		if(cin.fail())
		{
			cout << "Invalid Product Sales" << endl;
			cin.clear();
		}

		if (a < 1)
		{
			cout << "Invalid Product Sales" << endl;
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
//Purpose: to get the salesperson ID
//Return type:  void
//Input parameters: id
//Output paramters: id
//User inputs: id
//User outputs: none
//Functions called: none
//Error messages: none

void GetID(int& id)
{
	cout << setw(16) << left << "Salesperson ID: " ;
	
	CheckForFailureInt(id);
}

//Function Name: CheckForFailureInt
//Purpose: to check for failure so the program doesn't crash
//Return type: void
//Input parameters: a
//Output paramters: a
//User inputs: a
//User outputs: a
//Functions called: none
//Error messages: Invalid ID

void CheckForFailureInt(int& a)
{
	bool valid;
	do
	{
		cin >> a;
		if(cin.fail())
		{
			cout << "Invalid ID" << endl;
			cin.clear();
		}

		if (a < 1)
		{
			cout << "Invalid ID" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
		}while(!valid);
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

void PrintAll(int ids[], double productOne[], double productTwo[], double productThree[], int count)
{
	cout << setw(65) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(65) << left << "Print All" << endl;
	cout << setw(65) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(15) << left << "Product # "
		<< setw(1) << left << "|"
		<< setw(15) << right << "1"
		<< setw(1) << left << "|"
		<< setw(15) << right << "2"
		<< setw(1) << left << "|"
		<< setw(15) << right << "3"
		<< setw(1) << left << "|" << endl;
	cout << setw(65) << setfill('-') << '\n' << setfill(' ') << endl;
	for(int i = 0; i < count; i++)
	{
		cout << setw(12) << "Salesperson " << setw(1) << i+1 << setw(3) << right << "|"
			<< setw(15) << right << fixed << setprecision(2) << productOne[i] << setw(1) << "|"
			<< setw(15) << right << fixed << setprecision(2) << productTwo[i] << setw(1) << "|"
			<< setw(15) << right << fixed << setprecision(2) << productThree[i] << setw(1) << "|" << endl;
	}
	cout << setw(65) << setfill('=') << '\n' << setfill(' ') << endl;
}
