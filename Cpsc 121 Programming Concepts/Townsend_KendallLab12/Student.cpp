//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.cpp
//Credits: Nathan Niyomtham

#include "Student.h"
#include <iomanip>
#include <iostream>

using namespace std;

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

ostream& operator<< (ostream& out, const Student& obj)
{


		out << setw(20) << left << obj.Fullname() 
			<< setw(6) << left << fixed << setprecision(2) << obj.Total()
			<< setw(14) << right << fixed << setprecision(2) << obj.Average() << endl;
	return out;

}

istream& operator >> (istream& in, Student& obj)
{

	bool valid;
	
	cout << "Enter first :";
	in >> obj.firstname;

	
	cout << "Enter last :";
	in >> obj.lastname;

	for(int i = 0; i < MAX; i++)
	{
		cout << "Enter score :";
		do
	{
		in >> obj.scores[i];
		if(cin.fail())
		{
			cout << "Invalid Score" << endl;
			cin.clear();
			valid = false;
		}

		else if (obj.scores[i] < 1 || obj.scores[i] > 100)
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

	return in;

}

bool Student::operator==(const Student& obj)
{
   return (firstname == obj.firstname) &&
          (lastname  == obj.lastname)  &&
          (scores == obj.scores);
}

bool Student::operator<(const Student& obj)
{
   if(Fullname() < obj.Fullname())
      return true;
   else
      return false;
}

bool Student::operator>(const Student& obj)
{
   if(Fullname() > obj.Fullname())
      return true;
   else
      return false;
}