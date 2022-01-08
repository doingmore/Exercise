#include <iostream>
#include <vector>

#include "MinBy.h"

std::string minBy(std::vector<std::string>& values, bool func(const std::string& a, const std::string& b))
{
	std::string answer = values[0];
	std::string b;
	for (size_t i = 0; i < values.size(); i++)
	{
		b = values[i];
		if (func(answer, b))
		{
			// nothing
		}
		else if (answer.size() == b.size())
		{
			if (b < answer)
			{
				answer = b;
			}
			else
			{
				//nothnig
			}
		}
		else
		{
			answer = b;
		}
	}
	return answer;
}