#include "TryParse.h"

bool tryParse(const std::string& inputStr, int& a)
{
	if (isalpha(inputStr[0]))
	{
		return false;
	}
	else
	{
		a = stoi(inputStr);
	}
	return true;
}