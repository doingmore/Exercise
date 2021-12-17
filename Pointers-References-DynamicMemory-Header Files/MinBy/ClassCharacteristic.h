#ifndef ClassCharacteristic_h
#define ClassCharacteristic_h
#include <iostream>
#include <string>

class ClassCharacteristic
{
private:
	std::string m_earliestLexicographically;
	std::string m_shortestWord;
	std::string m_longestWord;
public:
	ClassCharacteristic(std::string longestWord, std::string lexicographically, std::string shortestWord)
	{
		m_longestWord = longestWord;
		m_earliestLexicographically = lexicographically;
		m_shortestWord = shortestWord;
	}

	//getters
	std::string getLex() { return  m_earliestLexicographically; };
	std::string getShort() { return  m_shortestWord; };
	std::string getLong() { return  m_longestWord; };
};


#endif // !ClassCaracteristic

