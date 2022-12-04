#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


int getPoints() 
{
	std::string input;
	std::vector<std::string> assignments;
	int containedCount;
	std::string firstAssignment;
	std::string firstBegin;
	std::string firstEnd;
	std::string secondAssignment;
	std::string secondBegin;
	std::string secondEnd;
	while(std::getline(std::cin, input, '\n'))
	{			
		firstAssignment = input.substr(0, input.find(","));
		secondAssignment = input.substr(input.find(",")+1, input.length());
		firstBegin = firstAssignment.substr(0, firstAssignment.find("-"));
		firstEnd = firstAssignment.substr(firstAssignment.find("-")+1, firstAssignment.length());
		secondBegin = secondAssignment.substr(0, secondAssignment.find("-"));
		secondEnd = secondAssignment.substr(secondAssignment.find("-")+1, secondAssignment.length());
		//if beginning is less than the second's and the end is bigger than the second's
		std::cout<<firstAssignment<<" "<<secondAssignment<<'\n';
//		std::cout<<firstBegin<<' '<<secondBegin<<'\n';
//		std::cout<<firstEnd<<' '<<secondEnd<<'\n';
	
		if(
		   (std::stoi(firstBegin) <= std::stoi(secondBegin))
		   &&
		   (std::stoi(firstEnd) >= std::stoi(secondEnd))
		  )
		{
			std::cout<<secondAssignment<<" is fully contained by "<<firstAssignment<<'\n';
			containedCount++;
		}

		else if(
		   (std::stoi(firstBegin) >= std::stoi(secondBegin))
		   &&
		   (std::stoi(firstEnd) <= std::stoi(secondEnd))
		  )
		{
		//	std::cout<<firstAssignment<<" is fully contained by "<<secondAssignment<<'\n';
			containedCount++;
		}
		//assignments.push_back(input);
	}

	return containedCount;
}



int main()
{
	std::cout<<getPoints();
	return 0;
}
