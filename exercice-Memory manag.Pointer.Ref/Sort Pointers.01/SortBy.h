#ifndef SORT_BY_h
#define SORT_BY_h

#include "Company.h"

int get_num_companies(Company** companyPtrs, Company** end)
{
	int answer{ 0 };
	for (Company** i = companyPtrs; i != end; i++)
	{
		answer++;
	}
	return answer;
}

void swap(Company** left, Company** right)
{
	Company* ptr_temp= *right ;
	*right = *left;
	*left = ptr_temp;
}


void sortBy(Company** companyPtrs, Company** end, bool func(const Company& a, const Company& b))
{
	int size_array_companies{ get_num_companies(companyPtrs,end) };
	
	Company** temporary = companyPtrs;
	while (size_array_companies--)
	{
		for (Company** i = temporary; i != end; i++) 
		{
			if ( func(**i , **temporary) ) // return true if right is grather
			{
				swap(i,temporary);
			}
		}
		if (size_array_companies > 0)
		{
		temporary++;
		}
	}
}

#endif // !SORT_BY_h
