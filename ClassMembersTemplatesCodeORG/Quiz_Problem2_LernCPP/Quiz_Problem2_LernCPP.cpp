#include <iostream>

#include "myClass.h"

int main()
{
	Pair<int, double> p1{ 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2{ 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}