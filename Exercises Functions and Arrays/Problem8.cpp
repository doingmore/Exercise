#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Create a program that reads an numbers from user and multiplies the sum of all its even digits by the sum of all its odd digits:
*/

void Problem8()
{
	string elements;
	cin >> elements;
	vector <int> arrays;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		char oneElement = elements[i];
		int symbolsInArrays = oneElement - 48;  // char to int 
		if (oneElement > 48 && oneElement < 57)
		{
			arrays.push_back(symbolsInArrays);
		}
	}

	int evenDigits{ 0 };
	int oddDigits{ 0 };

	for (unsigned int i = 0; i < arrays.size(); i++)
	{
		if ((arrays[i] % 2) == 0)
		{
			evenDigits = evenDigits + arrays[i];
		}
		if ((arrays[i] % 2) != 0)
		{
			oddDigits = oddDigits + arrays[i];
		}
	}

	cout << evenDigits * oddDigits << '\n';
}