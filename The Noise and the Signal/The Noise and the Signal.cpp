#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Same as Problem 6, but your task here is to find the longest noise in a number
(numbers will always be positive integers). There are several noises with equal length,
print the one that is the first lexicographically. If there are no noises, print “no noise”. 
All symbols in the input will be either letters, digits, punctuation, or signs from of the standard 
ASCII table (no control symbols like newlines or tabs, delete, etc.)
1.][.3 5--aA3:)5 2asd=@14    
*/

int main()
{
    string input;
    getline(cin, input);
    stringstream stream;
    stream << input << '\n';

    string fragment;
    string noises;
    string maxNoise;
    string equalNoises;
    string actualLength, maxLength;

    while (stream)
    {
        stream >> fragment;
        for (char character : fragment)
        {
            if (character < 48 || character > 57)
            {
                noises += character;
                actualLength += character;           
            }
        }

        if (actualLength.size() > maxLength.size())
        {
            maxLength = actualLength;
        }
        else if ((actualLength.size() == maxLength.size()) && (actualLength[0] < maxLength[0]) )
        {
            maxLength = actualLength;
        }
        
        actualLength.clear();
        noises += " ";
    }
    if (maxLength.size()< 1)
    {
        cout << "The input not contains noise" << '\n';
    }
    else
    {
    cout << maxLength << '\n';
    }

    return 0;
}