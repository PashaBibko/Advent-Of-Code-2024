#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

static bool verifyRow(std::vector<int> data)
{
	// The levels are either all increasing or all decreasing.

	bool increasing = true;
	bool firstLoop = true;
	bool valid = true;

	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] - data[i - 1] > 0)
		{
			if (firstLoop == false && increasing == false)
			{
				valid = false;
			}

			if (firstLoop)
			{
				increasing = true;
			}
		}

		else if (data[i] - data[i - 1] < 0)
		{
			if (firstLoop == false && increasing == true)
			{
				valid = false;
			}

			if (firstLoop)
			{
				increasing = false;
			}
		}

		firstLoop = false;
	}

	// Any two adjacent levels differ by at least one and at most three.

	int diffA = (increasing ? 1 : -3);
	int diffB = (increasing ? 3 : -1);

	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] - data[i - 1] < diffA || data[i] - data[i - 1] > diffB)
		{
			valid = false;
		}
	}

	// Print the result

	std::cout << "Data: " << data.size() << " " << (increasing ? " Increasing" : " Decreasing") << std::endl;
	std::cout << "Valid: " << (valid ? "True" : "False") << std::endl;

	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}

	std::cout << "\n\n";

	// If the row is valid, return true.
	return valid;
}

int main()
{
	std::ifstream file("Data.txt");
	std::string line;

	int validRows = 0;

	while (std::getline(file, line))
	{
		std::vector<int> row;
		std::string value;

		for (char c : line)
		{
			if (c == ' ')
			{
				row.push_back(std::stoi(value));
				value.clear();
			}
			else
			{
				value += c;
			}
		}

		row.push_back(std::stoi(value));

		bool result = verifyRow(row);

		if (result)
		{
			validRows++;
		}

		else
		{
			for (int i = 0; i < row.size(); i++)
			{
				std::vector<int> newRow = row;
				newRow.erase(newRow.begin() + i);

				if (verifyRow(newRow))
				{
					validRows++;
					break;
				}
			}
		}
	}

	std::cout << "Valid Rows: " << validRows << std::endl;
}