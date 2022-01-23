#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Parser.h"
#include "PrintUtils.h"


template<typename T>
void printVector(const std::vector<T>& vector)
{
	for (auto i = vector.begin(); i != vector.end(); i++)
	{
		std::cout << *i << " ";
	}
}