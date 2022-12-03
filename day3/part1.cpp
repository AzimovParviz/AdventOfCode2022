#include <algorithm>
#include <iostream>
#include <string>

int calculatePriorities(char item)
{
	/*
	 * A-Z  65-90. A-Z 27-52 points
	 * a-z 97-122. a-z 1-26 points
	 */
	if(item >= 65 && item <= 90)
	{
		std::cout<<(int)item-38<<'\n';
		return (int)item-38;
	}
	else if (item >= 97 && item <= 122)
	{
		std::cout<<(int)item-96<<'\n';
		return (int)item-96;
	}
	else 
		return 0;
}

int getItems() 
{
	int priorities = 0;
	std::string input;
	char cursor;
	std::string firstHalf;
	std::string secondHalf;
	while(std::getline(std::cin, input, '\n'))
	{		
		firstHalf = input.substr(0, input.length()/2);
		secondHalf = input.substr(input.length()/2, input.length());
		//std:cout<<firstHalf<<' '<<secondHalf<<'\n';
		int finalIndex = firstHalf.length();
		int i = 0;
		while(i<firstHalf.length())
		{
			cursor = firstHalf[i];	
			if(secondHalf.find_first_of(cursor) != std::string::npos)
			{
				//std:cout<<cursor<<'\n';
				firstHalf.erase(std::remove(firstHalf.begin(), firstHalf.end(), cursor), firstHalf.end());
				priorities += calculatePriorities(cursor);		
				////std:cout<<priorities<<'\n';
			}
			i++;
		}
	}

	return priorities;

}

int main()
{
	std::cout<<getItems();
	return 0;
}
