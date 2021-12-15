#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>


#include "Company.h"

using namespace std;

/*
acme 424242420
softuni_foundation 20140414
itjoro 878968302
end
id
*/

vector<Company> populateCompaniesFromInput()
{
    vector<Company> companies;
    string input = " begin ";
    string companyID{ 0 };
    string companyName;
    int id{ 0 };

    while (input != "end")
    {
        getline(cin, input);
        if (input =="end")
        {
            return companies;
            break;
        }
        istringstream istr(input);
        istr >> companyName >> companyID;
        id = stoi(companyID);
        companies.push_back(Company(id,companyName));
    }
    return companies;
}


bool sortByID(Company &left,Company &right)
{
    return (left.getID() < right.getID());
}

bool sortByName(Company &left, Company &right)
{
    return (left.getName() < left.getName());
}


int main()
{
    vector<Company> companies = populateCompaniesFromInput();

    string choice;
    getline(cin, choice);

    if (choice == "id")
    {
        std::sort(companies.begin(), companies.end(), sortByID);
    }
    else
    {
        std::sort(companies.begin(), companies.end(), sortByName);
    }

    for (Company &company : companies)
    {
        cout << company.toString() << '\n';
    }

    return 0;
}