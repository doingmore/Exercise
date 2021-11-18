#include <iostream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

/*
Read a list of integers and extract all square numbers from it and print them in descending order.
A square number is an integer which is the square of any integer. For example, 1, 4, 9, 16 are square numbers.
*/

int main()
{
    string input;
    getline(cin, input);
    stringstream stream(input);
    set<int> listNumbers;
    int digit{ 0 };
    int number{ 0 };

    while (stream >> digit)
    {
        number=sqrt(digit);
        if (number*number==digit)
        {
        listNumbers.insert(digit);
        }
    }

    set<int>::iterator it=listNumbers.end();
    it--;

    for (unsigned int  i = 0; i < listNumbers.size(); i++)
    {
        cout << *it << " " << '\n';
        it--;
    }

    return 0;
}
