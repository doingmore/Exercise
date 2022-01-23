#include <iostream>
#include <string>
#include <sstream>

#include "Parser.h"
/*
i
7
1
2
3
4
5
6
7
8

====under this is another input example=====

s
...
caught-somewhere-in-time 446
superpalav 246
...
this is not printed
*/

template<typename T>
bool Parser<T>::readNext(T& toParse)
{
	this->m_line >> toParse;
	std::ostringstream stream;
	stream << toParse;
	if (stream.str() == this->m_stopLine)
	{
		return false;
	}
	return true;
}