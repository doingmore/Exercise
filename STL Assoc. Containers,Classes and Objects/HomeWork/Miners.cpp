#include <iostream>
#include <string>
#include <map>

int main()
{
	std::string input;
	int quantity{ 0 };
	std::map<std::string, int> resources;

	while (1)
	{
		std::cin >> input;
		if (input == "stop")
		{
			break;
		}
		std::cin >> quantity;

		if (resources.count(input)) //searching input key in map
		{
			resources[input] += quantity;
		}
		
		resources.emplace(input, quantity);
	}




	std::map<std::string, int>::iterator it;
	it = resources.find("Gold");
	for (it=resources.begin(); it != resources.end(); it++)
	{
	std::cout << it->first << " -> " << it->second << '\n';
	}
	return 0;
}