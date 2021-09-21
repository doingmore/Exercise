#include <iostream>
using namespace std;

/*
This is homework, program that calculates the greatest common divisor (GCD) of given two numbers.
*/

int main()
{
	int firstNumber{ 0 }, secondNumber{ 0 };
	cin >> firstNumber >> secondNumber;

	int maxDigitDivisinFirst{ 0 };
	int maxDigitDivisionSecond{ 0 };
	int maxCommonDivision{ 0 };


	for (int j = 1; j <= secondNumber; j++)
	{
		if ((secondNumber % j) == 0)
		{
			maxDigitDivisionSecond = j;
		}

		for (int i = 1; i <= firstNumber; i++)
		{
			if ((firstNumber % i) == 0)
			{
				maxDigitDivisinFirst = i;
			}
			if (maxDigitDivisinFirst == maxDigitDivisionSecond)
			{
				maxCommonDivision = maxDigitDivisinFirst;
			}
		}

	}
	cout << maxCommonDivision << '\n';
	return 0;
}