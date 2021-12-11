#include <iostream>

#include "TryParse.h"


void checkParse(std::string *first, std::string *second)
{
	std::string checkString = *first;
	int potentialNumber{ 0 };
	int sum{ 0 };
	bool flag = false;
	
	for (int i = 0; i < 2; i++)
	{

		for (unsigned int j = 0; j < checkString.size(); j++)
		{
			if (checkString[i] >= '0' && checkString[i] <= '9')
			{
				// OK do nothing
			}
			else //print and stop
			{
				if (i == 1)
				{
					std::cout << sum << " [Error] " << checkString << '\n';
					flag = true;
					break;
				}
				std::cout << "[Error] " << checkString << " " << *second << '\n';
				flag = true;
				break;
			}
		}
		if ((i==1) && (flag != true))  // successful parse finish
		{
			potentialNumber = stoi(checkString);
			sum += potentialNumber;
			std::cout << sum << '\n';
			break;
		}
		else if (flag != true)
		{
		potentialNumber = stoi(checkString);
		sum += potentialNumber;
		checkString = *second;
		}
		else
		{
			break;
		}
	}
}
