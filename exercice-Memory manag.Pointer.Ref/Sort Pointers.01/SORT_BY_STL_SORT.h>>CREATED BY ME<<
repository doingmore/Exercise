#ifndef SORT_BY_WITH_SORT
#define SORT_BY_WITH_SORT

#include <algorithm>
#include "Company.h"


bool (*global) (const Company& a, const Company& b) = NULL;   // in function internalSort now I can accessed global

bool internalSort(Company* begin, Company* end)
{
	return global(*begin, *end);
}

void sortBy(Company** begin, Company** end, bool sort(const Company& a, const Company& b))
{
	global = sort; // address on global is asigned on sort(function in SortPointersWithSkeletons.cpp)

	std::sort(begin, end, internalSort);
}

#endif // !SORT_BY_WITH_SORT

