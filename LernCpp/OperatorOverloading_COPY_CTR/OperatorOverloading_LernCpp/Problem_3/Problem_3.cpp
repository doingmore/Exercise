#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <cassert>

#include "IntArray.h" // that is my file, where I implement necessary

/*
3. Write your own integer array class named IntArray from scratch (do not use std::array or std::vector).
Users should pass in the size of the array when it is created, and the array should be dynamically allocated.
Use assert statements to guard against bad data. Create any constructors or
overloaded operators needed to make the following program operate correctly:
*/



// skeleton
IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}
// skeleton