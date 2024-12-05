#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static char safeRead(std::vector<std::vector<char>> &map, int x, int y)
{
	if (x < 0 || y < 0 || x >= map.size() || y >= map[0].size())
		return ' ';
	return map[x][y];
}

static int countXMASappearances(std::vector<std::vector<char>>& data)
{
	unsigned int count = 0;

	for (int x = 0; x < data.size(); x++)
	{
		for (int y = 0; y < data[x].size(); y++)
		{
			// Check if current cell is an 'X'
			if (safeRead(data, x, y) != 'X')
				continue;

			// Cardinal directions

			// Check dir left
			if (safeRead(data, x - 1, y) == 'M' && safeRead(data, x - 2, y) == 'A' && safeRead(data, x - 3, y) == 'S')
				count++;

			// Check dir right
			if (safeRead(data, x + 1, y) == 'M' && safeRead(data, x + 2, y) == 'A' && safeRead(data, x + 3, y) == 'S')
				count++;

			// Check dir up
			if (safeRead(data, x, y - 1) == 'M' && safeRead(data, x, y - 2) == 'A' && safeRead(data, x, y - 3) == 'S')
				count++;

			// Check dir down
			if (safeRead(data, x, y + 1) == 'M' && safeRead(data, x, y + 2) == 'A' && safeRead(data, x, y + 3) == 'S')
				count++;

			// Diagonal directions

			// Check dir up-left
			if (safeRead(data, x - 1, y - 1) == 'M' && safeRead(data, x - 2, y - 2) == 'A' && safeRead(data, x - 3, y - 3) == 'S')
				count++;

			// Check dir up-right
			if (safeRead(data, x + 1, y - 1) == 'M' && safeRead(data, x + 2, y - 2) == 'A' && safeRead(data, x + 3, y - 3) == 'S')
				count++;

			// Check dir down-left
			if (safeRead(data, x - 1, y + 1) == 'M' && safeRead(data, x - 2, y + 2) == 'A' && safeRead(data, x - 3, y + 3) == 'S')
				count++;

			// Check dir down-right
			if (safeRead(data, x + 1, y + 1) == 'M' && safeRead(data, x + 2, y + 2) == 'A' && safeRead(data, x + 3, y + 3) == 'S')
				count++;
		}
	}

	return count;
}

static int countX_MASappearances(std::vector<std::vector<char>>& data)
{
	unsigned int count = 0;

	for (int x = 0; x < data.size(); x++)
	{
		for (int y = 0; y < data[x].size(); y++)
		{
			// Check if the current cell is an 'A'
			if (safeRead(data, x, y) != 'A')
				continue;

			int MASCount = 0;

			// Checks for 'S' at the TL and 'M' at the BR
			if (safeRead(data, x - 1, y - 1) == 'S' && safeRead(data, x + 1, y + 1) == 'M')
				MASCount++;

			// Checks for 'S' at the TR and 'M' at the BL
			if (safeRead(data, x + 1, y - 1) == 'S' && safeRead(data, x - 1, y + 1) == 'M')
				MASCount++;

			// Checks for 'S' at the BL and 'M' at the TR
			if (safeRead(data, x - 1, y + 1) == 'S' && safeRead(data, x + 1, y - 1) == 'M')
				MASCount++;

			// Checks for 'S' at the BR and 'M' at the TL
			if (safeRead(data, x + 1, y + 1) == 'S' && safeRead(data, x - 1, y - 1) == 'M')
				MASCount++;

			// If there are 2 'MAS' around the 'A', increment the count
			if (MASCount == 2)
				count++;
		}
	}

	return count;
}

int main()
{
	// Create the data structure
	std::vector<std::vector<char>> data;
	std::ifstream file("Data.txt");

	// Parse the file
	for (std::string line; std::getline(file, line);)
	{
		std::vector<char> row;
		for (char c : line)
			row.push_back(c);
		data.push_back(row);
	}

	// Output the XMAS count
	std::cout << "XMAS count: " << countXMASappearances(data) << std::endl;

	// Output the X_MAS count
	std::cout << "X_MAS count: " << countX_MASappearances(data) << std::endl;
	
	// End the program
	return 0;
}