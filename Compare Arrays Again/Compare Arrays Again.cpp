#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
Write a program that reads two integer arrays from the console and compares them element by element.
For better code reusability, you could do the comparison in a function, which returns true if they
are equal and false if not. Each array will be defined by a single line on the console, containing 
the numbers in the array, separated by spaces.
Print equal if the arrays match, and not equal if the arrays don’t match.
*/

int compireIndex(int IFFA, int IFSA,bool localFlag) //IFFA ==> index from first array IFSA ==> index from second array
{
    if (IFFA != IFSA)
    {
        localFlag = false;
    }
    return localFlag;
}

int main()
{
    string firstArray;
    string secondArray;
    getline(cin,firstArray);
    getline(cin, secondArray);
    
    int indexFFA{ 0 };
    int indexFSA{ 0 };
    bool flag=true;

    for (unsigned int i = 0; i < firstArray.size(); i++)
    {
        if (firstArray[i] > 47 && firstArray[i] < 58)
        { 
        indexFFA = firstArray[i]-48;
        indexFSA = secondArray[i]-48;
        flag=compireIndex(indexFFA, indexFSA, flag);
        }

        if (flag!=true)
        {
         break;
        }
    }

    if (flag)
    {
        cout << "Arrays are equal" << '\n';
    }
    else
    {
        cout << "Arrays not equal" << '\n';
    }
        return 0;
}
