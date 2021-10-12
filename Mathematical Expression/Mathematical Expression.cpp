#include <iostream>
#include <string>

using namespace std;

/*
Write a program that reads a line from the console containing a mathematical expression. 
Write a bool function that checks whether the brackets in the expression () are placed 
correctly (assume everything else is correct, i.e. you don’t need to check for correct
signs, correct variables/numbers, etc.) and returns true if they are correct and false 
if they are not correct. Print correct or incorrect accordingly on the console
*/

bool expresionCheck(string localexprecion)
{
    int countOpenBrackets{ 0 };
    int countCloseBrackets{ 0 };
    for (unsigned int i = 0; i < localexprecion.size() ; i++)
    {
        if (localexprecion[i] == '(') // ASCII The char '(' is equal integer value 40 
        {
            countOpenBrackets++;
        }
        if (localexprecion[i] == ')')
        {
            countCloseBrackets++;
        }
    }
    if (countOpenBrackets==countCloseBrackets)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string exprecion;
    getline(cin, exprecion);

    bool flag;
    flag = expresionCheck(exprecion);

    if (flag)
    {
        cout << "The expresion is with correct brackets syntax";
    }
    else
    {
        cout << "Not correct brackets syntax";
    }
    return 0;
}