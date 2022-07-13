#ifndef OPERATORS_H
#define OPERATORS_H

#include <vector>
#include <sstream>
#include <string>



std::vector<std::string>& operator<< (std::vector<std::string>& vec , const std::string& str)
{
	vec.push_back(str);
	return vec;
}

std::string operator+ (std::string& str, const int& intNumber)
{
	std::string answer;
	answer = answer + str;
	answer = answer + std::to_string(intNumber);
	return answer;
}

std::ostream& operator<< (std::ostream& stream, const std::vector<std::string>& vec)
{
	for (const std::string& str : vec)
	{
		stream << str<<'\n';
	}
	return stream;
}


#endif // !OPERATORS_H
