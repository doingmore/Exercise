#include<iostream>
#include <map>
#include <iterator>
#include <string>

/*
Write a program that reads the digits of a base-10 numeral system – exactly 10 unique non-space characters on a single line,
representing the symbols used for the digits 0-9 (inclusively) – then reads two numbers represented in that numeral system,
then prints their sum in that numeral system.

abcdefghij
cba                 ==> daa
ja

0123456789
42                  ==> 554
512

*/

std::map<char, int> myMap;

void getDigit(std::string& digit)
{
	char symbol;
	std::string input;
	std::cin >> input;
	for (size_t i = 0; i < input.size(); i++)
	{
		symbol = input[i];
		digit += symbol;
	}
}

std::string translateToTenNumeralSystem(const std::string& digitstring)
{
	std::string answer;
	char symbol;

	std::map<char, int>::iterator it;
	for (size_t i = 0; i < digitstring.size(); i++)
	{
		symbol = digitstring[i];
		for (it = myMap.begin(); it != myMap.end(); it++)
		{
			if (symbol == it->first)
			{
				answer += std::to_string(it->second);
				break;
			}
		}
	}

	return answer;
}

	

int main()
{
	std::string input;
	std::string firstDigit;
	std::string secondDigit;
	std::cin >> input;
	char symbol;
	for (size_t i = 0; i < input.size(); i++)
	{
		symbol = input[i];
		myMap.emplace(std::pair<char, int>(symbol, i));
	}

	getDigit(firstDigit);
	getDigit(secondDigit);
	
	std::string firstAddStr{ translateToTenNumeralSystem(firstDigit) };
	std::string secondAddStr{ translateToTenNumeralSystem(secondDigit) };
	int firstAdd{ stoi(firstAddStr) };
	int secondAdd{ stoi(secondAddStr) };

	std::string sum{ std::to_string( firstAdd + secondAdd) };

	std::cout << '\n';
	std::map<char, int>::iterator it;
	for (size_t i = 0; i < sum.size(); i++)
	{
		symbol = sum[i];
		int compare = symbol - 48;
		for (it = myMap.begin(); it != myMap.end(); it++)
		{
			if (compare == it->second)
			{
				std::cout<< it->first;
				break;
			}
		}
	}

	return 0;
}