#include <iostream>
#include <sstream>
#include <map>

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


void exchangeWords(std::map<int, std::string>& myMap)
{
	std::string temporary;
	std::map<int, bool> registerForSwapedWords;
	std::map<int, std::string>::iterator itR;
	std::map<int, std::string>::iterator itL;
	for ( itL=myMap.begin(); itL != myMap.end(); itL++)
	{
		itR = myMap.end();
		itR--;
		while(itL->first < itR->first)
		{
			if ( itL->second.size() == itR->second.size() )
			{
				temporary = itL->second;
				itL->second = itR->second;
				itR->second = temporary;
			
				temporary.erase(); //string temporary
				break;
			}
			itR--;
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

	exchangeWords(myMap);



	return 0;
}