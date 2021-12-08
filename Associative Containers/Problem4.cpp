#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

/*
Read a text, extract its words (separated by spaces) find all short words (less than 5 characters) and print them alphabetically,
in lowercase, separate by a single comma and a single space.
•	Use case-insensitive matching.
•	Remove duplicated words.
*/

void Problem4()
{
	string input;
	getline(cin, input);
	stringstream stream(input);
	string word;
	int sizeWord{ 0 };
	map<string, int> list;
	while (stream >> word)
	{
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		sizeWord = word.size();
		list.insert(pair<string, int>(word, sizeWord));
	}

	std::map<string, int>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (it->second < 5)
		{
			cout << it->first << ", ";
		}
	}
}