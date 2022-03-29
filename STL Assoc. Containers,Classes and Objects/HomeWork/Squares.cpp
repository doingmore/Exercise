#include <iostream>
#include <sstream>
#include <string>
#include <set>


int main_6()
{
    std::string input;
    std::getline(std::cin, input);
    std::stringstream stream(input);
    std::set<int> listNumbers;
    int digit{ 0 };
    int number{ 0 };

    while (stream >> digit)
    {
        number = sqrt(digit);
        if (number * number == digit)
        {
            listNumbers.insert(digit);
        }
    }

    std::set<int>::iterator it = listNumbers.end();
    it--;

    for (unsigned int i = 0; i < listNumbers.size(); i++)
    {
        std::cout << *it << " ";
        it--;
    }

    return 0;
}