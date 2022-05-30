#include "Company.h"
#include "Register.h"

#define begin 0

Register::Register(size_t numCompanies)
{
	companiesArray = new Company[numCompanies]{};
	numAdded = begin;
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
	return companiesArray[begin]; // if not have this searching id , return first company
}

Register::~Register()
{
	delete[] companiesArray;
}

Register::Register(const Register& other)
{
	numAdded = other.numAdded;
	companiesArray = new Company[numAdded]{};
	for (size_t i = 0; i < numAdded; i++)
	{
		companiesArray[i] = other.companiesArray[i];
	}
}

Register& Register::operator=(const Register& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (companiesArray)
	{
		delete[] companiesArray;
	}

	numAdded = other.numAdded;
	companiesArray = new Company[numAdded]{};
	for (size_t i = 0; i < numAdded; i++)
	{
		companiesArray[i] = other.companiesArray[i];
	}

	return *this;
}