#ifndef Word_H
#define Word_H
#include <string>
#include <map>

static std::map<std::string,int> map; // repository for m_str on objects

class Word
{
private:
	int m_count;
	std::string m_str;
public:
	Word(std::string word)
	{

		if (doCheckForObjectWithThisMember(word))
		{
			std::map<std::string, int>::iterator it=map.find(word);
			it->second += 1;
			m_count = it->second;
			m_str = word;
		}
		else
		{
		m_count = 1;
		m_str = word;
		map.emplace(m_str, m_count);
		}
	}

	bool doCheckForObjectWithThisMember(const std::string &word) const
	{
		std::map<std::string,int>::iterator it;
		for (it=map.begin(); it != map.end(); it++)
		{
			if (it->first == word)
			{
				return true;
			}
		}
		return false;
	}

	bool operator< (const Word& other) const 
	{
		return m_str < other.m_str;
	}

	std::string getWord() const { return this->m_str; }

	int getCount() const { return this->m_count; }

};

// Ths task not solved currect !!!
// The problem is new object with increase m_count can't input in set, because m_str is same.
// In this task, It's worth noting " operator< " !!! 
 
/* input
she sells sea shells on the sea shore
hello world
*/


#endif // !Word_H
