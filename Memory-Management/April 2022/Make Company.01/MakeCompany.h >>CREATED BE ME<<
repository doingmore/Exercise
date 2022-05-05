#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H
#include <vector>

char getFirstChar(std::string& str)
{
	char c = str[0];
	return c;
}
char getSecondChar(std::string& str)
{
	char c = str[1];
	return c;
}

std::shared_ptr<Company> makeCompany(const std::vector<std::string>& companies)
{
	std::string idStr;
	int id;
	std::string name;
	std::vector<std::pair<char, char> > initials;
	idStr = companies[0];
	id = stoi(idStr);
	name = companies[1];
	std::string initialsSTR;
	char first;
	char second;
	for (size_t i = 2; i < companies.size(); i++) // every time vector companies will be gradest or equal to 2
	{
		initialsSTR = companies[i];
		first = getFirstChar(initialsSTR);
		second = getSecondChar(initialsSTR);
		initialsSTR.clear();
		initials.emplace_back(std::pair<char, char>(first, second));
	}

	return std::make_shared<Company>(id,name,initials);
}
 

#endif // !MAKE_COMPANY_H
