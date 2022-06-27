#include <cassert>
#include <sstream>
#include <iostream>
#include <string>

#include "Register.h"
#include "Company.h"

#define begin 0

Register::Register(size_t num_companies) : numAdded{ begin }
{
	assert(num_companies >= 0);
	companiesArray = new Company[num_companies]{};
	std::cout << "Constructor has been performed" << '\n';
}

void Register::add(const Company& c)
{
	companiesArray[numAdded] = c;
	numAdded++;
}

Company Register::get(int companyId) const
{
	for (size_t i = 0; i < numAdded; i++)
	{
		if (companiesArray[i].getId() == companyId )
		{
			return companiesArray[i];
		}
	}
	return companiesArray[begin]; // if no have match, return first company
}

Register::~Register()
{
	delete[] companiesArray;
	companiesArray = NULL;
	std::cout << "Destructor has been performed" << '\n';
}