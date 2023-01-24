#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <utility>
#include "Person.h"


int main()
{
	unsigned int a{0};
	std::cin>>a;

	for (int i = 1; i <= a; i++)
	{
        if (a % i == 0)
		{
            std::cout <<" " << i;
		}
	}

	return 0;
}