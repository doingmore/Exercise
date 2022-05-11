#ifndef SUM_OF_VECTORS_H
#define SUM_OF_VECTORS_H

#include <string>
#include <vector>

std::vector<std::string> operator+ (const std::vector<std::string>& left , const std::vector<std::string>& right)
{
	std::vector<std::string> answer;
	std::string in;
	for (size_t i = 0; i < left.size(); i++) // the size of left and right vector, every time is same 
	{
		in +=left[i];
		in += ' ';
		in += right[i];
		answer.push_back(in);
		in.erase();
	}
	return answer;
}


#endif // !SUM_OF_VECTORS_H
