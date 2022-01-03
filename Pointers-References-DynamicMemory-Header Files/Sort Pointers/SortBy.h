#ifndef SortBy_H
#define SortBy_h

void sortBy(Company** begin, Company** end,
	bool(*sortBy)(Company& a, Company& b));

#endif // !SortBy_H
