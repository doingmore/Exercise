#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Write a program that reads a positive integer number and returns its square root
(print the result as cout prints double numbers). The number will be entered with “noise”
in it, i.e. there will be symbols that are not digits. These symbols should be ignored.
The last symbol of the input of the number will always be . (dot) and there will be no other . (dot) in the number.
*/

void Problem4()
{
	vector<char> randomSymbols;
	char dec;
	int digit{ 0 };
	vector<int> intPositiveNumber;
	int number{ 0 };

	for (int i = 0; i < 1;)
	{
		cin >> dec;
		randomSymbols.push_back(dec);
		//dec = symbols;
		if (dec > 47 && dec < 58)
		{
			digit = (dec - 48);
			intPositiveNumber.push_back(digit);
		}
		if (dec == 46) // that is .(dot)
		{
			break;
		}
	}

	for (unsigned int i = 0; i < intPositiveNumber.size(); i++)
	{
		number = number * 10;
		number = number + (intPositiveNumber[i]);
	}
	cout << sqrt(number);
}