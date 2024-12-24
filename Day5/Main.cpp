#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

constexpr int MAX_NUMBERS = 100;

static int Part1(std::set<unsigned char> numbers[MAX_NUMBERS], std::vector<std::vector<unsigned char>> lists)
{
	// The result of part 1
	unsigned int result = 0;

	bool valid = true;

	// Loops through the lists
	// We need to find if each list is valid
	// If it is valid we add the middle number to the result
	for (auto& list : lists)
	{
		valid = true;

		// Loops through the list
		for (int first = 0; first < list.size(); first++)
		{
			for (int second = 0; second < first; second++)
			{
				// If the number is in the set
				if (numbers[list[second]].find(list[first]) != numbers[list[second]].end())
				{
					// The list is invalid
					// We dont need to check the rest of the list
					valid = false;
				}
			}
		}

		if (valid)
		{
			// Finds the middle number and adds it to the result
			result += list[list.size() / 2];
		}
	}

	return result;
}

static int Part2(std::set<unsigned char> numbers[MAX_NUMBERS], std::vector<std::vector<unsigned char>> lists)
{
	// The result of part 2
	unsigned int result = 0;

	bool valid = true;

	// Loops through the lists
	// We need to find if each list is valid
	// If it is valid we add the middle number to the result
	for (auto& list : lists)
	{
		valid = true;

		// Loops through the list
		for (int first = 0; first < list.size(); first++)
		{
			for (int second = 0; second < first; second++)
			{
				// If the number is in the set
				if (numbers[list[second]].find(list[first]) != numbers[list[second]].end())
				{
					// The list is invalid
					// We dont need to check the rest of the list
					valid = false;
				}
			}
		}

		if (valid == false)
		{
			std::vector<unsigned char> newList;

			// Loops through the list
			for (int i = 0; i < list.size(); i++)
			{
				bool inserted = false;

				for (int j = 0; j < newList.size(); j++)
				{
					if (numbers[list[i]].find(newList[j]) != numbers[list[i]].end() && inserted == false)
					{
						inserted = true;

						newList.insert(newList.begin() + j, list[i]);
					}
				}

				if (inserted == false)
				{
					// Puts the number at the start of the list
					newList.insert(newList.begin(), list[i]);
				}
			}

			for (int i = 0; i < newList.size(); i++)
			{
				std::cout << (int)newList[i] << " ";
			}

			std::cout << std::endl;

			result += newList[newList.size() / 2];
		}
	}

	return result;
}

int main()
{
	// Opens the pairs file
	std::ifstream pairsFile("Pairs_T.txt");

	// Array of numbers
	// Numbers are capped at 100 which is the maximum number of numbers
	std::set<unsigned char> numbers[MAX_NUMBERS];

	// Loops through the file
	std::string line;
	while (std::getline(pairsFile, line))
	{
		// Creates the two numbers
		unsigned char x;
		unsigned char y;

		// Reads the two numbers (sperated by |)
		std::string xStr = line.substr(0, line.find('|'));
		std::string yStr = line.substr(line.find('|') + 1);

		// Converts the two numbers to unsigned char
		x = std::stoi(xStr);
		y = std::stoi(yStr);

		// X must appear before Y
		// It doesnt have to appear but if it does it must appear before Y
		numbers[y].insert(x);
	}

	// Opens the list file
	std::ifstream listFile("Lists_T.txt");

	// Vector of the lists(vector of numbers)
	std::vector<std::vector<unsigned char>> lists;

	// Loops through the file
	while (std::getline(listFile, line))
	{
		// Creates the list
		std::vector<unsigned char> list;

		// Loops through the line
		int i = 0;
		while (i < line.size())
		{
			// Each number is 2 digits which allows for this dogey code
			char number = ((line[i] - '0') * 10) + (line[i + 1] - '0');
			list.push_back(number);

			i += 3;
		}

		// Adds the list to the lists
		lists.push_back(list);
	}

	// Prints the result of part 1
	std::cout << "Part 1: " << Part1(numbers, lists) << std::endl;

	// Prints the result of part 2
	std::cout << "Part 2: " << Part2(numbers, lists) << std::endl;
}
