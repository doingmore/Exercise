#include <iostream>
#include <vector>

#include "Company.h"
#include "Find.h"

std::string findCompany(std::string& searchMember, std::vector<Company>& list)
{
	int searchID = stoi(searchMember); // string from numbers to int numbers
	std::string answer = "not found";

	std::vector<Company>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (it->getId() == searchID)
		{
			answer = it->getName();
		}
	}

	return answer;
}