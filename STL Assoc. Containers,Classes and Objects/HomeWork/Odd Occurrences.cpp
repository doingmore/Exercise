#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

/*
Java C# PHP PHP JAVA C java
*/

int main()
{
	std::stringstream stream;
	std::map<std::string, int> myMap;
	std::vector<std::string> order;
	std::string input;
	std::getline(std::cin, input);
	stream << input;
	input.erase();
	while (stream >> input)
	{
		if ( isupper(input[0]) ) // transform letters from capital letter to lowercase, if they are capital
		{
			for (size_t i = 0; i < input.size(); i++)
			{
				if (isalpha(input[i]) && isupper(input[i]) )
				{
					input[i] += 32;
				}
			}
		}

		if (myMap.count(input))
		{
			myMap[input] += 1;
		}
		else
		{
			myMap.emplace(input, 1);
			order.push_back(input);
		}
	}
	
	std::map<std::string, int>::iterator it;
	for (size_t i = 0; i < order.size(); i++)
	{
		if (myMap.count(order[i]))
		{
			it = myMap.find(order[i]);
		}
		if (it->second % 2 != 0)
		{
			std::cout << it->first << " ";
		}
	}

	return 0;
}