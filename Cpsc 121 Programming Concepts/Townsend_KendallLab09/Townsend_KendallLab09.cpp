//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab09.cpp
//Credits: Nathan Niyomtham

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//function proto
void StringExercise();
void FixName(char fixName[]);
void Palindrome();
void CheckPalindrome(char name[]);
void PassbyPointer();
void CheckForFailure(int* a);
void GetPower(int x, int y, int* power);


int main()
{
	StringExercise();
	Palindrome();
	PassbyPointer();
}

void StringExercise()
{
	char firstName[21];
	char lastName[21];
	char fullName[43];
	char fixName[21];
	int len;

	cout << setw(35) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(35) << left <<  "C-String Exercise" << endl;
	cout << setw(35) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(12) << left << "First Name: ";
	cin >> firstName;
	cout << setw(11) << left << "Last Name: ";
	cin >> lastName;
	cout << setw(12) << left << "Full Name: ";
	
	FixName(firstName);
	FixName(lastName);
	
	strcpy(fullName, lastName);
	strcat(fullName, ", ");
	strcat(fullName, firstName);

	cout << setw(23) << left << fullName << endl;


}

void FixName(char fixName[])
{
	int len;
	len = strlen(fixName);

	fixName[0] = toupper(fixName[0]);

	for (int i=1; i<len; i++)
	{
		fixName[i] = tolower(fixName[i]);
	}
}

void Palindrome()
{
	char name[21];

	cout << setw(35) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(35) << left << "Palindrome" << endl;
	cout << setw(35) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(14) << "Enter String: ";
	cin >> name;

	CheckPalindrome(name);
	cout << setw(35) << setfill('=') << '\n' << setfill(' ') << endl;
}

void CheckPalindrome(char name[])
{
	int len;
	len = strlen(name);

	for (int i=0; i < len; i++)
	{
		name[i] = tolower(name[i]);

	}

	bool valid = true;
	for(int i=0, j = len-1; i < len && j >= 0; i++, j--)
	{
		
		if (name[i] != name[j])
			valid = false;

	}

	if ( valid == true)
		cout << "Yes,it's palindrome!" << endl;
	else if ( valid == false)
		cout << "No, it's not a palindrome!" << endl;

}


void PassbyPointer()
{
	int x, y, power, a;

	cout << setw(35) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(35) << left << "Pass by Pointer" << endl;
	cout << setw(35) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(9) << "Enter x: ";


	CheckForFailure(&x);
	cout << endl << setw(9) << "Enter y: ";


	CheckForFailure(&y);

	cout << setw(2) << right << "y" << endl;

	GetPower(x, y, &power);

	cout << setw(6) << left << "x" 
		<< setw(4) << left << "="
		<< power << endl;



}

void GetPower(int x, int y, int* power)
{
	*power = 1;
	for ( int i=0; i <= y; i++)
	{
		*power = *power * x;
	}
}

void CheckForFailure(int* a)
{
	bool valid;
	cin >> *a;

	if ( cin.fail())
	{
			valid = false;
			cin.clear();
	}
	else
	{
			valid = true;
	}

}
