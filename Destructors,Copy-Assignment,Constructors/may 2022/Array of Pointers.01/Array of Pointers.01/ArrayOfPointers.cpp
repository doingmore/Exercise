#include "ArrayOfPointers.h"
#include "Company.h"
#include <iostream>
#include <vector>


void ArrayOfPointers::add(Company* object)
{
	m_data.emplace_back(object);
}

size_t ArrayOfPointers::getSize() const
{
	return m_data.size();
}

Company* ArrayOfPointers::get(const int& positionInList)
{
	return m_data[positionInList] ;
}

ArrayOfPointers::~ArrayOfPointers()
{
	for (Company* p : m_data)
	{
		delete p;
		p = NULL;
	}
	std::cout << "destructor" << '\n';
}