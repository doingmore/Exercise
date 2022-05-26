#include "Register.h"
#include <string>
#include <iostream>

Register::Register(size_t numCompanies)
{
	this->companiesArray = new Company [numCompanies];
	numAdded=numCompanies;
}

void Register::add(const Company& c)
{
	int index{ 0 };
	while (true)
	{
		if (companiesArray[index].getId() > 0)
		{
		}
		else
		{
			companiesArray[index] = c;
			break;
		}
		index++;
	}
}

Company Register::get(int companyId) const
{
	for (size_t i = 0; i < this->numAdded; i++)
	{
		if (companyId == ( this->companiesArray[i].getId() ) )
		{
			return this->companiesArray[i];
		}
	}

	return Company();
}

Register::~Register()
{
	std::cout << "hello I'm a destructor" << '\n';
	delete [] companiesArray;
}

/*
1
2
42 theanswer
69 thehub
69
end
*/