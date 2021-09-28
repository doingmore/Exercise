#include <iostream>
using namespace std;

/*
Write a program that reads two integer numbers from the console, 
then reads one of the following four instructions (as a single symbol): +, -, *,/)
and performs the respective operation on the two numbers, with the first number
as a left operand and the second number as a right operand.
If the user enters a symbol different than one of the four operations, the program
should print try again and allow the user to enter the operation again.
*/

int getValueFromUser()
{
    char localSymbol;
    cin >> localSymbol;
    return localSymbol;
}

int main()
{
    int firstNumber{0};
    int secondNumber{0};
    cin >> firstNumber >> secondNumber;
    int action{ getValueFromUser() };

    for (int i = 0; i < 1;)
    {
        if (action == 43) // "+"
        {
            cout << (firstNumber + secondNumber) << '\n';
            break;
        }
        else if (action == 45) // "-"
        {
            cout << (firstNumber - secondNumber) << '\n';
            break;
        }
        else if (action == 42) // "*"
        {
            cout << (firstNumber * secondNumber) << '\n';
            break;
        }
        else if (action == 47) // "/"
        {
            cout << (firstNumber / secondNumber) << '\n';
            break;
        }
        cout << "Try again" << "\n";
        action= getValueFromUser();
    }
    return 0;
}