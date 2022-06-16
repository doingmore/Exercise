#ifndef SUM_OF_VECTORS_H
#define SUM_OF_VECTORS_H
#include <vector>
#include <string>
#include <cassert>


std::vector<std::string> operator+ (const std::vector<std::string>& left, const std::vector<std::string>& right)
{
	assert(left.size() == right.size());
	std::vector<std::string> answer;

	std::string resultData;
	for (size_t i = 0; i < left.size(); i++)
	{
		resultData += left[i];
		resultData += " ";
		resultData += right[i];
		answer.push_back(resultData);
		resultData.erase();
	}

	return answer;
}




#endif // !SUM_OF_VECTORS_H
