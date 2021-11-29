#include <iostream>
#include <vector>
using namespace std;

/*
Write a program to sum all adjacent equal numbers in an array of decimal numbers, starting from left to right.
	After two numbers are summed, the obtained result could be equal to some of its neighbors and should be summed as well (see the examples below).
	Always sum the leftmost two equal neighbors (if several couples of equal neighbors are available).
The array will be defined by two lines – the first line will contain the size of the array and the second will contain the elements of the array.
*/


void Problem9()
{
    vector<int> numbers;
    int vectorSize{ 0 };
    cin >> vectorSize;
    int symbol{ 0 };
    vector<int> result;
    for (unsigned int i = 0; i < (unsigned)vectorSize; i++)
    {
        cin >> symbol;
        numbers.push_back(symbol);
    }

    while (1) {
        for (unsigned int i = 0; i < (numbers.size()); i++)
        {
            if (i < (numbers.size() - 1) && numbers[i] == numbers[i + 1])
            {
                result.push_back(numbers[i] * 2);
                i++;
            }
            else
            {
                result.push_back(numbers[i]);
            }
        }
        if (result.size() == numbers.size())
        {
            break;
        }
        numbers = result;
        result.clear();
    }

    for (unsigned int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}