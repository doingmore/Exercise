#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H
#include <vector>

template<typename T>
void printVector(std::vector<T>& vec)
{
	for (T element : vec)
	{
		std::cout << element << " ";
	}
}

#endif // !PRINT_UTILS_H
