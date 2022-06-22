#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <sstream>


template<typename T>
class Parser
{
	std::string m_stop_line;
public:
	Parser(std::istream& stream, const std::string& stop) : m_stop_line{stop}
	{}

	bool readNext( T& element )
	{
		std::string input;
		std::getline(std::cin, input);
		if (input != m_stop_line)
		{
			std::istringstream in(input);
			in >> element;
			return true;
		}

		return false;
	}

};

#endif // !PARSER_H