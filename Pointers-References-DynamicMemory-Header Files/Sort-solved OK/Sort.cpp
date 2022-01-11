#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

#include "Company.h"

/*
acme 424242420
softuni_foundation 20140414
itjoro 878968302
end
id
*/

std::vector<Company> populateCompaniesFromInput()
{
    std::vector<Company> companies;
    std::string input = " begin ";
    std::string companyID{ 0 };
    std::string companyName;
    int id{ 0 };

    while (input != "end")
    {
        std::getline(std::cin, input);
        if (input == "end")
        {
            return companies;
            break;
        }
        std::istringstream istr(input);
        istr >> companyName >> companyID;
        id = stoi(companyID);
        companies.emplace_back(id, companyName);  //  OR  // companies.push_back(Company(id,companyName)) nut here is with copy;
    }
    return companies;
}


bool sortByID  (const Company &left,const Company &right)
{
    return (left.getId() < right.getId());
}

bool sortByName(Company& left, Company& right)
{
    return (left.getName() < left.getName());
}


int main()
{
    std::vector<Company> companies = populateCompaniesFromInput();

    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "id")
    {
        std::sort(companies.begin(), companies.end(), sortByID);
    }
    else
    {
        std::sort(companies.begin(), companies.end(), sortByName);
    }

    for (Company& company : companies) // Range base for loop 
    {
        std::cout << company.toString() << '\n';
    }

    return 0;
}
