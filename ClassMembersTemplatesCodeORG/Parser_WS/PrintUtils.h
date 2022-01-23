#ifndef PrintUtils_H
#define PrintUtils_H
#include <iostream>
#include <vector>
#include <string>

template<typename T>
void printVector(const std::vector<T>& vector)
{
	for (auto i = vector.begin(); i != vector.end(); i++)
	{
		std::cout << *i << " ";
	}
}

#endif // !PrintUtils_H