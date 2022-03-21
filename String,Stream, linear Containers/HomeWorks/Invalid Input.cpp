#include <iostream>
#include <string>

using namespace std;

/*
Write a program which reads a line containing integer numbers, separated by spaces,
and prints their sum. In addition to the numbers, each line will contain one
or more words (sequences of English letters) – print those words on a separate line,
separated by spaces, after the sum, in the order they were in the input.
*/

int findSum(string str)
{
	// A temporary string
	string temp = "";


	// holds sum of all numbers present in the string
	int sum = 0;

	// read each character in input string
	for (char ch : str)
	{
		if (ch == '-')
		{
			temp += ch;
		}
		// if current character is a digit
		else if (isdigit(ch))
		{
			temp += ch;
		}

		// if current character is an alphabet
		else
		{
			// increment sum by number found earlier
			// (if any)
			sum += atoi(temp.c_str());

			// reset temporary string to empty
			temp = "";
		}

	}

	// atoi(temp.c_str()) takes care of trailing
	// numbers
	return sum + atoi(temp.c_str());
}

int findWords(string str)
{
	// A temporary string
	string newString;

	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] < 47 || str[i]>57)
		{
			newString += str[i];
		}
	}
	cout << newString << '\n';
	return 0;
}


void Problem5()
{

	string str;
	getline(cin, str);

	cout << findSum(str) << '\n';
	findWords(str);
}