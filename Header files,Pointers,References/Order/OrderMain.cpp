#include <iostream>
#include <vector>

#include "Company.h"
#include "OrderedInserter.h"

void getInfoAllCompanys(std::vector<OrderedInserter>* listCompanys)
{
	std::vector<OrderedInserter> passedList = *listCompanys;
	std::vector<OrderedInserter>::iterator it;
	for (it = passedList.begin(); it != passedList.end(); it++)
	{
		std::cout << it->getName() << " " << it->getID() << '\n';
	}
}