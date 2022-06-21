#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <vector>
#include <string>

#include "Song.h"

template <typename T>
class Parser
{
private:
	std::string m_stopLine;
public:
	Parser(std::istream& stream, std::string& stop) : m_stopLine{stop}
	{}

	bool readNext(T& object)
	{
		std::string input;
		std::getline(std::cin, input);

		if (input != m_stopLine)
		{
			std::istringstream in(input);
			in >> object;
			return true;
		}
		return false;
	}

};


#endif // !PARSER_H
