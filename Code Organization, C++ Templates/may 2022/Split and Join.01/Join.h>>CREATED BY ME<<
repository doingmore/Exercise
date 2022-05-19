#ifndef JOIN_H
#define JOIN_H
#include <vector>
#include <string>
#include <sstream>

template<typename T>
std::string join(const std::vector<T>& vec ,const std::string& symbolSpoil)
{
	std::string answer;
	std::stringstream stream;
	std::string element;
	for (size_t i = 0; i < vec.size(); i++)
	{
		stream << vec[i];
		while (stream >> element)
		{
			answer += element;
		}
		if (i != (vec.size()-1) )
		{
		answer += symbolSpoil;
		}
		stream.clear();
	}
	return answer;
}






#endif // !JOIN_H
