#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
Write a program, use an array of chars (max char 100), that by inputed characters sorts them in the following order:
•	Numbers
•	Small case letters
•	All others (Caps letters, symbols)
*/

void print(set<char>& list)
{
	set<char>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		cout << *it << " ";
	}
	'\n';
}

void Problem2()
{
	int numberOfSymbols{ 0 };
	cin >> numberOfSymbols;
	char symbol;
	set<char> inputList;
	set<char> digits;
	set<char> lowercase;
	set<char> capitalLetter;
	set<char> other;

	for (unsigned int i = numberOfSymbols; i > 0; i--)
	{
		cin >> symbol;
		inputList.insert(symbol);
	}

	set<char>::iterator it;
	for (it = inputList.begin(); it != inputList.end(); it++)
	{
		symbol = *it;
		if (isdigit(symbol))
		{
			digits.insert(symbol);
		}
		else if (symbol > 64 && symbol < 91)
		{
			capitalLetter.insert(symbol);
		}
		else if (symbol > 96 && symbol < 123)
		{
			lowercase.insert(symbol);
		}
		else
		{
			other.insert(symbol);
		}
	}
	if (digits.size() != 0) { print(digits); };  // if have any digits
	if (lowercase.size() != 0) { print(lowercase); }; //if have any lowercase
	if (capitalLetter.size() != 0) { print(capitalLetter); }; //if have any capitalLetter
	if (other.size() != 0) { print(other); }; //if have any other symbol
}