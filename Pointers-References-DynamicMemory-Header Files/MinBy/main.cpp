#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "MinBy.h"
#include "ClassCharacteristic.h"

/* input
hear the rime of the ancient mariner see his eyes as he stops one of
*/

int main()
{
    std::string inputString;
    int choice{ 0 };
    std::getline(std::cin, inputString);
    std::cin >> choice;
    std::stringstream stream(inputString);
    std::string answer;

    switch (choice)
    {
    case 1: // finds the string that is earliest lexicographically
        answer = checkForFirstCriteria(stream);
        break;
    case 2: // finds the shortest string
        answer = checkForSecondCriteria(stream);
        break;
    case 3: // finds the longest string
        answer = checkForThirdCriteria(stream);
        break;
    default:
        std::cout << "Tour choice is incorrect" << '\n';
        break;
    }

    std::cout<< answer <<'\n'; //check words characteristic and create a member with three of characteristics

    return 0;
}
