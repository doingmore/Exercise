#include <iostream>
#include <vector>
#include <map>

#include "Company.h"
#include "ProfitCalculator.h"

int main()
{
    std::vector<Company> list;
    std::map<int, int> iDTax;
    
    // for member                       
    std::string inputName;              //int p = 5; // int variable
    int iD{ 0 };                        //int* pPointer=&p ;// pointer to int
    int revenue{ 0 };                   //int*& pPointerRef = pPointer; // reference to pointer to int
    int costs{ 0 };
    // for member

    int taxPrecentage{ 0 };

    for (int i = 0; i < 10; i++)
    {
        std::cin >> inputName;
        if (inputName == "end")
        {
            inputName = "GO";
            break;
        }
        std::cin >> iD >> revenue >> costs;
        list.push_back(Company(inputName, iD, revenue, costs));
    }
    while (inputName != "end")
    {
        std::cin >> inputName;
        if (inputName == "end")
        {
            break;
        }
        std::cin>>taxPrecentage;
        iD = stoi(inputName); // to int because must put in map. After that in string, because must do check for end
        iDTax.insert(std::pair<int, int>(iD, taxPrecentage));
    }

    getProfitReport(list,iDTax);

        return 0;
}
