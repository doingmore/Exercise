#include <iostream>
#include <vector>
using namespace std;

/*
Write a program that, given an integer number in the range [0, 9999], prints the name of that number in English.
Simplifications:
•	Use lowercase English letters only
•	Don’t place “and” (e.g. 957 is nine hundred fifty seven, NOT nine hundred and fifty seven)
•	Skip 0 digits, except for the number 0 (e.g. 0 -> zero; 101 -> one hundred one; 1001 -> one thousand one)
•	Don’t print dashes (e.g. print 75 as seventy five, NOT seventy-five)
*/

void Problem7()
{
    int number{ 0 };
    cin >> number;

    if (number == 0)
    {
        cout << "zero" << '\n';
    }

    if (number < 0 || number > 9999)
    {
        cout << "Error! Expected number between 0 and 9999." << '\n';
    }

    int d1, d2, d3, d4;
    d1 = number / 1000;
    d2 = (number % 1000) / 100;
    d3 = (number % 100) / 10;
    d4 = number % 10;

    if (d1)
    {
        switch (d1)
        {
        case 1: cout << "onethousants";
            break;
        case 2: cout << "twothousants";
            break;
        case 3: cout << "threethousants";
            break;
        case 4: cout << "fourthousants";
            break;
        case 5: cout << "fivethousants";
            break;
        case 6: cout << "sixthousants";
            break;
        case 7: cout << "seventhousants";
            break;
        case 8: cout << "eightthousants";
            break;
        case 9: cout << "ninethousants";
            break;
        }
    }
    if (d2)
    {
        switch (d2)
        {
        case 1: cout << "one hundred ";
            break;
        case 2: cout << "two hundred ";
            break;
        case 3: cout << "three hundred ";
            break;
        case 4: cout << "four hundred ";
            break;
        case 5: cout << "five hundred ";
            break;
        case 6: cout << "six hundred ";
            break;
        case 7: cout << "seven hundred ";
            break;
        case 8: cout << "eight hundred ";
            break;
        case 9: cout << "nine hundred ";
            break;
        }
    }
    if (d3)
    {
        switch (d3)
        {
        case 1: cout << "ten";
            break;
        case 2: cout << "twenty";
            break;
        case 3: cout << "thirty";
            break;
        case 4: cout << "fourty";
            break;
        case 5: cout << "fifty";
            break;
        case 6: cout << "sixty";
            break;
        case 7: cout << "seventy";
            break;
        case 8: cout << "eighty";
            break;
        case 9: cout << "ninety";
            break;
        }
    }
    if (d4)
    {
        switch (d4)
        {
        case 1: cout << " one";
            break;
        case 2: cout << " two";
            break;
        case 3: cout << " three";
            break;
        case 4: cout << " four";
            break;
        case 5: cout << " five";
            break;
        case 6: cout << " six";
            break;
        case 7: cout << " seven";
            break;
        case 8: cout << " eight";
            break;
        case 9: cout << " nine";
            break;
        }
    }
}