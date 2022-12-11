#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

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

std::vector<std::vector<char>> executeInstructions(int numberOfStacks, std::vector<std::string> instructions)
{
    std::vector<std::vector<char>> crates (9);
    /*
                    [L]     [H] [W]
                [J] [Z] [J] [Q] [Q]
[S]             [M] [C] [T] [F] [B]
[P]     [H]     [B] [D] [G] [B] [P]
[W]     [L] [D] [D] [J] [W] [T] [C]
[N] [T] [R] [T] [T] [T] [M] [M] [G]
[J] [S] [Q] [S] [Z] [W] [P] [G] [D]
[Z] [G] [V] [V] [Q] [M] [L] [N] [R]
1   2   3   4   5   6   7   8   9
     */
    crates[0] = {'Z','J','N','W','P','S'};
    crates[1] = {'G','S','T'};
    crates[2] = {'V','Q','R','L','H'};
    crates[3] = {'V','S','T','D'};
    crates[4] = {'Q','Z','T','D','B','M','J'};
    crates[5] = {'M', 'W', 'T', 'J', 'D', 'C', 'Z', 'L'};
    crates[6] = {'L','P','M','W','G','T','J'};
    crates[7] = {'N','G','M','T','B','F','Q','H'};
    crates[8] = {'R','D','G','C','P','B','Q','W'};
//    crates[0] = {'Z', 'N'};
//    crates[1] = {'M','C','D'};
//    crates[2] = {'P'};
	int howMany,from,to;
	char _;
	for(int i = 0; i<instructions.size();i++)
	{
		std::istringstream singleInstruction(instructions[i]);
		singleInstruction>>howMany>>_>>from>>_>>to;
		//std::cout<<howMany<<"-"<<from<<"-"<<to;
        crates[to-1].insert(crates[to-1].end(), crates[from-1].end()-howMany,crates[from-1].end());
		for (int j = 0; j < howMany;j++)
		{	
			//std::cout<<"from: "<<crates[from-1][j]<<" to: "<<crates[to-1][j]<<'\n';
//			crates[to-1].push_back(crates[from-1].back());
			crates[from-1].pop_back();
		}
		
		//std::cout<<"ended up as: "<<std::string (crates[i].begin(), crates[i].end())<<'\n';
	}

	return crates;
}

std::vector<std::vector<char>> getCrates()
{
	std::vector<std::string> crates;
	std::vector<std::vector<char>> formattedCrates(9);
	std::string input;
	std::vector<std::string> instructions;
    
    
	while(std::getline(std::cin, input, '\n'))
	{	
		if(input[0] == 109)
		{	
			replace_all(input, "move", "");
			replace_all(input, "from", "-");
			replace_all(input, "to", "-");
			replace_all(input, " ", "");
			instructions.push_back(input);
            //std::cout<<input<<'\n';
		}	
	}
	
	return executeInstructions(9, instructions);
}

int main()
{
	std::vector<std::vector<char>> crates = getCrates();
	for (int i = 0; i < 9; i++)
	{
		std::cout<<crates[i].back();
	}
	return 0;
}
