//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab11.cpp
//Credits: Nathan Niyomtham

#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

//function prototype
void GetStudentInfo(Student* students, int size);
void PrintStudents(const Student* students, int size);
int GetSize(int& size);
void GetStudentInfo(Student& s);
void GetInfo(Student students[], int size);
void Getfirstname(string& firstname);
void Getlastname(string& lastname);
void GetScore(double& score);
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
		GetStudentInfo(students[i]);
	}

}

void GetStudentInfo(Student& s)
{
	string name;
	Getfirstname(name);
	s.SetFirstName(name);
	Getlastname(name);
	s.SetLastName(name);
	for(int i = 0; i < MAX; i++)
	{
		double score;
		GetScore(score);
		s.SetScore(score, i);
	}
}

void Getfirstname(string& firstname)
{
	cout << "First Name: ";
	cin >> firstname;
}

void Getlastname(string& lastname)
{
	cout << "Last Name: ";
	cin >> lastname;
}



void GetScore(double& score)
{
	cout << "Students Score: ";
	bool valid;
		do
	{
		cin >> score;
		if(cin.fail())
		{
			cout << "Invalid Score" << endl;
			cin.clear();
			valid = false;
		}

		else if (score < 1 || score > 100)
		{
			cout << "Invalid Score" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);
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

		cout << setw(20) << left << students[i].Fullname() 
			<< setw(6) << left << fixed << setprecision(2) << students[i].Total()
			<< setw(14) << right << fixed << setprecision(2) << students[i].Average() << endl;

	}
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;

}