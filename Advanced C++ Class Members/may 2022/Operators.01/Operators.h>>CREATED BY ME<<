#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include <vector>
#include <sstream>


std::string& operator+ (std::string& left, const char text[] )
{
	return left += text;
}

std::string& operator+ (std::string& left, const std::string& right)
{
	return left += right;
}

std::string& operator+ (std::string& left, const size_t& right)
{
	return left += std::to_string(right);
}


std::vector<std::string>& operator<< (std::vector<std::string>& formattedLines, const std::string& str)
{
	formattedLines.push_back(str);
	formattedLines.push_back("\n");
	return formattedLines;
}

std::ostream& operator<< (std::ostream& stream , const std::vector<std::string>& vec)
{
	for (std::string s : vec)
	{
		stream << s;
	}
	return stream;
}


#endif // !OPERATORS_H
