#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::size_t replace_all(std::string& inout, std::string_view what, std::string_view with)
{
    std::size_t count{};
    for (std::string::size_type pos{};
         inout.npos != (pos = inout.find(what.data(), pos, what.length()));
         pos += with.length(), ++count) {
        inout.replace(pos, what.length(), with.data(), with.length());
    }
    return count;
}

std::vector<std::vector<char>> formatCrates(std::vector<std::vector<char>> crates, int numberOfStacks, int maxHeight)
{
	std::vector<std::vector<char>> formattedCrates;
	for (int i = 0; i<numberOfStacks; i++)
	{
		for (int j = 0; j<maxHeight*maxHeight; j+=2)
		{	
			if(crates[i][j] > '0')
				formattedCrates[i].push_back(crates[i][j]);
			else
				formattedCrates[i].push_back(' ');
			std::cout<<"formattedCrates: "<<formattedCrates[i][j]<<'\n';	
		}
	}
	return formattedCrates;
}

std::vector<std::vector<char>> executeInstructions(std::vector<std::vector<char>> crates, int numberOfStacks, std::vector<std::string> instructions)
{
	int howMany,from,to;
	char _;
	for(int i = 0; i<instructions.size();i++)
	{
		std::reverse(crates[i].begin(), crates[i].end());
		std::istringstream singleInstruction(instructions[i]);
		singleInstruction>>howMany>>_>>from>>_>>to;
		std::cout<<howMany<<from<<to;
		for (int j = 0; j < howMany;j++)
		{	
			crates[to-1].pop_back();
			crates[to-1].push_back(crates[from-1][j]);
			std::cout<<"from: "<<crates[from-1][j]<<" to: "<<crates[to-1][j]<<'\n';
			crates[from-1].pop_back();
		}
		
		std::cout<<"ended up as: "<<std::string (crates[i].begin(), crates[i].end())<<'\n';
	}

	return crates;
}

std::vector<std::vector<char>> getCrates()
{
	std::vector<std::string> crates;
	std::vector<std::vector<char>> formattedCrates(3);
	char singleCrate[3];
	std::string input;
	int numberOfStacks = 0;
	std::vector<std::string> instructions;
	char _;
	int iter = 0; //to mark last row of crates;
	while(std::getline(std::cin, input, '\n'))
	{	
		if(input.find(']') != std::string::npos)
		{
			replace_all(input, "[", "");
			replace_all(input, "]", "");
			replace_all(input, "    ", "  ");
			replace_all(input, "  ", "00");
			replace_all(input, " ", "0");
			//std::cout<<input<<'\n';
			//crates.push_back(input);
			std::istringstream sstream(input);
			sstream>>singleCrate[0]>>_>>singleCrate[1]>>_>>singleCrate[2];
			std::cout<<singleCrate[0]<<singleCrate[1]<<singleCrate[2]<<'\n';
			for (int i = 0; i<3; i++)
			{
				if(singleCrate[i] > '0')
					formattedCrates[i].push_back(singleCrate[i]);
				else
					break;			}
			iter++; //means we are still on crates, marking that as a last row
			     //if there are no more crates, the iter will keep the last row 
		}
		else if(input.find("   ") != std::string::npos)
		{	
			replace_all(input, " ", "");
			numberOfStacks = input[input.length()-1] - '0';
			std::cout<<numberOfStacks<<'\n';

		}
		else if(input[0] == 109)
		{	
			replace_all(input, "move", "");
			replace_all(input, "from", "-");
			replace_all(input, "to", "-");
			replace_all(input, " ", "");
			instructions.push_back(input);
		}	
	}

	std::cout<<"maxHeight: "<<iter<<'\n';
	//std::vector<std::vector<char>> newCrates = formatCrates(formattedCrates, numberOfStacks, iter);
	//return formattedCrates;

	return executeInstructions(formattedCrates, numberOfStacks, instructions);
}

int main()
{
	std::vector<std::vector<char>> crates = getCrates();
	for (int i = 0; i < 3; i++)
	{
		std::cout<<"result is: "<<crates[i].back()<<'\n';
	}
	return 0;
}
