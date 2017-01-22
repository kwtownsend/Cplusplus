#pragma once
#include "student.h"

#define WAGE 10.75

class StudentTutors :
	public Student
{
public:
	int GethoursWorked();
	void SetHoursWorked(int hours);
	double StudentTutorPay() const;
	virtual void Print() const;

private:
	int hoursWorked;
};

