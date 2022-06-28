#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H

#include <string>
#include <vector>

#include "Company.h"

class ArrayOfPointers
{
private:
	std::vector<Company*> m_list;
public:
	ArrayOfPointers(){}

	void add(Company* const object)
	{
		m_list.emplace_back(object);
	}

	size_t getSize() const { return m_list.size(); }

	Company* get(const size_t& n) const { return m_list[n];}

	ArrayOfPointers(const Company& other) = delete;
	ArrayOfPointers& operator= (const ArrayOfPointers& other) = delete;
	~ArrayOfPointers()
	{
		for (size_t i = 0; i < m_list.size(); i++)
		{
		delete m_list[i];
		}
	}
};



#endif // !ARRAY_OF_POINTERS_H
