#ifndef Split_H
#define Split_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>



template<typename T>
std::vector<T> split(std::string &line, char &separator)
{
	std::vector<T> answer;
	line.erase(std::remove(line.begin(), line.end(), separator), line.end()); // remove separator
	std::istringstream stream(line);
	T element;
	while (stream >> element)
	{
		answer.push_back(element);
	}
	
	return answer;
}

#endif
	/*
	std::vector<T> answer;
	for (size_t i = 0; i < line.size(); i++)
	{
		if (line[i] != separator)
		{
			answer.push_back(line[i]);
		}
	}

;
caught-somewhere-in-time 446;superpalav 246
w
>


	*/