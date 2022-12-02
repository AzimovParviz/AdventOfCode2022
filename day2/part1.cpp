#include <iostream>
#include <string>
#include <vector>
//A for Rock, B for Paper, C for Scissors
//X for Rock, Y for Paper, Z for Scissors
//1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).
//

int resultOfRound(char player, char opponent)
{
	/*
	 * ASCII values for ABC is 65 66 67
	 * e.g A (65) and B (66). Rock loses to Paper, 65 - 66 = - 1. 
	 * C(67) and A (65). Scissors loses to Rock, 67 - 65 = 2.
	 */
	if (player==opponent) 
		return 3;	
	else if ((player - opponent == 1) || (player - opponent == -2))
		return 6;
	else if ((player - opponent == -1) || (player -opponent == 2))
		return 0;
	else
		return 0;
}

int calculateTotalScore(std::string input)
{
	int totalPoints = 0;
	char playerChoice;
	totalPoints += input[2]-87;//ascii for X is 88, Y is 89, Z is 90
				   //we get 1, 2, 3 points respectively for choosing X,Y,Z
	playerChoice = input[2]-23;
				   //we substract 23 to get A,B,C from X,Y,Z
	totalPoints += resultOfRound(playerChoice, input[0]);
	return totalPoints;
}

int getPoints() 
{
	int points = 0;
	std::string input;
	int i = 0;
	while(std::getline(std::cin, input, '\n'))
	{			
		points += calculateTotalScore(input);
	}

	return points;
}

int main()
{
	std::cout<<getPoints();
	return 0;
}
