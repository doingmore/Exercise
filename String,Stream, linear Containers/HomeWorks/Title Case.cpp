#include <iostream>
#include <string>

using namespace std;

/*
Write a program which changes each word in a text to start with a capital letter
(don’t bother with the exact title-case rules about not capitalizing things like in, from, etc.).
Assume the first letter of a word is an English alphabetical symbol preceded by a non-alphabetical
symbol (so in “we will--rock you”, “we”, “will”, “rock” and “you” are all considered words which need to be capitalized).
*/

void Problem3()
{
	string text;
	getline(cin, text);

	for (unsigned int i = 1; i < text.size(); i++)
	{
		if (text[i - 1] == ' ' && text[i] > 96)
		{
			text[i] = text[i] - 32;
		}
	}
	cout << text << '\n';
}