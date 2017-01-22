//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.cpp
//Credits: Nathan Niyomtham

#include "Student.h"


Student::Student(void)
{
	for (int i = 0; i < MAX; i++)
		scores[i]=0;
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

string Student::Fullname()
{
	return lastname + ", " + firstname;
}

double Student::Total()
{
	double total = 0;
	for(int i=0; i< MAX; i++)
	{
		total += scores[i];
	}
	
	return total;
}

double Student::Average()
{
	return Total()/MAX;
}