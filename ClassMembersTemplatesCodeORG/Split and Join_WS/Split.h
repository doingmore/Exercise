#ifndef Split_H
#define Split_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

template<typename T>
std::vector<T> split(std::string& line, char& separator)
{
	std::vector<T> answer;
	std::stringstream stream; // stream for cast
	std::string fragment;
	T element;
	for (unsigned int i = 0; i < line.size(); i++)
	{
		if (line[i] != separator)
		{
			fragment += line[i];
		}
		else
		{
			stream << fragment;
			stream >> element;
			answer.push_back(element);
			stream.clear();
			fragment.clear();
		}
	}
	// if does not meet a new separator
	stream << fragment;
	stream >> element;
	answer.push_back(element);
	stream.clear();
	fragment.clear();
	return answer;
}
#endif
