#ifndef Join_H
#define Join_H

#include <iostream>
#include <string>
#include <vector>

template <typename U>
std::string join(std::vector<U>& vec, std::string& joinStr)
{
	std::string answer;

	for (unsigned i = 0; i < vec.size(); i++)
	{
		answer += vec[i];
		if ((i + 1) == vec.size())
		{
			break;
		}
		answer += joinStr;
	}

	return answer;
}

#endif // !Join_H
