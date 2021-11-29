#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

/*
Write a program that generate number and returns its square root.
The number will be entered with “noise” in it, i.e. there will be symbols that are not digits.
These symbols should be ignored. The last symbol of the input random symbols will always be . (dot)
and there will be no other . (dot) in the number.
*/

int getRandomSymbol()
{
	int symbol{ 0 };
	srand((unsigned)time(NULL));
	symbol = { (unsigned)rand()) % 100 + 1 };
	return symbol;
}

void Problem5()
{
	vector<char> randomSymbols;
	char dec{ 0 };
	int digit{ 0 };
	vector<int> intPositiveNumber;
	int number{ 0 };


	for (int i = 0; i < 1;)
	{
		//cin >> dec;
		dec = getRandomSymbol();

		randomSymbols.push_back(dec);

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