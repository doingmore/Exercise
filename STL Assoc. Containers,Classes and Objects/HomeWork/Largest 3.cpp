#include <iostream>
#include <sstream>
#include <set>

int main_3()
{
	std::stringstream stream;
	std::set<int> myList;
	std::string input{ 0 };
	std::getline(std::cin, input);
	stream << input;
	input.erase();
	int number{0};
	while (stream >> input)
	{
		number = stoi(input);
		myList.insert(number);
	}
	

	std::set<int>::iterator it=myList.end();
	it--;
	for (int i = 0; i < 3; i++)
	{
		std::cout << *it << " ";
		it--;
	}
	
	return 0;
}