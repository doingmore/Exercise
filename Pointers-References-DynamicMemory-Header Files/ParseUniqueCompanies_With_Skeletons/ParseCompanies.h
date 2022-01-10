#ifndef ParseCompanies
#define ParseCompanies
#include <string>
#include <sstream>
#include <list>
#include "Company.h"


Company* parseUniqueCompanies(std::string streamWithCompanies, int& numCompanies, std::string choseFunction(const Company& c))
{
	static std::list<Company*> myList;
	std::stringstream stream(streamWithCompanies);
	std::string name;
	std::string idSTR;
	int id;

	// for checking criteria
	std::string checkName;
	std::string checkId;
	while (stream >> idSTR >> name)
	{
		id = stoi(idSTR);
		Company* ptr = new Company(id, name);
		myList.push_back(ptr);

		if (myList.size() > 1) // do check
		{
			for (Company* p : myList)
			{
				if (p == ptr)// same address, pointer to same object 
				{
					break;
				}
				checkName = p->getName();
				checkId = std::to_string(p->getId());
				if (checkId + checkId == choseFunction(*ptr))
				{
					myList.remove(ptr);
					delete ptr;
					ptr = NULL;
					break;
				}
				else if (checkName == choseFunction(*ptr))
				{
					myList.remove(ptr);
					delete ptr;
					ptr = NULL;
					break;
				}
				else if (checkId == choseFunction(*ptr))
				{
					myList.remove(ptr);
					delete ptr;
					ptr = NULL;
					break;
				}
			}
		}
	}
	numCompanies = myList.size();

	std::list<Company*>::iterator answer = myList.begin();
	for (int i=0; i< 1; i++)
	{
		return *answer;
	}
}

#endif // !ParseCompanies
