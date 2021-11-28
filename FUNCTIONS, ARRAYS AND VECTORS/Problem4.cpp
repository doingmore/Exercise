#include <iostream>
#include<vector>

using namespace std;

/*
Write a program that finds the most frequent number in a given sequence of numbers.
•	Numbers will be in the range [0…9].
•	In case of multiple numbers with the same maximal frequency, print all of them, ordered from smallest to largest, separated by spaces
*/

void Problem4()
{
	vector<int> numbers;
	int length{ 0 };
	cin >> length;
	int index{ 0 };
	int maxCount{ 0 };
	int count{ 0 };
	while (length--)
	{
		cin >> index;
		numbers.push_back(index);
	}

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		count = 1;
		for (unsigned int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] == numbers[j])
			{
				count++;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
		}
	}

	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		count = 1;
		for (unsigned int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[i] == numbers[j])
			{
				count++;
			}
		}
		if (count == maxCount)
		{
			cout << numbers[i] << " ";
		}
	}
}