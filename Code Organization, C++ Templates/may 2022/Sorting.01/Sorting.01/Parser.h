#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <set>
#include <string>

#include "Song.h"

template<typename T>
class Parser
{
private:
	std::set<T> m_list;
	std::string m_stopLine;
public:
	Parser(std::istream& stream, std::string& stopLine) : m_stopLine{stopLine} {}

    bool readNext(T& element) 
    {
        std::string line;
        if (std::getline(std::cin, line) && line != m_stopLine) {
            std::istringstream is(line);
            is >> element;
            return true;
        }
        return false;
    }
};

#endif // !PARSER_H
