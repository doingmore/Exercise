#include <iostream>
#include <vector>
#include <map>

#include "Company.h"
#include "OrderedInserter.h"

std::vector<OrderedInserter> insert(std::map<int, std::string>& orderedID)
{
	std::vector<OrderedInserter> listCompanies;

	std::map<int, std::string>::iterator it;
	for (it = orderedID.begin(); it != orderedID.end(); it++)
	{
		listCompanies.push_back(OrderedInserter(it->second, it->first));
	}

	return listCompanies;
}

int main()
{
	//std::vector<OrderedInserter> listCompanys;
	std::map<int,std::string> ordered; //saving ID in increase order
	std::string inputName;
	int inputID;

	//input info in map 
	while (inputName != "end")
	{
		std::cin >> inputName;
		if (inputName =="end")
		{
			break;
		}
		std::cin >> inputID;
		ordered.insert(std::pair<int,std::string>(inputID,inputName));
	}

	std::vector<OrderedInserter> listCompanies = insert(ordered);  //input info from ordered map to vector

	printInfoAllCompanies(listCompanies);

	return 0;
}
