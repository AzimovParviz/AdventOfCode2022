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
	if (result  ==  3) return opponent;
	else if (result == 0) {
		if (opponent == 65) {
			return 67;
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
	char playerChoice;
	switch (input[2]) {
		case 'X':
			totalPoints+=0;
			break;
		case 'Y':
			totalPoints+=3;
			break;
		case 'Z':
			totalPoints+=6;
			break;
		default:
			break;
	};
	
	switch (findCorrectChoice(totalPoints, input[0])) {
		case 65:
			totalPoints += 1;
			break;
		case 66:
			totalPoints +=2;
			break;
		case 67:
			totalPoints +=3;
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
	std::cout<<getPoints();
	return 0;
}
