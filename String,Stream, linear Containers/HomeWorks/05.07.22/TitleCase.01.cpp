#include <iostream>
#include <string>
#include <sstream>

bool checkForAnotherSumbols(const std::string& str)
{
    for (size_t i=0; i < str.size() ; i++)
    {
        if (! std::isalpha(str[i]) )
        {
            return true;
        }
    }
    return false;
}



int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::istringstream in(str);
    str.clear();

    std::string output;

    while (in>>str)
    {
        if ( std::isalpha(str[0]) )
        {
            if ( std::islower(str[0]) )
            {
                str[0] = str[0] - 32;
            }
        }
        if ( checkForAnotherSumbols(str) )
        {
            for (size_t i=0; i< str.size(); i++)
            {
                if (!std::isalpha(str[i]))
                {
                    if ( (i+1) < str.size())
                    {
                        str[i + 1] = str[i + 1] - 32;
                    }
                }
            }

        }
        output += str;
        output += ' ';
    }
    std::cout << output << '\n';

    return 0;
}
