#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

/*
Write a program that reads the digits of a base-10 numeral system – exactly 10 unique non-space characters on a single line, representing
the symbols used for the digits 0-9 (inclusively) – then reads two numbers represented in that numeral system, then prints their sum in that numeral system.
*/

int getValue(map<char, int>& list, string findNumber)
{
    char localNumber;
    stringstream stream(findNumber);
    string returnNumber;
    int sentNumber{ 0 };
    while (stream >> localNumber)
    { 
		for (map<char, int>::iterator it = list.begin(); it != list.end(); it++)
		{
            if (localNumber == it->first)
            {
                returnNumber+=to_string(it->second);
            }
		}
	}
    sentNumber = stoi(returnNumber);
    return sentNumber;

}

int main()
{
    string input;
    string firstNumber{ 0 }, secondNumber{ 0 };
    getline(cin, input);
    cin >> firstNumber;
    cin >> secondNumber;

    int firstDigit{ 0 };
    int secondDigit{ 0 };

    stringstream stream(input);
    char ch;
    int weight{ 0 };
    map<char, int> myMap;
    while (stream >> ch)
    {
        myMap.insert(pair<char, int>(ch, weight));
        if (weight>9)
        {
            cout << "Error! That example is for base 10 numeral system. Too much chars." << '\n';
            break;
        }
        weight++;
    }

    firstDigit = getValue(myMap,firstNumber);
    secondDigit= getValue(myMap,secondNumber);

    cout << firstDigit + secondDigit << '\n';
    return 0;
}
