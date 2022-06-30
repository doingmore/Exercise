#ifndef FIND_H
#define FIND_H

#include <string>
#include <vector>

Company* find(const std::vector<Company*>& list , const int& search_id )
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i]->getId() == search_id)
		{
			return list[i];
		}
	}
	return NULL;
}


#endif // !FIND_H
