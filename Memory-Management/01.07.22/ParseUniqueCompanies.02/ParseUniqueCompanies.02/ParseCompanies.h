#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#define begin_zero 0





int getNumberCompanies(const std::string& input)
{
	int answer{0};
	for (size_t i = 0; i < input.size(); i++)
	{
		if (input[i] == '\n')
		{
			answer++;
		}
	}
	return answer;
}

bool check_for_id(const int& search_id, const std::vector<Company>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i].getId() == search_id )
		{
			return false;
		}
	}
	return true;
}

std::vector<Company> remove_element(const Company* remove,const std::vector<Company>& vec)
{
	std::vector<Company> answer;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (remove->getId() == vec[i].getId())
		{
			// do nothing
		}
		else
		{
			answer.push_back(vec[i]);
		}
	}

	return answer;
}





Company* parseUniqueCompanies(const std::string& input, int& valid_numbers_companies, std::string(*func)(const Company& c) )
{
	Company* answer = NULL;
	std::istringstream in(input);
	std::vector<Company> vec;
	int number_iterations = getNumberCompanies(input);
	for (int i = begin_zero; i < number_iterations; i++)
	{
		int id;
		std::string name;
		in >> id;
		in >> name;
		if (check_for_id(id,vec) ) // only unique id
		{
			vec.emplace_back(Company{ id,name });
		}
	}

	valid_numbers_companies = vec.size();
	answer = new Company[valid_numbers_companies];
	bool flag_ready = false;
	int index_answer{ begin_zero };
	while (!flag_ready)
	{
		Company* early_company = &vec[begin_zero];
		for (int i = begin_zero+1; i < vec.size(); i++)
		{
			if ( func(vec[i]) < func(*early_company) )
			{
				early_company = &vec[i];
			}
		}
		

		answer[index_answer] = *early_company;  // call default copy CTR
		vec = remove_element(early_company,vec);
		if (vec.empty())
		{
			flag_ready = true;
		}
		else
		{
			index_answer++;
		}
	}


	
	



	return answer;
}


#endif // !PARSE_COMPANIES_H
