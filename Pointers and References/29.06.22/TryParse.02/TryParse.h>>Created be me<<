#ifndef TRY_PARSE_H
#define TRY_PARSE_H
#include <string>
#include <sstream>

bool tryParse(const std::string& str, int& answer)
{
	if (std::isdigit(str[0]))
	{
		std::istringstream stream(str);
		stream >> answer;
		return true;
	}

	return false;
}


#endif // !TRY_PARSE_H
