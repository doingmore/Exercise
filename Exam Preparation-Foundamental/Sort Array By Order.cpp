#include <iostream>
#include <sstream>
#include <vector>

/*
5
1 2 3 h H
*/

int main()
{
	std::vector<char> array;
	std::string lowercase;
	std::string numbers;
	std::string others;
	int size{ 0 };
	char symbol;
	std::cin >> size;
	
	for (int i = 0; i < size; i++)
	{
		std::cin >> symbol;
		array.emplace_back(symbol);
	}

	for (char s : array)
	{
		if (s >= 48 && s <= 57) // number
		{
			numbers += s;
			numbers += ' ';
		}
		else if (s >= 97 && s <= 122) // lowercase
		{
			lowercase += s;
			lowercase += ' ';
		}
		else
		{
			others += s;
			others += ' ';
		}
	}

	std::cout << numbers << '\n' << lowercase << '\n'<< others << '\n';

	return 0;
}