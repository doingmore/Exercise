#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H
#include <list>
#include <string>
#include "Company.h"

bool find(const Company* search , const std::list<Company*>& list)
{
	for (Company* p : list)
	{
		if ( search == p )
		{
			return true;
		}
	}
	return false;
}

void removeDuplicates(std::list<Company*>& companies)
{
	std::list<Company*> newList;

	for ( Company* p : companies )
	{
		if ( !find(p,newList) )
		{
			newList.push_back(p);
		}
	}
	companies.clear();
	companies = newList;
	newList.clear();
}

#endif // !REMOVE_DUPLICATES_H
