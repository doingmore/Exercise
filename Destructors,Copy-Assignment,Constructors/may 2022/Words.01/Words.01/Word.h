#ifndef WORD_H
#define WORD_H

#include <string>
#include <map>
#include <set>

static std::map<std::string, int> global_map;

class Word
{
private:
	std::string m_word;
public:
	Word(const std::string& str);
	
	std::string getWord() const;
	int getCount()const;


	friend bool operator< (const Word& left, const Word& right);
};





#endif // !WORD_H
