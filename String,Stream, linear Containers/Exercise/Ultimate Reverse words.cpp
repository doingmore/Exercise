#include <iostream>
#include <sstream>
#include <map>
#include <vector>

bool isEnd(const char& c)
{
	if (c == '!' || c == '.' || c == '?' || c==',')
	{
		return true;
	}
	else if (c == 32)
	{
		return true;
	}
	return false;
}

bool checkForWord(std::string& str,std::vector<std::string>& registerForWords)
{
	for (size_t i = 0; i < registerForWords.size(); i++)
	{
		if (str == registerForWords[i])
		{
			return true;
		}
	}
	return false;
}

void swapWords(std::map<int, std::string>& myMap)
{
	std::vector<std::string> registerForWords;
	std::string temporary;
	std::map<int, std::string>::iterator itR;
	std::map<int, std::string>::iterator itL;
	for (itL = myMap.begin(); itL != myMap.end(); itL++)
	{
		itR = myMap.end();
		itR--;
		while (itL->first < itR->first)
		{
			if ( itL->second.size() == itR->second.size() && !checkForWord(itL->second, registerForWords) && !checkForWord(itR->second, registerForWords))
			{
			registerForWords.push_back(itL->second);
			registerForWords.push_back(itR->second);
			//swap
			temporary = itL->second;
			itL->second = itR->second;
			itR->second = temporary;
			temporary.erase();
			break;
			}
			itR--;
		}
	}
}

void exchangeWordsInInputString(std::string& input,std::map<int, std::string>& myMap)
{
	int counter{ 0 };
	std::string word;
	std::map<int, std::string>::iterator it=myMap.begin();
	for (size_t i = 0; i < myMap.size(); i++)
	{
	word=it->second;
		for (size_t k = 0; k < word.size(); k++)
		{
			input[counter] = word[k];
			counter++;
		}
		it++;
		if (it != myMap.end())
		{
		counter = it->first;
		}
	}
}

void correctionCapitalLetter(std::string& input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (islower(input[0]))
		{
			input[0] -= 32; 
		}
		if (input[i] == ' ')
		{
			if (isupper(input[i+1]))
			{
				input[i + 1] += 32;
			}
		}
	}
}

int main()
{
	std::stringstream stream;
	std::map<int,std::string> myMap;
	std::string input;
	std::string word;
	std::getline(std::cin, input);
	for (size_t i = 0; i < input.size(); i++)
	{
		if ( !isEnd(input[i]) )           
		{
			word += input[i];
		}
		else
		{
			if (word != "")
			{
			myMap.emplace((i - word.size() ),word);
			}
			word.erase();
		}
	}
	swapWords(myMap);
	exchangeWordsInInputString(input, myMap);
	correctionCapitalLetter(input);
	std::cout << input << '\n';
	return 0;
}
