#include <iostream>
#include <string>

using namespace std;
/*
Write a program which is given a line of text, another line
with a "find" string and another line with a "replace" string.
Any part of text which matches the "find" string should be
replaced with the "replace" string.Print the resulting text on the console.
*/

void Problem4()
{
	string text;
	getline(cin, text); //I am the Night. Dark Night! No, not the knight

	cout << "Enter the word,which you want replace." << '\n';
	string removeWord;
	getline(cin, removeWord); // Night

	cout << "Enter the word with which you want replace." << removeWord << '\n';
	string replaceWord;
	getline(cin, replaceWord); // Day

	int lengthRemoveWord = removeWord.size();

	while (true)
	{
		int soughtPositions = text.find(removeWord);

		if (soughtPositions == -1) // -1 When the searching is not successful
		{
			break;
		}
		text.replace(soughtPositions, lengthRemoveWord, replaceWord);
	}
	cout << text << '\n';
}