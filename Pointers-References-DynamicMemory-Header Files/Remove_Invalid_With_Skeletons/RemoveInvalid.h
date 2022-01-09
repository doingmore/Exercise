#ifndef RemoveInvalid
#define RemoveInvalid
#include <list>
#include "Company.h"

void removeInvalid(std::list<Company*>& companies)
{
	unsigned int numberIteration = companies.size();
	bool flagClearInvalid = true;
	while (flagClearInvalid)
	{
		for (Company* ptr : companies)
		{
			flagClearInvalid = false;
			if (ptr->getId() < 0 )
			{
				companies.remove(ptr);
				delete ptr;
				ptr = NULL;
				flagClearInvalid = true;
				break;
			}
		}
	}
}


#endif // !RemoveInvalid
