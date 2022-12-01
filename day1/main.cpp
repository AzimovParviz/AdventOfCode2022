#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Elf
{
	public:
		int calories = 0;
		int id;

		void addCalories(int foodItem){
			calories += foodItem;
		}
};

bool CompareCalories(const Elf & left, const Elf & right) {
	return left.calories > right.calories;
}

std::vector<Elf> getCalories() {
	std::string input;
	int i = 0;//will be used for identifcation of elfs
	std::vector<int> calories;
	std::vector<Elf> allElfs;
	Elf elf {0,i};
	allElfs.push_back(elf);
	while (std::getline(std::cin, input, '\n')) {
		if(input.empty()) {
			i++;
			allElfs.push_back(
					{0,i}
					);
		}
		else 
			allElfs[i].addCalories(std::stoi(input));
	}	

	return allElfs;
}

int main() {
	std::vector<Elf> listOfElves = getCalories();
	std::sort(listOfElves.begin(), listOfElves.end(), CompareCalories);
	std::cout<<"Most calories: "<<listOfElves[0].calories;
	return 0;
}
