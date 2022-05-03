#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include "Company.h"


Company* get_min_id(std::vector<Company*>& list)
{
    int max{ INT_MAX };
    Company* answer = NULL;
    for (Company* o : list)
    {
        if (o != NULL)
        {
            if (o->getId() < max)
            {
                answer = o;
                max = o->getId();
            }
        }
    }
    for (size_t i = 0; i < list.size(); i++) // max_id for that iteration bound to NULL
    {
        if (list[i] == answer)
        {
            list[i] = NULL;
            break;
        }
    }
    return answer;
}

Company* get_min_name(std::vector<Company*>& list)
{
    std::string max{ "~~~~~" };
    Company* answer = NULL;
    for (Company* o : list)
    {
        if (o != NULL)
        {
            if (o->getName() < max)
            {
                answer = o;
                max = o->getName();
            }
        }
    }
    for (size_t i = 0; i < list.size(); i++) // max_id for that iteration bound to NULL
    {
        if (list[i] == answer)
        {
            list[i] = NULL;
            break;
        }
    }
    return answer;
}

void sort_By_Id(std::vector<Company*>& list)
{
    std::vector<Company*> sorted_vector;
    Company* min_id = NULL;
    for (size_t i = 0; i < list.size(); i++)
    {
        min_id = get_min_id(list);
        sorted_vector.push_back(min_id);
    }
    list = sorted_vector;
}

void sort_By_Name(std::vector<Company*>& list)
{
    std::vector<Company*> sorted_vector;
    Company* alpAlphabetical_min = NULL;
    for (size_t i = 0; i < list.size(); i++)
    {
        alpAlphabetical_min = get_min_name(list);
        sorted_vector.push_back(alpAlphabetical_min);
    }
    list = sorted_vector;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // this line added by Svetozar, check for memory leak, exercise
    std::vector<Company*> list;
    std::string inputSTR;
    std::string name;
    int id;
    std::getline(std::cin, inputSTR);
    while (inputSTR != "end")
    {
        std::istringstream input(inputSTR);
        input >> name >> id;
        Company* ptr = new Company{ id,name };
        list.push_back(ptr);
        std::getline(std::cin, inputSTR);
    }

    std::string sortedBy;
    std::getline(std::cin, sortedBy);

    if (sortedBy == "id")
    {
        sort_By_Id(list);
    }
    else if (sortedBy == "name")
    {
        sort_By_Name(list);
    }
    else
    {
        throw _EXCEPTION_;
    }

    for (auto ptr : list)
    {
        std::cout << ptr->toString() << '\n';
        delete ptr;
    }

    return 0;
}
