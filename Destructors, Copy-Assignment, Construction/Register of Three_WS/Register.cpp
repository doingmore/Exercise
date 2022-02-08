#include "Register.h"

Register::Register(size_t numCompanies)
{

	this->companiesArray = new Company[numCompanies];
	this->numAdded = numCompanies;

}

void Register::add(const Company& c)
{
	for (size_t i = 0; i < this->numAdded; i++)
	{
		if (this->companiesArray[i].getId() > 0 )
		{
		}
		else
		{
			this->companiesArray[i] = c;
			break;
		}
	}
}

Company Register::get(int companyId) const
{
	for (size_t i = 0; i < this->numAdded; i++)
	{
		if (this->companiesArray[i].getId() == companyId)
		{
			return this->companiesArray[i];
			break;
		}
	}

	return this->companiesArray[0]; 
}

Register::~Register()
{
	delete[] companiesArray;
}

Register& Register::operator=(const Register& other) {

	if (this != &other) 
	{
		if (this->companiesArray != nullptr) 
		{
			delete[] this->companiesArray;
		}

		this->numAdded = other.numAdded;
		this->companiesArray = new Company[other.numAdded];

		int arrSize = (size_t)other.numAdded;
		for (int i = 0; i < arrSize; ++i) 
		{
			this->companiesArray[i] = other.companiesArray[i];
		}
	}
	return *this;
}

Register::Register(const Register& other) : numAdded(other.numAdded), companiesArray(other.companiesArray)
{
}


/*
1
2
42 theanswer
69 thehub
42
end
*/