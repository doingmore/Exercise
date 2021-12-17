#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "MinBy.h"
#include "ClassCharacteristic.h"

using namespace std;

/*
hear the rime of the ancient mariner see his eyes as he stops one of
*/

int main()
{
    string inputString;
    getline(cin, inputString);
    stringstream stream(inputString);
    string answer;

    answer = checkWordCharacteristic(&stream);

    cout<< answer <<'\n'; //check words characteristic and create a member with three of characteristics

    return 0;
}
