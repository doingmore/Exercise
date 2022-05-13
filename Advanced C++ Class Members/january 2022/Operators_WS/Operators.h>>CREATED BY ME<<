#ifndef Operators
#define Operators
#include <string>
#include <sstream>

std::vector<std::string>& operator<< (std::vector<std::string> &vector,std::string &str)
{
	vector.push_back(str);
	return vector;
}

std::string& operator+ (std::string &left, int &right)
{
	std::string intSTR = std::to_string(right);
	left += intSTR;
	return left;
}

std::string& operator+ (std::string &left, const size_t &right)
{
	std::string length = std::to_string(right);
	left += length; 
	return left;
}

std::ostream& operator<< (std::ostream& os, const std::vector<std::string>& vector)
{
	for (auto elementFromVector : vector)
	{
		os << elementFromVector << '\n';
	}
	return os;
}

#endif // !Operators
