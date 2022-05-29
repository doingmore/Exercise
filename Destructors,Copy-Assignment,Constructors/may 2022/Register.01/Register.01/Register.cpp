#include "Register.h"
#include "Company.h"

#include <cassert>
#include<iostream>

#define begin 0  // begin companiesArray

Register::Register(size_t numCompanies) : numAdded{0}
{
	companiesArray = new Company[numCompanies]{};
	std::cout << "Constructor" << '\n';
}

void Register::add(const Company& c)
{
	companiesArray[numAdded] = c;
	numAdded = numAdded + 1;
}

Company Register::get(int companyId) const
{
	for (size_t i = 0; i < numAdded; i++)
	{
		if (companiesArray[i].getId() == companyId)
		{
			return companiesArray[i];
		}
	}
	return companiesArray[begin];
}


Register::~Register()
{
	delete[] companiesArray;
	std::cout << "Destructor" << '\n';
}