#include <iostream>
#include <vector>

#include "Company.h"
#include "Find.h"

using namespace std;

int main()
{
	vector<Company> companys;
	string inputName;
	int id{ 0 };

	string searchMember;

	while (inputName != "end")
	{
		cin >> inputName;
		if (inputName =="end")
		{
			break;
		}
		cin >> id;
		companys.push_back(Company( inputName,id));
	}

	cin >> searchMember; //ID on search member

	cout<<findCompany(&searchMember,&companys)<<" "<<searchMember<<'\n';

    return 0;
}