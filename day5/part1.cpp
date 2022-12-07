#include <cstdio>
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

std::vector<std::string> formatCrates(std::vector<std::string> crates, int numberOfStacks, int maxHeight)
{
	std::vector<std::string> formattedCrates(numberOfStacks);
	for (int i = 0; i<numberOfStacks*2; i+=2)
	{
		for (int j = 0; j<maxHeight; j++)
		{	
			formattedCrates[i] += crates[j][i];
		}
		std::cout<<"formattedCrates: "<<formattedCrates[i]<<'\n';
	}

	return formattedCrates;
}

std::string executeInstructions(std::vector<std::string> crates, int numberOfStacks, std::vector<std::string> instructions)
{
	int howMany,from,to;
	char _;
	for(int i = 0; i<instructions.size();i++)
	{
		std::istringstream singleInstruction(instructions[i]);
		singleInstruction>>howMany>>_>>from>>_>>to;
		for (int j = 0; j < howMany;j++)
		{
			
		}
	}
	return crates[0];
}

std::vector<std::string> getCrates()
{
	std::vector<std::string> crates;
	char singleCrate;
	std::string input;
	int numberOfStacks = 0;
	std::vector<std::string> instructions;
	int iter = 0; //to mark last row of crates;
	while(std::getline(std::cin, input, '\n'))
	{	
		if(input.find(']') != std::string::npos)
		{
			replace_all(input, "[", "");
			replace_all(input, "]", "");
			replace_all(input, "    ", "  ");
			//replace_all(input, " ", "0");
			//replace_all(input, "    ", "  ");
			std::cout<<input<<'\n';
			crates.push_back(input);
			iter++; //means we are still on crates, marking that as a last row
			     //if there are no more crates, the iter will keep the last row 
		}
		if(input.find("   ") != std::string::npos)
		{	
			replace_all(input, " ", "");
			numberOfStacks = input[input.length()-1] - '0';
			std::cout<<numberOfStacks<<'\n';

		}
		if(input[0] == 109)
		{	
			replace_all(input, "move", "");
			replace_all(input, "from", "-");
			replace_all(input, "to", "-");
			replace_all(input, " ", "");
			instructions.push_back(input);
			//std::cout<<"instructions "+input<<'\n';
		}	
	}

	//std::cout<<"wow ok "<<formattedCrates[1]<<'\n';
	std::cout<<"maxHeight: "<<iter<<'\n';
	std::vector<std::string> formattedCrates = formatCrates(crates, numberOfStacks, iter);
	return formattedCrates;
	return crates;
}

int main()
{
	std::cout<<getCrates()[0];
	return 0;
}
