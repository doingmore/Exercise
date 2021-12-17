#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

#include "Company.h"
#include "RemoveInvalid.h"

using namespace std;

/*
123 valid
-123 invalid
321 ancientmarinerinc
end
*/



int main()
{
    string idstr; // ID must be integer number, because is firt input, must be checked for "end"
    int id;
    string name;
	int numberOfMember{ 0 };
	shared_ptr<Company> memberCopy;
	vector<shared_ptr<Company> > listMember;   // This is list with members 
    while (idstr != "end")
    {
        cin >> idstr;
        if (idstr == "end")
        {
            break;
        }
        id = stoi(idstr);
        cin >> name;
		shared_ptr<Company> member = make_shared<Company>(id,name);
		memberCopy = member;
		listMember.push_back(memberCopy);
		numberOfMember++;
    }
	

    removeInvalid(listMember);

    printMembers(listMember);


    return 0;
}