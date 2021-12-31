#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int main()
{
	int firstNumber{ 0 }, secondNumber{ 0 };
	cin >> firstNumber >> secondNumber; // only six numbers long

	// for cicle
	int digit{ 0 };
	int evenPosition{ 0 };
	int oddPosition{ 0 };

	for ( firstNumber; firstNumber < secondNumber; firstNumber++)
	{
		string firstNumberST = to_string(firstNumber);
		string secondNumberST = to_string(secondNumber);

		for (int i = 0; i < 6; i++)
		{
			digit = firstNumberST[i] - 48;

			if ((i % 2) == 0)
			{
				oddPosition= oddPosition + digit;
			}
			else
			{
				evenPosition= evenPosition+digit;
			}
		}

		if (evenPosition == oddPosition)
		{
				cout << firstNumber << '\n';
		}
		evenPosition = 0;
		oddPosition = 0;

	}
}