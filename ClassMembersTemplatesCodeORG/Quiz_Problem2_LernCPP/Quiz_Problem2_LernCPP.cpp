#include <iostream>

#include "myClass.h"

/*
Write a Pair class that allows you to specify separate types for each of the two values in the pair.
Note: We’re naming this class differently from the previous one because C++ does not currently allow
you to “overload” classes that differ only in the number or type of template parameters.

The following program should work:
*/

int main()
{
	Pair<int, double> p1{ 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2{ 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
