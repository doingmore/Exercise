#include <iostream>
#include <string>

#include "string_custom.h"

void report(const std::string& s)
{
    std::cout << " Size: " << s.size() << " Capacity: " << s.capacity() << '\n';
}

void report(const string& s)
{
    std::cout << " Size: " << s.size() << " Capacity: " << s.capacity() << '\n';
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);

    std::string str{"asdfghjkl;'zxcv"};
    std::string::iterator Sit{ str.begin() };
    std::cout << *Sit << '\n';

    string cSTR{ "qwertyuiop[]asd" };
    string::iterator it{ cSTR.begin() };
    std::cout << *it << '\n';
    it++;
    std::cout << *it << '\n';
    ++it;
    std::cout << *it << '\n';
    return 0;
}