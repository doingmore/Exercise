#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <sstream>
#include <vector>
#define begin 0

template<typename T>
std::vector<T> split(std::string& line , const char& separator)
{
	std::vector<T> answer;

	for (size_t i = begin; i < line.size(); i++) // remove separator from input line
	{
		if (line[i] == separator)
		{
			line[i] = ' ';
		}
	}

	std::istringstream in(line);
	
	T element;
	while (in >> element)
	{
		answer.push_back(element);
	}

	return answer;
}


#endif // !SPLIT_H
