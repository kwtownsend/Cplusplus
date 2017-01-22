//Kendall Townsend
//894121409

#include <iostream>
#include "queue.h"
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//function protype
void Copy(string filename, queuepk &parts);
int GetMenuChoice(int& choice);
void DisplayMenu();
void Write(string filename, queuepk parts);

enum{ NEW = 1, FIND, DELETE, PRINT, QUIT};
int main()
{
	queuepk  parts;
	int choice;
	//Copy("textSave.txt", parts);

	//run enum menu
	while( ( choice = GetMenuChoice(choice) ) !=QUIT)
	{
		if(choice == NEW)
		{
			string a;
			int b;
			//header for answer
			cout << "Enter Parts number" << endl;
			cin >> b;
			cout << "Enter brief description" << endl;
			cin.ignore(1000, '\n');
			getline(cin, a);

			parts.pushq(a, b);
	}
		if(choice == FIND)
		{
			int search;
			cout << "Enter part ID Number: ";
			cin >> search;


			//search for ID
			parts.SearchPart(search);
			cout << endl;
		}

		if(choice == DELETE)
		{
			int deletepart;
			cout << "Enter Part number you want to delete: " << endl;
			cin >> deletepart;


			parts.popq(deletepart);
		}

		//cant get print all function to work properly without losing entire queue.
		if(choice == PRINT)
		{

			parts.DisplayAll();
		}
		

	}

		cout << "Will now save to textSave.txt" << endl;
		//Write("textSave.txt", parts);
	
	return 0;
}

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
	cout << setw(40) << left << "1. N: New part" << endl;
	cout << setw(40) << left << "2. F: Find part" << endl;
	cout << setw(40) << left << "3. D: Delete part" << endl;
	cout << setw(40) << left << "4. P: Print information" << endl;
	cout << setw(40) << left << "5. Q: Quit" << endl;
	cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
}


void Copy(string filename, queuepk &parts)
{
	int idnumber;
	string description;

	ifstream f;
	f.open("testSave.txt");
	for(int i = 0; i < 13; i++)
	{
		f >> description;
		f >> idnumber;
		parts.insert(description, idnumber);
	}
	f.close();
}

void Write(string filename, queuepk parts)
{
	int idnumber;
	string description;

	fstream f;
	f.open("testSave.txt");
	for(int i = 0; i < 13; i++)
	{
		f << description;
		f << idnumber;
		parts.insert(description, idnumber);
	}
	f.close();

}
