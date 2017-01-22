
//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.cpp
//Credits: Nathan Niyomtham

#include "Customer.h"
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

Customer::Customer(void)
{
	firstname = "";
	lastname = "";
}


void Customer::SetFirstName(string first)
{
	firstname = first;
}

string Customer::GetFirstName() const
{
	return firstname;
}
void Customer::SetBalance(double bal)
{
	balance = bal;
}

double Customer::GetBalance() const
{
	return balance;
}

int Customer::GetID() const
{
	return ids;
}


void Customer:: SetID(int id)
{
	ids = id;
}

void Customer::SetLastName(string last)
{
	lastname = last;
}

string Customer::GetLastName() const
{
	return lastname;
}



string Customer::GetFullName() const
{
	return fullname;
}

void Customer::SetFullName(string lastname, string firstname)
{
	fullname = lastname + ", " + firstname;

}



ostream& operator<< (ostream& out, const Customer& obj)
{

	out << setw(10) << left << obj.GetID() << setw(19) << left << obj.GetLastName() + ", " + obj.GetFirstName() << setw(4) << left << "$" << setw(10) << fixed << setprecision(2) << obj.GetBalance() << endl;
	return out;

}

istream& operator>> (istream& in, Customer& obj)
{
	bool valid;

	
	do
	{
		cout << setw(4) << left << "ID: " ;

		in >> obj.ids;

		if(cin.fail())
		{
			cout << "Invalid ID" << endl;
			cin.clear();
			valid = false;
		}
		else if (obj.ids < 1)
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

	cout << "Enter first :";
	in >> obj.firstname;

	
	cout << "Enter last :";
	in >> obj.lastname;

	do
	{
		cout << setw(4) << left << "Balance: ";
		in >> obj.balance;

		if(cin.fail())
		{
			cout << "Invalid Balance" << endl;
			cin.clear();
			valid = false;
		}
		else if (obj.balance < 1)
		{
			cout << "Invalid Balance" << endl;
			cout << "Balance: ";
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);
	

	return in;
}


bool Customer::operator==(const Customer& obj)
{
   return (firstname == obj.firstname) &&
          (lastname  == obj.lastname)  &&
          (balance == obj.balance) &&
		  (ids == obj.ids);
}

bool Customer::operator<(const Customer& obj)
{
   if(GetID() < obj.GetID())
      return true;
   else
      return false;
}

bool Customer::operator>(const Customer& obj)
{
   if(GetID() > obj.GetID())
      return true;
   else
      return false;
}

bool Customer::operator>=(const Customer& obj)
{
   if(GetID() > obj.GetID())
      return true;
   else
      return false;
}

bool Customer::operator<=(const Customer& obj)
{
   if(GetID() > obj.GetID())
      return true;
   else
      return false;
}

Customer::~Customer(void)
{
}
