#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

/*
Write a program that reads the digits of a base-10 numeral system – exactly 10 unique non-space
characters on a single line, representing the symbols used for the digits 0-9 (inclusively) – then
reads two numbers represented in that numeral system, then prints their sum in that numeral system.
*/

string toSystemNumber(const string baseInput, const int number)
{
    string answer;
    string numberStr = to_string(number);
    answer.resize(numberStr.size());

    for (unsigned int i = 0; i < numberStr.size(); i++)
    {
        const int index = numberStr[i] - '0';
        answer[i] = baseInput[index];
    }

    return answer;
}

int numberSystemToInt(const vector<int>& allValues,const string& valueStr)
{
    int answer{ 0 };
    int multiplier{ 1 };
    int index{ 0 };
    int size = ((int)valueStr.size()-1);

    while (size>=0)
    {
        index = valueStr[size];
        answer = answer + (multiplier * allValues[index]);
        multiplier = multiplier * 10;
        size--;
    }
    return answer;
}

int main()
{
    string baseInput;
    getline(cin, baseInput);
    string firstNumber;
    getline(cin, firstNumber);
    string secondNumber;
    getline(cin, secondNumber);

    vector<int> numeralValue(255,0);
    char letter;
    for (unsigned int i = baseInput.size(); i > 0  ; i--)
    {
        letter = baseInput[i];
        numeralValue[letter]=i;
    }

    int firstNumberInt = numberSystemToInt(numeralValue, firstNumber);

    const int secondNumberInt = numberSystemToInt(numeralValue, secondNumber);

    const int answerInt = firstNumberInt + secondNumberInt;

    cout << toSystemNumber(baseInput, answerInt);

    return 0;
}