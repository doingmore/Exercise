#include <iostream>
#include <vector>

#include "Company.h"
#include "RemoveInvalid.h"


void printMembers(std::vector<std::shared_ptr<Company> >& listMember)
{
	int numbersMember = listMember.size();
	for (int i = 0; i < numbersMember; i++)
	{
		std::cout << listMember[i]->getID() << " " << listMember[i]->getName() << '\n';
	}
}