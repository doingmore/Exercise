#include <iostream>
#include<vector>
using namespace std;

/*
Write a program that finds the longest sequence of equal elements
in an integer vector and then prints that sequence 
on the console (integers separated by space on a single line). 
If there is more than one such sequence, print the bigest one. 
The input vector will be entered on two lines – the first line will contain
an integer representing the number of elements, 
the second will contain the elements separated by spaces
*/

int main()
{
    vector<int> Numbers;
    int vectorlength;
    int elements;
    cin >> vectorlength;
    
    int digitFromMaxCounterMatch{ 1 };
    int bigestDigit{ 0 };
    int counterMatch = 1;
    int maxCounterMatch = 1;
    
    for (size_t i = 0; i < vectorlength; i++)
    {
        cin >> elements;
        Numbers.push_back(elements);
    }

    for (size_t i = 1; i < Numbers.size(); i++)
    {
        if (Numbers[i] == Numbers[i - 1]) {
            counterMatch++;
        }
        else
        {
            counterMatch = 1;
        }
        if (counterMatch > maxCounterMatch) {
            maxCounterMatch = counterMatch;
            digitFromMaxCounterMatch = Numbers[i];
        }
        if (Numbers[i] > bigestDigit)
        {
            bigestDigit = Numbers[i];
        }
        
    }
    if (digitFromMaxCounterMatch != 1)
    {
        for (size_t i = 0; i < maxCounterMatch; i++)
        {
            cout << digitFromMaxCounterMatch << " ";
        }
    }
    else
    {
        cout << bigestDigit;
    }
}
