#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int calculatePriorities(char item)
{
	/*
	 * A-Z  65-90. A-Z 27-52 points
	 * a-z 97-122. a-z 1-26 points
	 */
	if(item >= 65 && item <= 90)
	{
		return (int)item-38;
	}
	else if (item >= 97 && item <= 122)
	{
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
	std::vector<std::string> rucksacks;
	while(std::getline(std::cin, input, '\n'))
	{			
		rucksacks.push_back(input);
	}
	
	for (int i = 0; i < rucksacks.size(); i+=3)
	{
		for (int j = 0; j<rucksacks[i].length();j++)
		{
			cursor = rucksacks[i][j];
			if(rucksacks[i+1].find_first_of(cursor) != std::string::npos && rucksacks[i+2].find_first_of(cursor) != std::string::npos)
			{
				priorities += calculatePriorities(cursor);
				break;
			}
		}
	}
	return priorities;

}

int main()
{
	std::cout<<getItems();
	return 0;
}
