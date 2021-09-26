#include <iostream>
#include <vector>
using namespace std;

/*
Write a program that read an vector of integer numbers from the console and prints
all numbers which are larger than or equal to the mathematical average of the numbers 
in the array. The output should be printed on a single line, separating the output
number by spaces. 1 The input array will be entered on two lines – the first line
will contain an integer representing the number of elements, the second will contain 
the elements separated by spaces
*/

int main()
{
    vector<int> numbers = {};
    int lengthVector{ 0 };
    int elements{ 0 };
    cin >> lengthVector;

    int sumOfElements{ 0 };
    int averageNumber{ 0 };

    for (int i = 0; i < lengthVector; i++)
    {
        cin >> elements;
        numbers.push_back(elements);
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        sumOfElements = sumOfElements + numbers[i];
    }
    averageNumber = sumOfElements / lengthVector;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] >= averageNumber)
        {
            cout << numbers[i] << " ";
        }
    }
    return 0;
}