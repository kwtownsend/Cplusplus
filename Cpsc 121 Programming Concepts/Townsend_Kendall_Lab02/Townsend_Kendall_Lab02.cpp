//Townsend, Kendall
// 894121409
//CPSC 121 Section 5
//Spring 2011
//Townsend_Kendall_Lab02.cpp
//Credits:

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Function name:main()
//Purpose: To Determine the distance from two points in longitude and latitude
//Return type: int
//Input parameters: none
//Output parameters: none
//User inputs:latitude1, longitude1, latitude2, longitude2
//User outputs:distance
//Functions called:
//Error Messages:

int main()
{
	//variable for runagain
	char runagain = 'y';

	double latitude1, longitude1, latitude2, longitude2, latitude1radian, longitude1radian, latitude2radian, longitude2radian, distance, pi, radius;
	bool valid;
	pi = 3.14159265;
	radius = 3,963.1676;
	// Get the Latitude for position one
		do
		{
		cout << "What is the Latitude of Position One?" << endl;
		cin >> latitude1;

		if (latitude1 > 90 || latitude1 < -90)
		{
			cout << "Invalid Latitude Please Enter Again" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		} 
	}while (!valid);

	// Get the longitude for position one
			do
			{
			cout << "What is the Longitude of Position One?" << endl;
			cin >> longitude1;

			if(longitude1 > 180 || longitude1 < -180)
			{
				cout << "Invalid Longitude Please Enter Again"<< endl;
				valid = false;
			}
			else
			{
				valid = true;
			}
		} while (!valid);

	// Get the Latitude for position two
		do
		{
			cout << "What is the Latitude of Position Two?" << endl;
			cin >> latitude2;

			if (latitude2 > 90 || latitude2 < -90)
			{
				cout << "Invalid Latitude Please Enter Again" << endl;
				valid = false;
			}
			else
			{
			valid = true;
			}
		}while (!valid);

	// Get the longitude for position two
	
		do
		{
			cout << "What is the Longitude of Position Two?" << endl;
			cin >> longitude2;

			if(longitude2 > 180 || longitude2 < -180)
			{
				cout << "Invalid Longitude Please Enter Again"<< endl;
				valid = false;
			}
			else
			{
				valid = true;
			}
		} while (!valid);


	//Turning latitude and longitude into radian for formula
		latitude1radian = latitude1 * (pi/180);
		longitude1radian = longitude1 * (pi/180);
		latitude2radian = latitude2 * (pi/180);
		longitude2radian = longitude2 * (pi/180);

	// Find the Distance Between Two points
		distance = acos(sin(latitude1radian)*sin(latitude2radian)+cos(latitude1radian)*cos(latitude2radian)*cos(longitude2radian-longitude1radian)) * radius;


	// Formatting
		cout << setw(65) << setfill('-') << '\n' << setfill(' ');

		cout << left << setw(10) << "Location" << " | " 
			 << setw(10) << "" << " A "  
			 << setw(10) << "" << " | "  
			 << setw(10) << "" << " B " 
			 << setw(10) << "" << " |" << endl; 

		cout << setw(64) << setfill('-') << "" << endl << setfill(' ');

		cout << right << setw(10) << "" << " | " 
			 << setw(10) << "Latitude" << " | "  
			 << setw(10) << "Longitude" << " | "  
			 << setw(10) << "Latitude" << " | " 
			 << setw(10) << "Longtidue" << " |" << endl; 

		cout << setw(65) << setfill('-') << '\n' << setfill(' ');

		cout << fixed << setprecision(5);

		cout << right << setw(10) << "" << " | " 
			 << setw(10) << latitude1 << " | "  
			 << setw(10) << longitude1 << " | "  
			 << setw(10) << latitude2 << " | " 
			 << setw(10) << longitude2 << " |" << endl; 

		cout << setw(65) << setfill('-') << '\n' << setfill(' ');

		cout << left << setw(10) << "Distance" << " | "
			 << right << distance << setw(45) << " | " << endl;


		cout << setw(65) << setfill('-') << '\n' << setfill(' ');

		
		cout << "Would you like to run again, enter y?";
		runagain = tolower(runagain);
		cin >> runagain;
		if(runagain != 'y')
		{
			return 0;
		}

		}