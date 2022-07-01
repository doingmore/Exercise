#ifndef MIN_BY_H
#define MIN_BY_H

#include <sstream>
#include <string>

#define begin 0


std::string minBy(const std::vector<std::string>& vec, bool(*func)(const std::string& a, const std::string& b) )
{
	std::string answer = vec[begin];
	for (size_t i = 1; i < vec.size(); i++)
	{
		if (func(vec[i], answer))
		{
			answer = vec[i];
		}
	}
	return answer;
}


#endif // !MIN_BY_H
