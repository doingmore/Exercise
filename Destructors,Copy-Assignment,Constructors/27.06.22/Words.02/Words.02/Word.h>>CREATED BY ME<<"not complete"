#ifndef WORD_H
#define WORD_H
#include <string>
#include <map>



class Word
{
private:
	static std::map<std::string, int> m_register;
	std::string m_identical_string;
public:
	Word(const std::string& str) : m_identical_string{ str }
	{
		if (m_register.count(str))
		{
			(m_register.find(str)->second)++;
		}
		else
		{
			m_register.emplace(str, 1);
		}
	}

	friend bool operator< (const Word& left, const Word& right)
	{
		return left.m_identical_string < right.m_identical_string;
	}

	std::string getWord() const { return m_identical_string; }
	int getCount() const { int answer{ m_register.find(this->m_identical_string)->second }; return answer; }



};

std::map<std::string, int> Word::m_register;

#endif // !WORD_H
