#ifndef COMPANY_MEMORY_UTILS_H
#define COMPANY_MEMORY_UTILS_H
#include <string>
#include <vector>
#include <iostream>

#define begin 0

#include "Company.h"

std::vector<Company> readCompaniesFromMemory(unsigned char* array, const int& num_Companies)
{
	std::vector<Company> answer;

	bool flag = true;

	int counter{ 0 };
	while (flag)
	{
		// first step get ID
		char id = array[counter];
		int company_ID = (int)id;
		// second step get NAME
		counter++;
		std::string company_name;
		char temp;
		while (array[counter] != 0)
		{
			temp = array[counter];
			company_name += temp;
			counter++;
		}
		counter++;
		// third step get vector with pairs
		char num_employees = array[counter];
		int company_num_employees = (int)num_employees;
		counter++;
		std::vector<std::pair<char, char> > employees;
		for (int i = 0; i < company_num_employees; i++)
		{
			char first_char = array[counter];
			counter++;
			char second_char = array[counter];
			counter++;
			employees.emplace_back(std::pair<char, char>(first_char, second_char));
		}


		// create Company object and push at vector
		Company object{ company_ID , company_name , employees };
		answer.emplace_back(object);

		if (answer.size() == num_Companies)
		{
			break;
		}
	}

	return answer;
}






#endif // !COMPANY_MEMORY_UTILS_H
