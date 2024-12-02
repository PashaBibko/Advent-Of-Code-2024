#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream file("Data.txt");
	std::string line;

	std::vector<int> lhs;
	std::vector<int> rhs;

	std::unordered_map<int, int> map;

	int total = 0;

	while (std::getline(file, line))
	{
		int pos = line.find(" ");
		lhs.push_back(std::stoi(line.substr(0, pos)));
		rhs.push_back(std::stoi(line.substr(pos + 1)));
	}

	std::sort(lhs.begin(), lhs.end());
	std::sort(rhs.begin(), rhs.end());

	for (int i = 0; i < rhs.size(); i++)
	{
		if (map.find(rhs[i]) == map.end())
		{
			map[rhs[i]] = 1;
		}

		else
		{
			map[rhs[i]]++;
		}
	}

	for (int i = 0; i < lhs.size(); i++)
	{
		total = total + lhs[i] * (map.find(lhs[i]) != map.end() ? map[lhs[i]] : 0);
	}

	std::cout << total << std::endl;
}
