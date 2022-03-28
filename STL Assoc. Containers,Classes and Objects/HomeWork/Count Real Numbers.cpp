#include <iostream>
#include <sstream>
#include <map>

int main_1()
{
    double number{ 0 };
    std::stringstream stream;
    std::string input;
    std::getline(std::cin, input);

    std::map<double,int> regNumbers;

    stream << input;
    while (stream >> input)
    {
        number = std::stod(input);
        if ( regNumbers.count(number) )
        {
            regNumbers[number] += 1;
        }
        else
        {
        regNumbers.emplace(number, 1);
        }
    }
    std::map<double, int>::iterator it;
    for (it = regNumbers.begin(); it != regNumbers.end(); it++)
    {
        std::cout << it->first << " -> " << it->second << '\n';
    }

    return 0;
}
