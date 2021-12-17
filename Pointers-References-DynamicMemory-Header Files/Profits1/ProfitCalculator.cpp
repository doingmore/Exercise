#include <iostream>
#include <vector>
#include <map>

#include "Company.h"


void getProfitReport(std::vector<Company> *list, std::map<int, int> *ptID_Tax)
{
	std::map<int, int> iD_Tax = (*ptID_Tax);
	int searchedID{ 0 };
	int fulCosts{ 0 };

	std::map<int, int>::iterator it = iD_Tax.begin();
	for (unsigned  int i= 0; i < (*list).size(); i++)
	{
		searchedID=(*list)[i].getID();
		it = iD_Tax.begin();  // resetting key in map on first possibility position
		for (unsigned j = 0; j < (iD_Tax).size(); j++)
		{

			if (searchedID == (it->first))
			{              //                   percentage %                  //    //        costs        //
				fulCosts = ( ( (*list)[i].getRevenue() ) * ((it->second)*0.01) ) + ( (*list)[i].getCosts() );

				std::cout << (*list)[i].getName() << " = " << ( ((*list)[i].getRevenue()) - fulCosts )<<'\n';
				break;
			}

			it++; // next key from map relevant on ID 
		}
	}
	
}