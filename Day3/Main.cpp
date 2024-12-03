#include <iostream>
#include <fstream>
#include <string>

constexpr static bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int main()
{
	std::ifstream file("Data.txt");
	std::string fileContents = "";

	for (std::string line; std::getline(file, line);)
	{
		fileContents += line;
	}

	size_t i = 0;
	size_t length = fileContents.length();

	int total = 0;

	bool enabled = true;

	while (i < length)
	{
		if (fileContents[i] == 'd' && fileContents[i + 1] == 'o' && fileContents[i + 2] == 'n' && fileContents[i + 3] == '\'' && fileContents[i + 4] == 't' && fileContents[i + 5] == '(' && fileContents[i + 6] == ')')
		{
			enabled = false;
		}

		if (fileContents[i] == 'd' && fileContents[i + 1] == 'o' && fileContents[i + 2] == '(' && fileContents[i + 3] == ')')
		{
			enabled = true;
		}

		if (fileContents[i] == 'm' && fileContents[i + 1] == 'u' && fileContents[i + 2] == 'l' && fileContents[i + 3] == '(' && enabled == true)
		{
			i = i + 4;

			if (i >= length)
			{
				break;
			}

			int num1 = 0;

			while (isDigit(fileContents[i]))
			{
				num1 = num1 * 10 + (fileContents[i] - '0');
				i++;
			}

			if (num1 == 0)
			{
				continue;
			}
			
			if (fileContents[i] == ',')
			{
				i++;
			}

			else
			{
				continue;
			}

			int num2 = 0;

			while (isDigit(fileContents[i]))
			{
				num2 = num2 * 10 + (fileContents[i] - '0');
				i++;
			}

			if (num2 == 0)
			{
				continue;
			}

			if (fileContents[i] == ')')
			{
				total += num1 * num2;
			}

			else
			{
				continue;
			}
		}

		i++;
	}

	std::cout << "Total: " << total << std::endl;

	return 0;
}