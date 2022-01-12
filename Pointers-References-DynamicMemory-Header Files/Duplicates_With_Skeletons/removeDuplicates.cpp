#ifndef RemoveDuplicates_H
#define RemoveDuplicates_H
#include <list>
#include <set>

#include "Company.h"

void removeDuplicates(std::list<Company*>& companies)
{
	std::set<std::string> uniques;

	std::string currCompanyName;
	std::list<Company*>::iterator it;
	for (it = companies.begin(); it != companies.end();)
	{
		currCompanyName = (*it)->getName();

		if (uniques.find(currCompanyName) == uniques.end())
		{
			uniques.insert(currCompanyName);
			++it;
		}
		else
		{
			it = companies.erase(it);
		}
	}
}

#endif // !RemoveDuplicates_H