#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Company.h"

/*
acme 424242420
softuni_foundation 20140414
itjoro 878968302
end
id
*/

bool sortById(const Company& left, const Company& right)
{
    return (left.getId() < right.getId());
}

bool sortByName(const Company& left, const Company& right)
{
    return (left.getName() < right.getName());
}


int main()
{
    std::vector<Company> list;
    std::string input;
    while (std::getline(std::cin,input) && input != "end")
    {
        std::istringstream stream(input);
        std::string name;
        int id;
        stream >> name;
        stream >> id;
        list.emplace_back(Company{id,name});
    }

    std::string comand;
    std::cin >> comand;



    if (comand == "id")
    {
        std::sort(list.begin() , list.end() , sortById );
    }
    else if (comand == "name")
    {
        std::sort(list.begin(), list.end(), sortByName );
    }
    else
    {
        std::cout << "ERROR with comand" << '\n';
        throw _EXCEPTION_;
    }

    for (const Company& c : list)
    {
        std::cout << c.getName() << " " << c.getId() << '\n';
    }

    return 0;
}
