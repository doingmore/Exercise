#include <string>
#include <vector>
#include <sstream>
#include "Operators.h"


std::vector<std::string>& operator<< (std::vector<std::string>& left, const std::string& right)
{
	left.push_back(right);
	return left;
}

std::string operator+ (const std::string& left, const int& right)
{
	std::string answer;
	std::string number = std::to_string(right);
	answer += left;
	answer += number;
	return answer;
}

std::ostream& operator<< (std::ostream& stream, const std::vector<std::string>& vec)
{
	if (!vec.empty())
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			stream << vec[i] << '\n';
		}
	}
	return stream;
}