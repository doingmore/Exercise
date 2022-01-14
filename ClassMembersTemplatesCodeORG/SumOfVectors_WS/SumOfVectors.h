#ifndef SumOfVectors
#define SumOfVectors
#include <vector>
#include <string>

std::vector<std::string> operator+(const std::vector<std::string> &a, const std::vector<std::string> &b)
{
	std::vector<std::string> answer;
	std::string input;

	for (unsigned int i = 0; i < a.size(); i++)
	{
		input += a[i];
		input += " ";
		input += b[i];
		answer.emplace_back(input);
		input.clear();
	}

	return std::vector<std::string>(answer);
}

#endif // !SumOfVectors
