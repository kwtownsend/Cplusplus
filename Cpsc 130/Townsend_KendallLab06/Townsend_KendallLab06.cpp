//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab06.cpp
//Credits: 

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;


//function proto
void InitCount(int payBrackets[]);
void ComputeRanges(int payBrackets[]);
double GrossSales(double& sales);
double EmployeePay(double sales, double& pay);
bool MoreEmployee();
double EmployeePay(double sales, double& pay);
int PayToIndex(double pay);
void Print(int payBrackets[]);
void PrintSalary(ostream& out, int payBrackets[]);

const int MAX = 9;
const double paypercent = .09;
const int flatpay = 200;
int main()
{
	int payBrackets[MAX];

	InitCount(payBrackets);
	ComputeRanges(payBrackets);
	Print(payBrackets);



	return 0;
}

void InitCount(int payBrackets[])
{
	for ( int i = 0; i < MAX; i++)
		payBrackets[i] = 0;
}

void ComputeRanges(int payBrackets[])
{
	double sales, pay;
	int index;
	do
	{
		sales = GrossSales(sales);
		pay = EmployeePay(sales, pay);
		index = PayToIndex(pay);
		payBrackets[index]++;
	} while( MoreEmployee() );
}

double GrossSales(double& sales)
{
	bool valid;

	do
	{
		cout << "What is your Gross Sales: ";
		cin >> sales;

		if (sales < 0)
		{
			cout << "Invalid Answer" << endl;
			valid = false;
		}
		else
		{
		valid = true;
		}

		if ( cin.fail())
		{
			valid = false;
			cin.clear();
		}

		cin.ignore(1000, '\n');
	} while (!valid);

	return sales;
}

bool MoreEmployee()
{
	char answer;
	do
	{
		cout << "Do you have more? (Y or N): ";
		cin >> answer;
		answer = toupper(answer);
	}while ('Y' != answer && 'N' != answer);
	return ('Y' == answer);
}

double EmployeePay(double sales, double& pay)
{
	pay = (sales * paypercent) + flatpay;

	return pay;
}

int PayToIndex(double pay)
{

	if (pay < 300)
		return 0;
	else if (pay < 400)
		return 1;
	else if (pay < 500)
		return 2;
	else if (pay < 600)
		return 3;
	else if (pay < 700)
		return 4;
	else if (pay < 800)
		return 5;
	else if (pay < 900)
		return 6;
	else if (pay < 1000)
		return 7;
	else
		return 8;
}

void Print(int payBrackets[])
{
	PrintSalary(cout, payBrackets);

	ofstream outfile;
	string filename;
	filename = "employees range.txt";
	outfile.open(filename.c_str());
	if(outfile && outfile.is_open())
	{
		PrintSalary(outfile, payBrackets);
	}
	else
	{
		cout << "can't open file" << endl;
	}
}

void PrintSalary(ostream& out, int payBrackets[])
{
	out << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
	out << setw(25) << left << "Salary Range"
		<< setw(25) << right << "No. of Employees" << endl;
	out << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
	out << setw (47) << left << "$200 - $299" << setw(3) << payBrackets[0] << endl;
	out << setw (47) << left << "$300 - $399" << setw(3) << payBrackets[1] << endl;
	out << setw (47) << left << "$400 - $499" << setw(3) << payBrackets[2] << endl;
	out << setw (47) << left << "$500 - $599" << setw(3) << payBrackets[3] << endl;
	out << setw (47) << left << "$600 - $699" << setw(3) << payBrackets[4] << endl;
	out << setw (47) << left << "$700 - $799" << setw(3) << payBrackets[5] << endl;
	out << setw (47) << left << "$800 - $899" << setw(3) << payBrackets[6] << endl;
	out << setw (47) << left << "$900 - $999" << setw(3) << payBrackets[7] << endl;
	out << setw (47) << left << "$1000 and over" << setw(3) << payBrackets[8] << endl;
	out << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
}

