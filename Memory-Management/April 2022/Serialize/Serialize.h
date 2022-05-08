#ifndef SERIALIZE_H
#define SERIALIZE_H
#include <sstream>
#include <vector>

#include "Company.h"

void getChar(std::string& str, std::vector<char>& localList)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		localList.push_back(str[i]);
	}
}

void getAllCharacters(const Company& o,std::vector<char>& localList)
{
	std::string name{o.getName()};
	int id{o.getId()};

	localList.push_back((char)id);
	getChar(name, localList);
	localList.push_back(0);
	std::vector<std::pair<char, char> > employees = o.getEmployees();
	size_t numberOfEmployes{ employees.size() };
	localList.push_back((char)numberOfEmployes);
	for (std::pair<char, char>  p : employees)
	{
		localList.push_back(p.first);
		localList.push_back(p.second);
	}
}



byte* serializeToMemory(const std::string& str, size_t& number )
{
	std::vector<char> localList;
	std::vector<Company> listCompaniesVector;

	std::istringstream companiesIn(str);
	Company company;
	while (companiesIn >> company )
	{
		listCompaniesVector.emplace_back(company);
	}

	size_t numberOfCompanies{ listCompaniesVector.size() };
	localList.push_back( (char)numberOfCompanies);
	for (Company c : listCompaniesVector)
	{
	getAllCharacters(c,localList);
	}

	number = localList.size();

	byte* arrayInt (new byte [number]) ;

	int counter{ 0 };
	for (byte c : localList)
	{
		arrayInt [counter] = c;
		counter++;
	}

	return arrayInt;
}


#endif // !SERIALIZE_H
