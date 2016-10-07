//Kendall Townsend
//894121409


#include <iostream>

using namespace std;
//function prototype
int NumberofScores(int& amountofscores);
void EnterScores(int quizscores[], int amountofscores);
float CalculateAverage(int quizscores[], int amountofscores, float& average);

const int MAX = 100;


int main()
{
	int amountofscores;
	int quizscores[MAX];
	float average = 0;
	NumberofScores(amountofscores);
	EnterScores(quizscores, amountofscores);
	CalculateAverage(quizscores, amountofscores, average);
}

int NumberofScores(int& amountofscores)
{
	cout << "Please Enter the number of scores" << endl;
	cin >> amountofscores;
	if(amountofscores < 0 || amountofscores > 100)
	{
		cout << "Invalid Number" << endl;
		cout << "Please Enter the number of scores" << endl;
		cin >> amountofscores;
	}

	return amountofscores;
}

void EnterScores(int quizscores[], int amountofscores)
{
	cout << "Please enter the quiz scores" << endl;
	for(int i = 0; i < amountofscores; i++)
	{
		cin >> quizscores[i];
	}
}

float CalculateAverage(int quizscores[], int amountofscores, float& average)
{
	for(int i = 0; i < amountofscores; i++)
	{
		average += quizscores[i];
	}
	average = average / amountofscores;
	cout << "The average: " << average << endl;

	int belowaverage = 0;
	int aboveaverage = 0;

	for(int i =0; i < amountofscores; i++)
	{
		if( quizscores[i] < average)
			belowaverage++;
		else
			aboveaverage++;
	}

	cout << "The number of scores above average: " << aboveaverage << endl;
	cout << "The number of scores below average: " << belowaverage << endl;

	return average;
}