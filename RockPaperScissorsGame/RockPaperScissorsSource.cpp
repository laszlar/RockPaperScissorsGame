//Rock Paper Scissors Game!	

#include <iostream>												//preprocessor directive
#include <iomanip>												//preprocessor directive
#include <string>												//preprocessor directive
#include <ctime>												//preprocessor directive
#include <cstdlib>												//preprocessor directive

using namespace std;											//I know I shouldn't be using this.

void Rock(int &uInput, int &uScore, int &cScore);				//declaring function accepts user input, user score, and computer score
void Scissors(int &uInput, int &uScore, int &cScore);			//declaring function accepts user input, user score, and computer score
void Paper(int &uInput, int &uScore, int &cScore);				//declaring function accepts user input, user score, and computer score

int main()														//start function
{
	unsigned seed = time(0);									//passing time to seed value
	const int minValue = 1;										//constant variable of 1 as minimum value
	const int maxValue = 3;										//constant variable of 3 as maximum value
	int userInput, compInput;									//integer for userinput and computer input
	int userScore = 0;											//initialize user score as 0
	int compScore = 0;											//initialize computer score as 0
	char userChoice;											//character variable for restarting program

	srand(seed);												//seeding the random number generator

	do
	{
		compInput = (rand() % (maxValue - minValue + 1)) + minValue;		//assigning the random number between 1 - 3 to compInput variable

		cout << "Rock Paper Scissors Game!";								//string
		cout << "\nYou know the drill, Rock beats scissors,\n";				//string
		cout << "Paper beats rock, Scissors beats paper!\n\n";				//string

		cout << "1. Rock\n";												//string
		cout << "2. Paper\n";												//string
		cout << "3. Scissors\n";											//string
		cout << "Enter your choice! <1, 2, 3> ";							//string
		cin >> userInput;													//user input of choice

		while (userInput <= 0 || userInput >= 4)							//prevents user from inserting anything other than 1 - 3
		{
			cout << "Please enter a correct choice!";						//string
			cin >> userInput;												//correct user input
		}

		if (compInput == 1)													//if compInput is 1
		{
			Rock(userInput, userScore, compScore);							//call Rock function, computer chose rock
		}
		else if (compInput == 2)											//if compInput is 2
		{
			Paper(userInput, userScore, compScore);							//call Paper function, computer chose paper
		}
		else if (compInput == 3)											//if compInput is 3
		{
			Scissors(userInput, userScore, compScore);						//call Scissors function, computer chose scissors
		}
		
		cout << "User: " << setw(4) << "" << userScore << " wins\n";		//string, and show user score
		cout << "Computer: " << compScore << " wins\n";						//string, and show computer score

		cout << "Would you like to play again? <Y or N> ";					//string
		cin >> userChoice;													//user input of play again?
	} while (userChoice == 'Y' || userChoice == 'y');						//re run program if user inputs Y or y
}

void Rock(int &uInput, int &uScore, int &cScore)							//Rock function
{
	cout << "\nComputer chooses rock!\n";									//string

	if (uInput == 1)														//if user input of 1
	{
		cout << "Tie Game!\n";												//string
	}
	else if (uInput == 2)													//if user input of 2
	{
		cout << "You win!\n";												//string
		uScore++;															//add to user score variable
	}
	else if (uInput == 3)													//if user input of 3
	{
		cout << "You lose!\n";												//string
		cScore++;															//add to computer score
	}
}

void Paper(int &uInput, int &uScore, int &cScore)							//Paper function
{
	cout << "\nComputer chooses paper!\n";									//string

	if (uInput == 1)														//if user input of 1
	{
		cout << "You lose!\n";												//string
		cScore++;															//add to computer score
	}
	else if (uInput == 2)													//if user input is 2
	{
		cout << "Tie Game!\n";												//string
	}	
	else if (uInput == 3)													//if user input is 3
	{
		cout << "You Win!\n";												//string
		uScore++;															//add to user score
	}
}

void Scissors(int &uInput, int &uScore, int &cScore)						//Scissors function
{
	cout << "\nComputer chooses scissors!\n";								//string

	if (uInput == 1)														//if user input is 1
	{
		cout << "You Win!\n";												//string
		uScore++;															//add to user score
	}
	else if (uInput == 2)													//if user input is 2
	{
		cout << "You Lose!\n";												//string
		cScore++;															//add to computer score
	}
	else if (uInput == 3)													//if user input is 3
	{
		cout << "Tie Game!\n";												//string
	}
}