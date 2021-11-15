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

int getIntValue(map<char, int>& myMap, string findNumber)
{
    char localNumber;
    stringstream localStream(findNumber);
    string returnNumber;
    int sentNumber{ 0 };
    while (localStream >> localNumber)
    { 
		for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
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

    int intFirst{ 0 };
    int intSecond{ 0 };
    string intSum; 
    char ch;
    stringstream stream;
    stream << input;
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

    intFirst = getIntValue(myMap,firstNumber);
    intSecond= getIntValue(myMap,secondNumber);

    stream.clear();
    intSum= to_string(intFirst + intSecond);
    stream << intSum;
    int compareWithValue{ 0 };
    while (stream >> ch)
    {
        compareWithValue = ch - 48;
        for (map<char, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
        {
            if (compareWithValue == it->second)
            {
                cout << it->first;
                break;
            }
        }
    }
    
    return 0;
}
