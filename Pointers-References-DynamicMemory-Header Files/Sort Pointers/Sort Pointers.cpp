#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Company.h"
#include "SortBy.h"

/*
acme 424242420
softuni_foundation 20140414
itjoro 878968302
end
id
*/

/* cpp
bool (*globalComparator)( Company& a,  Company& b) = nullptr;


bool internalSort(Company* begin, Company* end)
{
	return globalComparator(*begin, *end);
}


void sortBy(Company** begin, Company** end,
	bool(*sortBy)( Company& a, Company& b))
{
	globalComparator = sortBy;
	std::sort(begin, end, internalSort);
}
*/

bool lessThanById(Company& a, Company& b)
{
	return a.getId() < b.getId();
}

bool lessThanByName(Company& a, Company& b)
{
	return a.getName() < b.getName();
}


int main()
{
	std::vector<std::string> lines;
	std::string line;
	//std::getline(std::cin, line);
	std::stringstream lineIn;

	while (line != "end")
	{
		std::getline(std::cin, line);
		if (line == "end")
		{
			break;
		}
		lines.push_back(line);
		lineIn << line;
	}

	std::string name;
	int id;
	int numCompanies = lines.size();
	Company** companyPtrs = new Company * [numCompanies];
	for (size_t i = 0; i < lines.size(); i++)
	{
		//std::istringstream lineIn(line);
		lineIn >> name >> id;
		companyPtrs[i] = new Company(id, name);
	}

	std::string choice;
	std::cin >> choice;

	if (choice == "name")
	{                     //   begin          end
		sortBy(companyPtrs, companyPtrs + numCompanies, lessThanByName);
	}
	else if (choice == "id")
	{                     //   begin           end  
		sortBy(companyPtrs, companyPtrs + numCompanies, lessThanById);
	}

	for (int i = 0; i < numCompanies; i++)
	{
		std::cout << companyPtrs[i]->toString() << '\n';
	}

	/*for (int i = 0; i < numCompanies; i++)       // not work
	{
		delete[] companyPtrs[i];
		companyPtrs[i] = nullptr;
		std::cout << "delete[i]" << '\n';
	}
	*/
	return 0;
}