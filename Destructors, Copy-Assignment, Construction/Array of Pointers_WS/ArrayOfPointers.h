#ifndef ArrayOfPointers_H
#define ArrayOfPointers_H
#include <vector>

class ArrayOfPointers
{
private:
	std::vector <Company*> arrayOfPtr;
public:
	ArrayOfPointers() {};

	void add(Company* &c)
	{
		this->arrayOfPtr.emplace_back(c);
	}

	size_t getSize() { return arrayOfPtr.size(); }

	Company* get (size_t &index)
	{
		return this->arrayOfPtr[index];
	}
};

#endif // !ArrayOfPointers_H
