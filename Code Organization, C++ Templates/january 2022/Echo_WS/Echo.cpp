#include "Echo.h"

#include <iostream>
#include <string>

bool echoOn=true;

void echo(const std::string& massage)
{
	if (echoOn)
	{
		std::cout << massage << '\n';
	}
}