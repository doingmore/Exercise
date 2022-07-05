#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input);

    char open = '(';
    char close = ')';
    int num_opened{ 0 };
    int num_closed{ 0 };

    for (size_t i = 0; i < input.size(); i++)
    {
        if ( input[i] == open )
        {
            num_opened++;
        }
        else if ( input[i] == close )
        {
            num_closed++;
        }
    }

    if (num_opened == num_closed)
    {
        std::cout << "correct" << '\n';
    }
    else
    {
        std::cout << "incorrect" << '\n';
    }


    return 0;
}