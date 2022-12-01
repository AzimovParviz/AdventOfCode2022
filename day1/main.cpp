#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> getCalories() {
	std::string input;
	int i = 0;//will be used for identifcation of elfs
	std::vector<int> calories;
	calories.push_back(0);
	while (std::getline(std::cin, input, '\n')) {
		if(input.empty()) {
			i++;
			calories.push_back(0);
		}
		else
			calories[i] += std::stoi(input);
	}

	return calories;
}

int main() {
	std::vector<int> listOfElves = getCalories();
	std::sort(listOfElves.begin(), listOfElves.end(), std::greater<int>());
	std::cout<<"Most calories: "<<listOfElves[0];
	std::cout<<"Top 3 calories: "<<listOfElves[0]+listOfElves[1]+listOfElves[2];
	return 0;
}
