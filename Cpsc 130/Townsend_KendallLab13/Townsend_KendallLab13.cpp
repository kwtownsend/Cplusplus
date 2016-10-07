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
#include "StudentTutors.h"

using namespace std;

#define SMAX 2

//function prototype
void GetStudentInfo(Student* students);
void GetStudentInfo(Student*& s);
void GetInfo(Student* students[]);
void Getfirstname(string& firstname);
void Getlastname(string& lastname);
void GetScore(double& score);
void PrintStudents(const Student* students[]);
int CheckTutor();

int main()
{
	Student* students[SMAX] = { 0 };

	GetInfo(students);
	PrintStudents(students);



	return 0;
}


void GetInfo(Student* students[])
{
	for(int i = 0; i < SMAX; i++)
	{
		GetStudentInfo(students);
	}

}

void GetStudentInfo(Student*& s)
{
	int type = CheckTutor();
	if(type == 1)
	{
		s = new Student;
	}
	else
	{
		StudentTutors* t = new StudentTutors;
		double hours;
		cout << "Enter hours worked :";
		cin >> hours;

		t->SetHoursWorked(hours);
		s = t;
	}

	string name;
	Getfirstname(name);
	s->SetFirstName(name);
	Getlastname(name);
	s->SetLastName(name);
	//s->CheckTutor(name);
	for(int i = 0; i < MAX; i++)
	{
		double score;
		GetScore(score);
		s->SetScore(score, i);
	}
}

int CheckTutor()
{
	int type;
	cout << "What kind of Student? 1 for Student 2 for Tutor :";
	cin >> type;
	 return type;
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



void PrintStudents(const Student* students[])
{
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(20) << left << "Name" 
		<< setw(6) << left << "Total"
		<< setw(14) << right << "Average" << endl;
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;

	for(int i=0; i < size; i++)
	{

		/*cout << setw(20) << left << students[i].Fullname() 
			<< setw(6) << left << fixed << setprecision(2) << students[i].Total()
			<< setw(14) << right << fixed << setprecision(2) << students[i].Average() << endl;
			*/
		students[i]->Print();
	}
	cout << setw(41) << setfill('=') << '\n' << setfill(' ') << endl;

}