#include <iostream>
#include <set>
#include <sstream>
#include <string>


int main_5()
{
    std::string input;
    std::getline(std::cin, input);
    std::stringstream stream(input);
    std::set<int> listNumbers;
    int number{ 0 };

    while (stream >> number)
    {
        listNumbers.insert(number);
    }

    auto stop = listNumbers.end();
    stop--;

    std::set<int>::iterator it;
    for (auto it = listNumbers.begin(); it != listNumbers.end(); it++)
    {
        if (it == stop)
        {
            std::cout << *it;
            break;
        }
        std::cout << *it << " < ";
    }
    return 0;
}