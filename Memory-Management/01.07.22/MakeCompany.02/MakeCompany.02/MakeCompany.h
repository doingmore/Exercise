#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"
#include <string>
#include <vector>

#define first 0 // for ID and first letter on employ
#define second 1 // for name and second letter on employ


std::shared_ptr <Company> makeCompany(const std::vector<std::string>& input)
{
	int id;
	std::string name;
	std::vector<std::pair<char, char> > employees;
	for (size_t i = 0; i < input.size(); i++)
	{
		std::string in{ input[i] };
		if (i == first)
		{
			id = stoi(in);
		}
		else if (i == second)
		{
			name = input[i];
		}
		else
		{
			char a;
			char b;
			a = in[first];
			b = in[second];
			employees.emplace_back( std::pair<char, char>(a, b) );
		}
	}
	
	std::shared_ptr <Company> shared_ptr(new Company{ id,name,employees });

	return shared_ptr;
}






#endif // !MAKE_COMPANY_H
