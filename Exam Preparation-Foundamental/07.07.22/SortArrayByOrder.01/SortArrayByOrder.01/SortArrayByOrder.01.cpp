#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>


void print(const std::vector<char>& v)
{
    for (const char& ch : v)
    {
        std::cout << ch << ' ';
    }
    std::cout <<'\n';
}



int main()
{
    int size{ 0 };
    std::cin >> size;
    std::vector<char> vec;

    for (int i = 0; i < size; i++)
    {
        char n;
        std::cin >> n;
        vec.push_back(n);
    }

    std::vector<char> capitalLetter;
    std::vector<char> lowecaseLetter;
    std::vector<char> otherSimbols;
    std::vector<char> digits;

    for (size_t i = 0; i < vec.size(); i++)
    {
        if ( std::isdigit(vec[i]) )
        {
            digits.push_back(vec[i]);
        }
        else if (!std::isalpha(vec[i]) && !std::isdigit(vec[i]) )
        {
            otherSimbols.push_back(vec[i]);
        }
        else if ( ( 64 < vec[i] && vec[i] < 91) )
        {
            capitalLetter.push_back(vec[i]);
        }
        else if ( (96 < vec[i] && vec[i] < 123) )
        {
            lowecaseLetter.push_back(vec[i]);
        }
    }
    
    print(digits);
    print(lowecaseLetter);
    print(capitalLetter);
    print(otherSimbols);


    return 0;
}
