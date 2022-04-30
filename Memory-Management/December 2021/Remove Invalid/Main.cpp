#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

#include "Company.h"
#include "RemoveInvalid.h"

/*
123 valid
-123 invalid
321 ancientmarinerinc
end
*/

int main()
{
    std::string idstr; // ID must be integer number, because is firt input, must be checked for "end"
    int id;
    std::string name;
	int numberOfMember{ 0 };
	std::shared_ptr<Company> memberCopy;
	std::vector<std::shared_ptr<Company> > listMember;   // This is list with members 
    while (idstr != "end")
    {
        std::cin >> idstr;
        if (idstr == "end")
        {
            break;
        }
        id = stoi(idstr);
        std::cin >> name;
		std::shared_ptr<Company> member = std::make_shared<Company>(id,name);
		memberCopy = member;
		listMember.push_back(memberCopy);
		numberOfMember++;
    }
	
    removeInvalid(listMember);

    printMembers(listMember);


    return 0;
}