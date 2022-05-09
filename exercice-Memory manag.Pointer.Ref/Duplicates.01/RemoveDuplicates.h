#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include <string>
#include <set>
#include <list>

#include "Company.h"

void removeDuplicates(std::list<Company*>& list)
{
	std::set<std::string> register_name;
	std::list<Company*> temporarity;
	for (Company* &p : list)
	{	
		if ( !register_name.count( p->getName() ) )
		{
		register_name.insert(p->getName());	
		temporarity.push_back(p);
		}
	}
	list.clear();
	list = temporarity; //copy
}


#endif // !REMOVE_DUPLICATES_H

