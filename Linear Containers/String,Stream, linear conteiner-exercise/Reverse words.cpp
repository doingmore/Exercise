#include <iostream>
#include <stack>

/*
Write a program that reads lines of space separated words from the standard input (until “end” word is met),
reverse the order of all given words and outputs the result to the standard output (words should be space-delimited).
*/

int main_1()
{
    std::string input;
	std::stack<std::string> mystack;
	std::cin >> input ;
	if (input == "end")
	{
		std::cout << " (empty) " << '\n';
	}
	while (input != "end")
	{
		mystack.push(input);
		std::cin >> input;
	}
	while (!mystack.empty())
	{
		std::cout << mystack.top() << " ";
		mystack.pop();
	}
    return 0;
}