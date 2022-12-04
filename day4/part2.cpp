#include <algorithm>
#include <iostream>
#include <string>


int getPoints() 
{
	std::string input;
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
		if(
		  ((std::stoi(firstBegin) <= std::stoi(secondBegin))
		  && (std::stoi(firstEnd) >= std::stoi(secondEnd)))  
		  ||
		  (
		   (std::stoi(firstBegin) >= std::stoi(secondBegin))
		   && (std::stoi(firstEnd) <= std::stoi(secondEnd))
		  )

		  ||

		  (
		    (std::stoi(secondEnd) >= std::stoi(firstBegin))
		   && ((std::stoi(firstEnd) >= std::stoi(secondBegin)))
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
