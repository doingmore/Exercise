#include <iostream>
#include <sstream>
#include <map>


int main_4()
{
	std::stringstream stream;
	std::map<std::string, int> myMap;
	std::string input;
	std::getline(std::cin, input);
	stream << input;
	input.erase();
	while (stream >> input)
	{
		if (isupper(input[0])) // transform letters from capital letter to lowercase, if they are capital
		{
			for (size_t i = 0; i < input.size(); i++)
			{
				if (isalpha(input[i]) && isupper(input[i]))
				{
					input[i] += 32;
				}
			}
		}

		if (myMap.count(input))
		{
			// OK do nothing
		}
		else
		{
			myMap.emplace(input, input.size());
		}
	}

	std::map<std::string, int>::iterator it;
	for ( it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->second < 5 )
		{
			std::cout << it->first << " ";
		}
	}
	return 0;
}