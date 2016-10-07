#include "StudentTutors.h"
#include <iostream>
#include <iomanip>

using namespace std;

StudentTutors::StudentTutors(void)
{
	hoursWorked = 0;
}

void StudentTutors::SetHoursWorked(int hours)
{
	hoursWorked = hours;
}

int StudentTutors::GethoursWorked()
{
	return hoursWorked;
}

double StudentTutors::StudentTutorPay() const
{
	return (hoursWorked * WAGE);
}

StudentTutors::~StudentTutors(void)
{

}


void StudentTutors::Print() const
{
	cout << setw(20) << left << Fullname() 
			<< setw(6) << left << fixed << setprecision(2) << Total()
			<< setw(14) << right << fixed << setprecision(2) << Average() << StudentTutorPay() << endl;
		
}
