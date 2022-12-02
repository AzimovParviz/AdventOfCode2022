#include <iostream>
#include <string>
#include <vector>
//A for Rock, B for Paper, C for Scissors
//X for Rock, Y for Paper, Z for Scissors
//1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).
//

int resultOfRound(char player, char opponent)
{
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
	totalPoints += input[2]-87;
	playerChoice = input[2]-23;
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
