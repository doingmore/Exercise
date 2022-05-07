#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H
#include <map>
#include <string>
#include "Company.h"


int getNmberCompany(const std::string& str)
{
	int counter{ 0 };

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '\n')
		{
			counter++;
		}
	}

	return counter;
}
int checkCriterion(const Company& o , std::string func(const Company& c))
{
	int criterion{0};
	std::string name{o.getName()};
	std::string id{ std::to_string( o.getId() ) };
	if ( func(o) == id )
	{
		criterion = 1;
	}
	else if (func(o) == name)
	{
		criterion = 2;
	}
	else if (func(o) == name+id )
	{
		criterion = 3;
	}
	return criterion;
}
Company* parseUniqueCompanies(const std::string& str, int& numCompanies, std::string func(const Company& c))
{
	numCompanies = getNmberCompany(str);
	std::istringstream stream(str);
	std::string name;
	std::string idSTR;
	int id;
	stream >> idSTR >> name;
	id = stoi(idSTR);
	int criterion{ checkCriterion(Company { id,name },func) };
	std::map<int, std::string> finalList;
	finalList.emplace(id, name);
	for (int i = 0; i < numCompanies; i++)
	{
		stream >> idSTR >> name;
		id = stoi(idSTR);
		if ( !finalList.count(id) )
		{
			finalList.emplace(id,name);
		}
	}
	numCompanies = finalList.size();

	Company* answerPtr = new Company[numCompanies];
	std::map<int, std::string>::iterator it = finalList.begin();
	for (int i = 0; i < numCompanies; i++)
	{
		answerPtr[i] = Company{it->first,it->second};
		it++;
	}
	


	return answerPtr;
}


#endif // !PARSE_COMPANIES_H
