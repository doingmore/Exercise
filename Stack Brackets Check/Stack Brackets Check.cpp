#include <iostream>
#include <string>
#include <sstream>
#include <stack>

/*
Write a program which reads a single line from the console, containing brackets for a mathematical expression
(only the brackets will appear in the input), and determines whether the brackets in the expression are correct.
There are 3 types of brackets – {}, [] and (). {} can contain {}, [] and () brackets. Square brackets [] can contain [] and () brackets.
Curved () brackets can contain only () brackets. Said simply, each type of brackets can contain the same type of brackets inside, 
or a “lower” type of brackets (() is lower than [] which is lower than {}). If a bracket of one type is opened, it needs
to be closed before a bracket of another type is closed.
Print valid if the brackets in the expression are valid and invalid if they are not.
*/

using namespace std;

bool checkBrackets(string& stream)
{
	stack <char> brackets;
	string::iterator symbol = stream.begin();
	char bracket;

	while (symbol != stream.end())
	{
		// read a bracket
		bracket = *symbol;
		// if this is OPEN bracket ( { [
		if (bracket == '(' || bracket == '{' || bracket == '[')
		{
			//check if the bracket level is correct
			if (brackets.size() && brackets.top() < bracket)
			{
				return false;
			}
			// push bracket in our stack
			brackets.push(bracket);
		}
		else    // if this is a CLOSING bracket ) } ]
		{
			// the stack cannot be empty
			if (brackets.size() == 0)
			{
				return false;
			}
			//check if the closing bracket matches top of the stack
			switch (brackets.top())
			{
			case '(':

				if (bracket != ')')
				{
					return false;
				}
				break;

			case '[':

				if (bracket != ']')
				{
					return false;
				}
				break;

			case '{':

				if (bracket != '}')
				{
					return false;
				}
				break;

			default:
				return false;
			}
			brackets.pop();  // pop from bracket stack
			// update bracket level      
		}
		symbol++; // next symbol
	}
	return brackets.size() == 0;
}

int main()
{
	string brackets;
	cin >> brackets;

	if (checkBrackets(brackets))
	{
		cout << "Valid expresion" << '\n';
	}
	else
	{
		cout << "Not valid expresion" << '\n';
	}

	return 0;
}