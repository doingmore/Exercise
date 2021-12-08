#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

/*
Write a program that extracts from a given sequence of words all elements that appear in it an odd number of times (case-insensitive).
•	Words are given in a single line, space separated.
•	Print the result elements in lowercase, in their order of appearance.
*/

void Problem2()
{

    map<string, int> map;
    string words;
    getline(cin, words);
    stringstream stream(words);
    string n;

    while (stream >> n)
    {
        std::transform(n.begin(), n.end(), n.begin(), ::tolower);
        if (map.count(n))
        {
            map[n]++;
        }
        else
        {
            map.insert(pair<string, int>(n, 1));
        }
    }

    std::map<string, int>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        if ((it->second) % 2 != 0)
        {
            cout << it->first << " " << '\n';
        }
    }
}