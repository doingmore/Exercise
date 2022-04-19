#include <iostream>
#include <vector>

#include "Company.h"
#include "Find.h"

/*
acme 424242420
itjoro 878968302
softuni_foundation 20140414
end
878968302
*/


int main()
{
	std::vector<Company> companies;
	std::string inputName;
	int id{ 0 };

	std::string searchMember;

	while (inputName != "end")
	{
		std::cin >> inputName;
		if (inputName =="end")
		{
			break;
		}
		std::cin >> id;
		companies.push_back(Company( inputName,id));
	}

	std::cin >> searchMember; //ID on search member

	std::cout<<findCompany(searchMember,companies)<<" "<<searchMember<<'\n';

    return 0;
}