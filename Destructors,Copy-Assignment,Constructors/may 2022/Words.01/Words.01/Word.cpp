#include "Word.h"


Word::Word(const std::string& str) : m_word{ str }
{
	if (!global_map.count(str))
	{
		global_map.emplace(str, 1);
	}
	else
	{
		std::map<std::string, int>::iterator it = global_map.find(str);
		it->second++;
	}
}

bool operator< (const Word& left, const Word& right)
{
	return left.getWord() < right.getWord();
}

std::string Word::getWord() const
{ 
	return m_word; 
}

int Word::getCount()const
{
	std::map<std::string, int>::iterator it = global_map.find(this->getWord());
	return it->second;
}