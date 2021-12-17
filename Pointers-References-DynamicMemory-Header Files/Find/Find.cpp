#include <iostream>
#include <vector>

#include "Company.h"
#include "Find.h"


std::string findCompany(std::string  *searchMember, std::vector<Company> *list)
{
	int searchID = stoi(*searchMember); // string from numbers to int numbers
	std::string answer; 
	std::vector<Company> listWithCompanys=*list; 

	std::vector<Company>::iterator it;
	for (it = listWithCompanys.begin(); it != listWithCompanys.end(); it++)
	{
		if (it->getId() == searchID)
		{
			answer = it->getName();
		}
	}
	
	return answer;
}