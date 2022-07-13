#ifndef SUM_OF_VECTORS_H
#define SUM_OF_VECTORS_H

#include <vector>
#include <string>


std::vector<std::string> operator+ (const std::vector<std::string>& left, const std::vector<std::string>& right)
{
	std::vector<std::string> answer;

	for (size_t i = 0; i < left.size(); i++)
	{
		std::string in;
		in += left[i];
		in += " ";
		in += right[i];
		answer.push_back(in);
	}

	return answer;
}




#endif // !SUM_OF_VECTORS_H
