#include <iostream>

#include "myClass.h"

/*
A string-value pair is a special type of pair where the first value is always a string type,
and the second value can be any type. Write a template class named StringValuePair that inherits 
from a partially specialized Pair class (using std::string as the first type, and allowing the user to specify the second type).
*/


int main()
{
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}