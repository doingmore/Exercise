#include <vector>
#include <string>
#include "MinBy.h"

std::string minBy(const std::vector<std::string>& words, bool criterion(const std::string& a, const std::string& b))
{
	std::string answer{ words[0] };
	for (size_t i = 0; i < words.size() - 1; i++)
	{
		if (criterion(words[i], answer))
		{
			answer = words[i];
		}
	}
	return answer;
}