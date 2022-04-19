#include <iostream>
#include <vector>

#include "Company.h"
#include "OrderedInserter.h"

void printInfoAllCompanies(std::vector<OrderedInserter>& listCompanies)
{

	for (std::vector<OrderedInserter> rangeBasedforloop :  listCompanies)
	{

	}


	std::vector<OrderedInserter>::iterator it;
	for (it = listCompanies.begin(); it != listCompanies.end(); it++)
	{
		std::cout << it->getName() << " " << it->getID() << '\n';
	}
}