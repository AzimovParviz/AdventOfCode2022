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
	switch (input[2]) {
		case 'X':
			totalPoints+=1;
			playerChoice = input[2];
			break;
		case 'Y':
			totalPoints+=2;
			playerChoice = input[2];
			break;
		case 'Z':
			totalPoints+=3;
			playerChoice = input[2];
			break;
		default:
			break;
	};
	
	switch (input[0]) {
		case 'A':
			totalPoints += resultOfRound(playerChoice-23, input[0]);
			break;
		case 'B':
			totalPoints += resultOfRound(playerChoice-23, input[0]);
			break;
		case 'C':	
			totalPoints += resultOfRound(playerChoice-23, input[0]);
			break;
		default:
			break;
	}

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
	int points = getPoints();
	std::cout<<points;
	return 0;
}
