#include "ArrayOfPointers.h"
#include "Company.h"



size_t ArrayOfPointers::getSize()
{ 
	return arrayOfPtr.size(); 
}

Company* ArrayOfPointers::get(size_t& index)
{
	return this->arrayOfPtr[index];
}

void ArrayOfPointers::add(Company*& c)
{
	this->arrayOfPtr.emplace_back(c);
}
