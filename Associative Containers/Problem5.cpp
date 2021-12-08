#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

/*
Read a list of decimal numbers and sort them in increasing order. Print the output as shown in the examples below.
*/

void Problem5()
{
    string input;
    getline(cin, input);
    stringstream stream(input);
    set<int> listNumbers;
    int number{ 0 };

    while (stream >> number)
    {
        listNumbers.insert(number);
    }

    auto stop = listNumbers.end();
    stop--;

    std::set<int>::iterator it;
    for (auto it = listNumbers.begin(); it != listNumbers.end(); it++)
    {
        if (it == stop)
        {
            cout << *it;
            break;
        }
        cout << *it << " < ";
    }
}