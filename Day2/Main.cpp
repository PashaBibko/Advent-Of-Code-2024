#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

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

		// The levels are either all increasing or all decreasing.

		bool increasing = true;
		bool firstLoop = true;
		bool valid = true;
		
		for (int i = 1; i < row.size(); i++)
		{
			if (row[i] - row[i - 1] > 0)
			{
				if (firstLoop == false && increasing == false)
				{
					valid = false;
				}

				increasing = true;
			}

			else if (row[i] - row[i - 1] < 0)
			{
				if (firstLoop == false && increasing == true)
				{
					valid = false;
				}

				increasing = false;
			}

			firstLoop = false;
		}

		// Any two adjacent levels differ by at least one and at most three.

		int diffA = (increasing ? 1 : -3);
		int diffB = (increasing ? 3 : -1);

		for (int i = 1; i < row.size(); i++)
		{
			if (row[i] - row[i - 1] < diffA || row[i] - row[i - 1] > diffB)
			{
				valid = false;
			}
		}

		// If the row is valid, increment the validRows counter.

		if (valid)
		{
			validRows++;
		}

		// Print the result

		if (true)
		{
			std::cout << "Row: " << row.size() << " " << (valid ? "Valid" : "Invalid") << " " << (increasing ? " Increasing" : " Decreasing") << std::endl;

			for (int i = 0; i < row.size(); i++)
			{
				std::cout << row[i] << " ";
			}

			std::cout << "\n\n";
		}
	}

	std::cout << "Valid Rows: " << validRows << std::endl;
}