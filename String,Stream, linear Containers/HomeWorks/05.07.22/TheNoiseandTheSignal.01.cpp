#include <iostream>
#include <string>
#include <sstream>


bool checkForNoise(const std::string& input)
{
    //  letters 
    //  digits
    //  punctuation  ,  signs from of the standard ASCII table 
    std::istringstream in(input);
    std::string s;
    int letters{0};
    int digits{0};
    int other{0};
    while (in >> s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] > 64 && s[i] < 91 ) // capitalletters
            {
                letters = 1;
            }
            else if (s[i] > 96 && s[i] < 123) // lowercase
            {
                letters = 1;
            }
            else if (s[i] > 47 && s[i] < 58) // digits
            {
                digits = 1;
            }
            else
            {
                other = 1;
            }
        }

        if ( (letters + digits + other) > 1 && (letters + digits + other) < 4)
        {
            return true;
        }
        else if ((letters + digits + other) < 0 || (letters + digits + other) > 4)
        {
            std::cout << "ERROR with check for noises, detected anther symbols" << '\n';
            throw _EXCEPTION_;
        }
    }
    return false;
}


std::string removeDigits(const std::string& str)
{
    std::string answer;
    for (size_t i = 0; i < str.size(); i++)
    {
        if ( !std::isdigit(str[i]) )
        {
            answer += str[i];
        }
    }
    return answer;
}


std::string getEarlier(const std::string& str)
{
    std::string answer;
    std::istringstream in(str);
    std::string comparer;
    in >> answer;
    while (in>>comparer)
    {
        if (comparer < answer)
        {
            answer = comparer;
        }
    }

    return answer;
}



int main()
{
    std::string input;
    std::getline(std::cin, input);

    if ( checkForNoise(input) )
    {
         std::string output{ removeDigits(input)};
         output = getEarlier(output);
         std::cout << output << '\n';
    }
    else
    {
        std::cout << "No noise" << '\n';
    }

    return 0;
}
