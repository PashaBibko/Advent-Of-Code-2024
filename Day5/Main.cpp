#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Number
{
	std::vector<unsigned char> prerequisites;
	unsigned char ID;
};

int main()
{
	std::ifstream pairsFile("pairs.txt");
	Number numbers[100];

	std::string line;

	for (std::getline(pairsFile, line))
	{

	}
}
