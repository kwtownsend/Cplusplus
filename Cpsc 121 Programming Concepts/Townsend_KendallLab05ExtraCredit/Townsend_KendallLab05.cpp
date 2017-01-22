//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab05.cpp
//Credits: Elliot

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

//function proto
void run();
void getStudentInfo(string& fullName, double scores[], int& count);
void getStudentName(string& fullName);
void getStudentScore(double scores[]);
void calculateScore(int& minIndex, int& maxIndex, double& mean, double scores[], char& grade, int count );
int calculateMin(double scores[], int count);
int calculateMaximum(double scores[], int count);
double calculateMean(double score[], int count);
char getGrade(double& mean, char& grade);
void print(int minIndex, int maxIndex, double mean, double score[], string fullName, char grade, int count);
void printScore(ostream& out, int minIndex, int maxIndex, double mean, double scores[], string fullName, char grade, int count);
bool moreStudent();
bool HaveMore();
int GetScores(double scores[], int& count);

const int MAX = 10;

//Function Name: main
//Purpose: to run the entire program
//Return type: int
//Input parameters: none 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: run(), morestudent()
//Error messages: none

int main()
{
	do
	{
		run();
	}
	while (moreStudent());

	return 0;
}



//Function Name:moreStudent
//Purpose: to loop if there is more student
//Return type: bool
//Input parameters: none 
//Output parameters: none
//User inputs:  moreStudent
//User outputs: none
//Functions called: none
//Error messages: none

bool moreStudent()
{
	bool valid;
	char moreStudent;
	bool again;

	do
	{
		cout << endl << "Do you have another student? (Y/N)" << endl;
		cin >> moreStudent;

		cin.ignore(); // prevents getline from taking left over characters

		moreStudent = toupper(moreStudent);
		
		if (moreStudent != 'Y' && moreStudent != 'N')
		{
			cout << "Invalid Answer" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	if (moreStudent == 'Y')
		again = true;
	else
		again = false;

	return again;
}

//Function Name:run()
//Purpose: to start the bulk of the program
//Return type: void
//Input parameters: none 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: getStudentInfo(), calculateScore(), print()
//Error messages: none

void run()
{
	double scores[MAX], mean;
	int  minIndex, maxIndex;
	int count = 0;
	char grade;
	string fullName;

	getStudentInfo(fullName, scores, count);
	calculateScore(minIndex, maxIndex, mean, scores, grade, count );
	print(minIndex, maxIndex, mean, scores, fullName, grade, count);
}



//Function Name: getStudentInfo()
//Purpose: to get name, and score
//Return type: void
//Input parameters: fullName, score[] 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: getStudentName(), getStudentScore()
//Error messages:  none

void getStudentInfo(string& fullName, double scores[], int& count)
{
	getStudentName(fullName);
	GetScores(scores, count);
}

//Function Name: GetScores()
//Purpose: to get the amount of scores that the user wants
//Return type: int
//Input parameters: scores[], count
//Output parameters: count
//User inputs: count
//User outputs: none
//Functions called: HaveMore()
//Error messages: none

int GetScores(double scores[], int& count)
{
	do
	{
		cout << "Score: ";
		cin >> scores[count++];
	} while (count < MAX && HaveMore());

	return count;
}

//Function Name: HaveMore()
//Purpose: to ask if the user has more test score
//Return type: bool
//Input parameters: none
//Output parameters: answer
//User inputs: answer
//User outputs: none
//Functions called: none
//Error messages: none

bool HaveMore()
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

//Function Name: getStudentName()
//Purpose: to get students full name
//Return type: void
//Input parameters: fullName 
//Output parameters: fullName
//User inputs: firstName, lastName
//User outputs: none
//Functions called: none
//Error messages: none

void getStudentName(string& fullName)
{
	string firstName, lastName;
		cout << "What is your first name?" << endl;
		cin >> firstName;
		
	


		cout << "What is your last name?" << endl;
		cin >> lastName;
		
		fullName = lastName + ", " + firstName;
}



//Function Name: calculateScore()
//Purpose: to get the maxindex, minindex, mean, and letter grade
//Return type: void
//Input parameters: minIndex, maxIndex, mean, scores[], grade 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: calculateMin(), calculateMaximum(), calculateMean(), getGrade()
//Error messages: none

void calculateScore(int& minIndex, int& maxIndex, double& mean, double scores[], char& grade, int count )
{
	minIndex = calculateMin(scores, count);
	maxIndex = calculateMaximum(scores, count);
	mean = calculateMean(scores, count);
	getGrade(mean, grade);
}

//Function Name:calculateMin()
//Purpose: to calculate minindex
//Return type: int
//Input parameters: scores[] 
//Output parameters: minIndex
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

int calculateMin(double scores[], int count)
{
	int minIndex = 0;

	for(int i = 1; i<count; i++)
	{
		if ( scores[i] < scores [minIndex])
			minIndex = i;
	}

	return minIndex;
}

//Function Name: calculateMaximum()
//Purpose: to get maxindex
//Return type: int
//Input parameters: scores[] 
//Output parameters: maxIndex
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

int calculateMaximum(double scores[], int count)
{
	int maxIndex = 0;

	for(int i = 1; i<count; i++)
	{
		if ( scores[i] > scores [maxIndex])
			maxIndex = i;
	}

	return maxIndex;
}

//Function Name: calculateMean()
//Purpose: to get mean
//Return type: double
//Input parameters: scores[]
//Output parameters: mean
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages:  noen

double calculateMean( double scores[], int count)
{
	double mean = 0;

	for (int i = 0; i < count; i++)
	{
		mean += scores[i];
	}

	mean = mean / count;

	return mean;
}

//Function Name:getGrade()
//Purpose: to get the letter grade
//Return type: char
//Input parameters: mean, grade 
//Output parameters: grade
//User inputs: none
//User outputs: none
//Functions called:none
//Error messages: none

char getGrade(double& mean, char& grade)
{
	if (mean <= 100 && mean >= 90)
		grade = 'A';
	else if (mean < 90 && mean >= 80)
		grade = 'B';
	else if (mean < 80 && mean >=70)
		grade = 'C';
	else if (mean < 70 && mean >= 60)
		grade = 'D';
	else
		grade = 'F';

	return grade;
}

//Function Name: print()
//Purpose: to print out the results in the w32 prompt, and into a .txt file
//Return type: void
//Input parameters: minIndex, maxIndex, mean, scores[], fullName, grade 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: printScore()
//Error messages: none

void print(int minIndex, int maxIndex, double mean, double scores[], string fullName, char grade, int count)
{
	printScore(cout, minIndex, maxIndex, mean, scores, fullName, grade, count);

	ofstream outfile;
	string filename;
	filename = fullName + " - Homework Grade.txt";
	outfile.open(filename.c_str());
	if(outfile && outfile.is_open())
	{
		printScore(outfile, minIndex, maxIndex, mean, scores, fullName, grade, count);
	}
	else
	{
		cout << "can't open file" << endl;
	}
}

//Function Name: printScore()
//Purpose: to print into .txt file
//Return type: void
//Input parameters: minIndex, maxIndex, mean, scores[], fullName, grade 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void printScore(ostream& out, int minIndex, int maxIndex, double mean, double scores[], string fullName, char grade, int count)
{
	out << setw(60) << left << "HOMEWORK" << endl;
	out << setw(60) << setfill('-') << '\n' << setfill(' ') << endl;
	out << setw(60) << left << fullName << endl;
	out << setw(60) << setfill('-') << '\n' << setfill(' ') << endl;
	for (int i = 0; i < count; i++)
		out << setw(6) << left << fixed << setprecision(2) << scores[i];
	out << endl << setw(60) << setfill('-') << '\n' << setfill(' ') << endl;
	out << setw(55) << left << "MAX" << setw(5) << fixed << setprecision(1) << scores[maxIndex] << endl;
	out << setw(55) << left << "MIN" << setw(5) << fixed << setprecision(1) << scores[minIndex] << endl;
	out << setw(55) << left << "MEAN" << setw(5) << fixed << setprecision(1) << mean << endl;
	out << setw(60) << setfill('-') << '\n' << setfill(' ') << endl;
	out << setw(58) << left << "GRADE" << setw(1) << grade << endl;
	out << setw(60) << setfill('-') << '\n' << setfill(' ') << endl;
}