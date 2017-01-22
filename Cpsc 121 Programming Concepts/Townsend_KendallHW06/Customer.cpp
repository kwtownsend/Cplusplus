//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.cpp
//Credits: Nathan Niyomtham

#include "Customer.h"
#include <iomanip>
#include <iostream>

using namespace std;


void Customer::SetFirstName(string first)
{
	firstname = first;
}

string Customer::GetFirstName()
{
	return firstname;
}
void Customer::SetBalance(double bal)
{
	balance = bal;
}

double Customer::GetBalance()
{
	return balance;
}

double Customer::Balance() const
{
	return balance;
}

int Customer::ID() const
{
	return ids;
}

void Customer::SetLastName(string last)
{
	lastname = last;
}

string Customer::GetLastName()
{
	return lastname;
}

int Customer::GetID()
{
	return ids;
}

void Customer:: SetID(int id)
{
	ids = id;
}

string Customer::Fullname() const
{
	return lastname + ", " + firstname;
}

void Customer::SearchID() const
{
	int search;
	bool valid;

	
	
	do
		{
			cout << setw(4) << left << "ID: " ;
			cin >> search;

				if(cin.fail())
			{
				cout << "Invalid ID" << endl;
				cin.clear();
				valid = false;
				}

			else if (search < 1)
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
	valid = false;
	for (int i = 0; i < count; i++)
	{
		if (search == obj.ids)
		{
			valid = true;
			cout << "Found Customers for ID " << search << endl; 
			cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
			cout << setw(10) << left << "ID" << setw(19) << left << "Name" << setw(11) << right << "Balance" << endl;
			cout << setw(40) << setfill('-') << '\n' << setfill(' ') << endl;
			cout << customers[i];
			cout << setw(40) << setfill('=') << '\n' << setfill(' ') << endl;
		}
	}
	if (valid == false)
	{
		cout << "Customer ID " << search << " not found" <<  endl; 
	}

}


ostream& operator<< (ostream& out, const Customer& obj)
{

	out << setw(10) << left << obj.ID() << setw(19) << left << obj.Fullname() << setw(4) << left << "$" << setw(10) << fixed << setprecision(2) << obj.Balance() << endl;
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
		cin >> obj.balance;

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
          (balance == obj.balance);
}

bool Customer::operator<(const Customer& obj)
{
   if(ID() < obj.ID())
      return true;
   else
      return false;
}

bool Customer::operator>(const Customer& obj)
{
   if(ID() > obj.ID())
      return true;
   else
      return false;
}

bool Customer::operator>=(const Customer& obj)
{
   if(ID() > obj.ID())
      return true;
   else
      return false;
}

bool Customer::operator<=(const Customer& obj)
{
   if(ID() > obj.ID())
      return true;
   else
      return false;
}

