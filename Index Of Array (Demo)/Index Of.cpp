#include <iostream>
#include <vector>
using namespace std;

/*
Write a program that reads an integer array from the console
(given by size, followed by the elements of the array), followed
by an integer number and prints the index of that number in the array
on the console (if the number does not appear in the array, print -1).
*/

int main()
{
    vector<int> example;
    int lengthExample{ 0 };
    int elements{ 0 };
    cin >> lengthExample;

    int desiredElement{};
    bool flag=true;

    for (int i = 0; i < lengthExample; i++)
    {
    cin >> elements;
    example.push_back(elements);
    }

    cout <<"Enter the desired element:"<<'\n';
    cin >> desiredElement;

    for ( unsigned int i = 0; i < example.size(); i++)
    {
        if (example [i] == desiredElement )
        {
            cout << "The out put is: " << i << '\n';
            flag = false;
        }
    }

    if (flag)
    {
     cout << "The out put is: (-1) " << '\n';
    }
    return 0;
}
