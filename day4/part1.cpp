#include <algorithm>
#include <iostream>
#include <string>


int getPoints() 
{
	std::string input;
	int containedCount;
	std::string firstAssignment, firstBegin, firstEnd, secondAssignment, secondBegin, secondEnd;
	while(std::getline(std::cin, input, '\n'))
	{			
		firstAssignment = input.substr(0, input.find(","));
		secondAssignment = input.substr(input.find(",")+1, input.length());
		firstBegin = firstAssignment.substr(0, firstAssignment.find("-"));
		firstEnd = firstAssignment.substr(firstAssignment.find("-")+1, firstAssignment.length());
		secondBegin = secondAssignment.substr(0, secondAssignment.find("-"));
		secondEnd = secondAssignment.substr(secondAssignment.find("-")+1, secondAssignment.length());
		//if beginning is less than the second's and the end is bigger than the second's
		if(
		  ((std::stoi(firstBegin) <= std::stoi(secondBegin))
		  && (std::stoi(firstEnd) >= std::stoi(secondEnd))) 
		  
		  ||
		  (
		   (std::stoi(firstBegin) >= std::stoi(secondBegin))
		   &&
		   (std::stoi(firstEnd) <= std::stoi(secondEnd))
		  )
		  )
		{
			containedCount++;
		}

	}

	return containedCount;
}



int main()
{
	std::cout<<getPoints();
	return 0;
}
