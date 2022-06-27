#include "Register.h"
#include <cassert>

#define begin 0

Register::Register(size_t numCompanies) : numAdded{ begin }
{
	assert(numCompanies > 0);
	companiesArray = new Company[numCompanies]{};
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
		if (companiesArray[i].getId() == companyId)
		{
			return companiesArray[i];
		}
	}
	return companiesArray[begin]; // if no have match, return first element of companiesArray
}

Register::~Register()
{
	delete[] companiesArray;
	companiesArray = NULL;
}

Register& Register::operator=(const Register& other)
{
	// self assignment guard
	if (this == &other)
	{
		return *this;
	}

	if (companiesArray)
	{
		delete[] companiesArray; // this->companiesArray
	}
	
	numAdded = other.numAdded;
	
	companiesArray = new Company[numAdded]{};

	for (size_t i = 0; i < numAdded; i++)
	{
		companiesArray[i] = other.companiesArray[i];
	}

	return *this;
}

Register::Register(const Register& other) : numAdded{other.numAdded}
{
	companiesArray = new Company[numAdded]{};

	for (size_t i = 0; i < numAdded; i++)
	{
		companiesArray[i] = other.companiesArray[i];
	}
}