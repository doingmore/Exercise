#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H
#include <vector>


#include"Company.h"

class ArrayOfPointers
{
private:
	std::vector<Company*> m_data;
public:
	ArrayOfPointers() {}

	void add(Company* object);
	size_t getSize() const ;

	Company* get(const int& positionInList);

	~ArrayOfPointers();

	// Rule of three 
	ArrayOfPointers(const Company& object) = delete;
	ArrayOfPointers operator=(const ArrayOfPointers& object) = delete;

};


#endif // !ARRAY_OF_POINTERS_H
