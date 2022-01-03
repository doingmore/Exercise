#include <iostream>
#include <algorithm>

#include "Company.h"
#include "SortBy.h"


bool (*globalComparator)(Company& a, Company& b) = nullptr;


bool internalSort(Company* begin, Company* end)
{
	return globalComparator(*begin, *end);
}


void sortBy(Company** begin, Company** end,
	bool(*sortBy)(Company& a, Company& b))
{
	globalComparator = sortBy;
	std::sort(begin, end, internalSort);
}