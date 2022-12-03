#include <iostream>
#include <string>
#include <vector>
//A for Rock, B for Paper, C for Scissors
//X for Rock, Y for Paper, Z for Scissors
//1 for Rock, 2 for Paper, and 3 for Scissors) plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).
//

char findCorrectChoice(int result, char opponent)
{
	//A beats C
	//B beats A
	//C beats B
	//A = 65, B = 66, C = 67
	// look at part1.cpp for explanation of maths here
	if (result  ==  3) return opponent;
	else if (result == 0) {
		if (opponent == 65) {
			return opponent + 2;
		}
		else {
			return opponent - 1;
		}
	}
	else if (result == 6) {
		if (opponent == 67) {
			return opponent - 2;
		}
		else {
			return opponent + 1;
		}
	}
	else {
		return 0;
	}
}

int calculateTotalScore(std::string input)
{
	int totalPoints = 0;	
	totalPoints += (input[2] - (88))*3; // 0 for loss, 3 for draw, 6 for winning
					    // 88 is X = loss, 89 is Y = (89 -88)*3 = 3 points
					    // 90 is Z = win, (90-88)*3 = 6 points
	totalPoints += findCorrectChoice(totalPoints, input[0]) - 64;
	return totalPoints;
}

int getPoints() 
{
	int points = 0;
	std::string input;
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
