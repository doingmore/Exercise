#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include <string>
#include "Company.h"
#include <list>

#define zero 0


void removeInvalid( std::list<Company*>& companies)
{
	std::list < Company* > temporarity;
	for (Company* operate : companies)
	{
		if (operate->getId() < zero)
		{
			delete operate;
			operate = NULL;
		}
		else
		{
			temporarity.push_back(operate);
		}
	}
	companies.clear();
	companies = temporarity;
	temporarity.clear();
}


#endif // !REMOVE_INVALID_H
