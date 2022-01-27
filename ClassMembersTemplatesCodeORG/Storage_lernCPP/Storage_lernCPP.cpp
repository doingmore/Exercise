#include <iostream>

#include "myHeader.h"
#include <iomanip>


int main()
{
    storage8<int> intStorage; //Define storage for integers

	for (int i = 0; i < 8; i++)
	{
		intStorage.set(i);
	}

	for (int i = 0; i < 8; i++)
	{
		std::cout << intStorage.get(i) << '\n';
	}

	storage8<double> doubleStorage; //Define storage for double

	double number;
	std::setprecision(4);
	for (int i = 0; i < 8; i++)
	{
		number = i + 0.2;
		doubleStorage.set(i , number );
	}

	for (int i = 0; i < 8; i++)
	{
		std::cout << doubleStorage.get(i) << '\n';
	}

}
