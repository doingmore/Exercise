#include <iostream>
#include <vector>

#include "Company.h"
#include "RemoveInvalid.h"


void removeInvalid(std::vector<std::shared_ptr<Company> >& listMember)
{
	int numbersMember = listMember.size();
	int checkingDigit{ 0 };
	for (int i=0; i < numbersMember; i++)
	{
		checkingDigit = listMember[i]->getID();
		if (checkingDigit < 0)
		{
			std::shared_ptr<Company> *ptrCopy= &listMember[i];
			delete ptrCopy;  //  not work correct ?????
			//listMember[i]->~Company();   //  not work correct ?????    //delete listMember[i]
		}
	}
}
