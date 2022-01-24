#ifndef Join_H
#define Join_H

#include <iostream>
#include <string>
#include <vector>

template <typename U>
std::string join(std::vector<U> &vec,std::string &joinStr)
{
	std::string answer;

	for (unsigned i = 0; i < vec.size(); i++)
	{
		answer += vec[i];
		if ((i+1) == vec.size())
		{
			break;
		}
		answer += joinStr;
	}

	return answer;
}








#endif // !Join_H



/*
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

//#include "func.h"

std::string do_replace(std::string const& in, std::string const& from, std::string const& to)
{
	return std::regex_replace(in, std::regex(from), to);
}

template <typename T>
std::vector<T> split(std::string line, char separator) {
	std::string replasedDelimiters_EmptySpacesStr = do_replace(line, separator, " ");
	istringstream iss(replasedDelimiters_EmptySpacesStr);
	T token;
	std::vector<T> v;
	while (iss >> token) {
		v.push_back(token);
	}
	return v;
}

template <>
std::vector<Song> split(std::string line, std::string separator) {
	std::string replasedDelimiters_EmptySpacesStr = do_replace(line, separator, " ");
	std::istringstream iss(replasedDelimiters_EmptySpacesStr);
	Song song;
	std::string name; int length;

	std::vector<Song> v;
	while (iss >> name) {
		iss >> length;
		v.push_back({ name, length });
	}
	return v;
}
*/
