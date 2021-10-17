#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/*
Write a program which reads a sequence of non - negative integer numbers
(in the decimal numeral system), separated by spaces, and finds the maximum number.
The numbers in the input may have “noise” – symbols before, after, or between
the digits of the number, which are not decimal digits(you need to ignore these 
when reading the numbers).All symbols in the input will be either letters, digits,
punctuation, or signs from the standard ASCII table(no control symbols like newlines or tabs, delete, etc.)
1.][.3 5--aA3:)5 2asd=@14
*/

int main()
{
    string input;
    getline(cin, input);
    stringstream noise;
    noise << input <<'\n';
    string fragment;
    string strDigit;
    string output;

    int digit{ 0 };
    int saveMaxDigit{ 0 };


    while (noise)
    {
        noise >> fragment;
        for (char character:fragment)
        {
            if (isdigit(character))
            {
                output = output + character;
                strDigit = strDigit + character;
            }
        }
        if (fragment!="")    // This chek is because in last iteration fragment is equal on "". This make a error in function stoi. 
        {
        digit = stoi(strDigit);
        }
        if (digit>saveMaxDigit)
        {
            saveMaxDigit=digit;
        }
        strDigit.clear();
        fragment.clear();
        output = output + " "; 
    }
    
    cout << "The numbers are: " << output << " of which," << saveMaxDigit << " is the max." << '\n';
  
    return 0;
}
