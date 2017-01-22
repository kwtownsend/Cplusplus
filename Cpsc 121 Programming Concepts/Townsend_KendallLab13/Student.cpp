//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.cpp
//Credits: Nathan Niyomtham

#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

Student::Student(void)
{
	InitScores();
}

void Student::InitScores()
{
	for(int i=0; i < MAX; i++)
		scores[i]= 0;
}

void Student::SetFirstName(string first)
{
	firstname = first;
}

string Student::GetFirstName()
{
	return firstname;
}

void Student::SetLastName(string last)
{
	lastname = last;
}

string Student::GetLastName()
{
	return lastname;
}

void Student::SetScore(double score, int i)
{
	if( i >= 0 || i < MAX)
	{
		scores[i] = score;
	}
}

string Student::Fullname() const
{
	return lastname + ", " + firstname;
}

double Student::Total() const
{
	double total = 0;
	for(int i=0; i< MAX; i++)
	{
		total += scores[i];
	}
	
	return total;
}

double Student::Average() const
{
	return Total()/MAX;
}

void Student::Print() const
{
	cout << setw(20) << left << Fullname() 
			<< setw(6) << left << fixed << setprecision(2) << Total()
			<< setw(14) << right << fixed << setprecision(2) << Average() << endl;
		
}