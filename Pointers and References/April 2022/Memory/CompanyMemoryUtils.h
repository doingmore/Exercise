#ifndef COMPANY_MEMORY_UTILS_H
#define COMPANY_MEMORY_UTILS_H
#include "Company.h"
#include <vector>

typedef unsigned char byte; // ?? pass by this typedef, how can i assigned to parameter ??

std::vector<Company> readCompaniesFromMemory(const byte* array , const int& numCompanies ) // pointerf only address editable  
{
	std::vector<Company> list;
	std::vector < std::pair<char, char>> employes;
	std::string name;
	bool flagForID = true;
	int id{0};
	int numEmployees{ 0 };
	char firstInitial;
	char secondInitial;
	for (int i = 0; i < numCompanies ; i++)
	{
		flagForID = true;

		while (*array != '\0' )
		{
			if (flagForID)
			{
				id = *array;
				flagForID = false;
				array++;
			}
			name += *array;
			array++;
		}
		array++;
		numEmployees = *array;
		array++;
		for (int k = 0; k < numEmployees; k++)
		{
			firstInitial = *array;
			array++;
			secondInitial = *array;
			if (i != numCompanies-1) // prevent pointer to go on terminate char at dinamically array 
			{
			array++; 
			}
			employes.push_back(std::pair<char,char>(firstInitial, secondInitial));
		}

		list.emplace_back(Company{ id,name,employes });
		name.clear();
		employes.clear();
	}
return list;
}



#endif // !COMPANY_MEMORY_UTILS_H
