//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2012
//Townsend_KendallLab12.cpp
//Credits: Nathan Niyomtham, Elliot Cossaboom

#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

//function prototype
void PrintStudents(const Student* students, int size);
int GetSize(int& size);
void GetInfo(Student students[], int size);
void PrintStudents(const Student students[], int size);

int main()
{
	Student* students = 0;
	int size = GetSize(size);

	students = new Student[size];
	if(students != NULL)
	{
		GetInfo(students, size);
		PrintStudents(students, size);
		delete [] students;
		students = 0;
	}
	else
	{
		cout << "No memory" << endl;
	}

	return 0;
}

int GetSize(int& size)
{
	cout << "Please enter the number of Students: ";

	bool valid;

		do
	{
		cin >> size;
		if(cin.fail())
		{
			cout << "Invalid Size" << endl;
			cin.clear();
			valid = false;
		}

		else if (size < 2)
		{
			cout << "Invalid Size" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);

	return size;
}

void GetInfo(Student students[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cin >> students[i];
	}

}






void PrintStudents(const Student students[], int size)
{
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(20) << left << "Name" 
		<< setw(6) << left << "Total"
		<< setw(14) << right << "Average" << endl;
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;

	for(int i=0; i < size; i++)
	{

		cout << students[i];

	}
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;

}