#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template<typename T>
class Parser
{
private:
	std::string m_stopLine;
public:
	Parser(std::istream& stream, std::string& in) : m_stopLine{in}	{}
	
	std::string getStopline() const { return m_stopLine; }

	bool readNext(T& object)
	{
		std::cin >> object;
		std::stringstream stream;
		std::string input;;
		stream << object;
		stream >> input;
		if (m_stopLine == input)
		{
			return false;
		}
		return true;
	}
};

template<>
bool Parser<int>::readNext(int& value)
{
	std::cin >> value;
	int stop{ stoi(this->getStopline()) };
	if ( stop == value)
	{
		return false;
	}

	return true;
}

template<>
bool Parser<std::string>::readNext(std::string& value)
{
	std::cin >> value;
	if (this->getStopline() == value)
	{
		return false;
	}
	return true;
}

#endif // !PARSER_H
