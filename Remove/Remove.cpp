#include <iostream>
#include <vector>
using namespace std;

/*
Write a program that reads an integer array from the console
(given by size, followed by the elements of the array), followed
by an integer number and removes all occurrences of that number
from the array, then prints the array
*/

int main()
{
    vector<int> numbers;
    int elements{ 0 };
    int length{ 0 };
    cin >> length;

    vector<int> newArray;
    int disireRemoveElements{ 0 };

    for ( int i = 0; i < length; i++)
    {
        cin >> elements;
        numbers.push_back(elements);
    }

    cin >> disireRemoveElements;

    for (unsigned int i = 0; i < numbers.size() ; i++)
    {
        if (numbers[i] != disireRemoveElements)
        {
            newArray.push_back(numbers[i]);
        }
    }

    for (unsigned  i = 0; i < newArray.size() ; i++)
    {
        cout << newArray[i] << " " ;
    }

    return 0;
}