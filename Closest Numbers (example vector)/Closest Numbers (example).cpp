#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

/*
Write a program which finds the two closest (by value) integer numbers
in an vector and prints the absolute difference between them.
*/

int main()
{
    vector<int> numbers;
    int length{ 0 };
    cin >> length;
    int symbols{ 0 };

    for (int i = 0; i < length; i++)
    {
        cin >> symbols;
        numbers.push_back(symbols);
    }

    int actualDifference{ 0 };
    int closestNumber{ INT_MAX };
    int closestNumberFirst{ 0 };
    int closestNumberSecond{ 0 };

    for (unsigned int i = 1; i < numbers.size(); i++)
    {
        actualDifference = 0;
        if (numbers[i-1] > numbers[i])
        {
            actualDifference = abs(numbers[i] - numbers[i - 1]);
        }
        
        else if (numbers[i-1] < numbers[i])
        {
            actualDifference = abs(numbers[i-1] - numbers[i]);
        }
        else
        {
            actualDifference = numbers[i-1];
        }
        if (actualDifference < closestNumber)
        {
            closestNumber = actualDifference;
            closestNumberFirst = numbers[i-1];
            closestNumberSecond = numbers[i];
        }

    }
    for (int i = 0; i < 1; i++)
    {
        actualDifference = 0;
        if (numbers[i] > numbers[length-1])
        {
            actualDifference = abs(numbers[i] - numbers[length - 1]);
        }

        else if (numbers[i] < numbers[length-1])
        {
            actualDifference = abs(numbers[i] - numbers[length-1]);
        }
        else
        {
            actualDifference = numbers[i];
        }
        if (actualDifference < closestNumber)
        {
            closestNumber = actualDifference;
            closestNumberFirst = numbers[i];
            closestNumberSecond = numbers[length - 1];
        }

    }
    if (closestNumber==1)
    {
        cout << "All numbers in this vector are exactly 1 unit apart" << '\n';
    }
    else
    {
        cout << " The closest numbers are "<< closestNumberFirst <<" and "<< closestNumberSecond <<" absolute difference is: " << closestNumber << '\n';
    }
    return 0;
}
