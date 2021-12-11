#include <iostream>
#include <string>

#include "TryParse.h"

using namespace std;

int main()
{
    string firstParse;
    string secondParse;

    cin >> firstParse >> secondParse;

    checkParse(&firstParse,&secondParse); //nothing return, just do check on these two parses

    return 0;
}

