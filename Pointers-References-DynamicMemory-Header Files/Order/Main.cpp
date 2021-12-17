#include <iostream>
#include <vector>
#include <map>

#include "Company.h"
#include "OrderedInserter.h"

using namespace std;

int main()
{
	vector<OrderedInserter> listCompanys;
	map<int,string> orderedID; //saving ID in increase order
	string inputName;
	int inputID;

	//input info in map 
	while (inputName != "end")
	{
		cin >> inputName;
		if (inputName =="end")
		{
			break;
		}
		cin >> inputID;
		orderedID.insert(pair<int,string>(inputID,inputName));
	}

	//input info from ordered map to vector
	map<int, string>::iterator it;
	for ( it = orderedID.begin(); it != orderedID.end(); it++)
	{
		listCompanys.push_back(OrderedInserter(it->second, it->first));
	}

	getInfoAllCompanys(&listCompanys);

	return 0;
}
