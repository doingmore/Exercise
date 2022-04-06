#include <iostream>
#include <stack>
#include <sstream>

void reverse(int* &array,int n)
{
	std::stack<int> temporary;
	for (int i = 0; i < n; i++)
	{
		temporary.push(array[i]);
	}
	for (int i = 0; i < n; i++)
	{
		array[i] = temporary.top();
		temporary.pop();
	}
}

int main_1()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // check for memory leak

	int length{ 0 };
	std::cin >> length;
	std::cin.ignore();
	int* array = new int[length];

	std::string input;
	std::stringstream stream;
	std::getline(std::cin, input);
	stream << input;
	input.erase();
	int digit{ 0 };
	for (int i = 0; i < length; i++)
	{
		stream >> input;
		digit = stoi(input);
		array[i] = digit;
	}
	
	reverse(array,length); // with stack
	
	//print
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}

	delete[] array;
	return 0;
}
