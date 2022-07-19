#include <iostream>

#define sizeInBits 8

void translateNumber(int* bitsArray, int number)
{
    int i{ sizeInBits - 1 };      // last bit, writing right to left
    while (number > 0)
    {
        bitsArray[i] = number % 2;
        number /= 2;
        i--;
    }
}





int main()
{
    int firstNumber{10};
    int secondNumber{10};
    //std::cin >> firstNumber >> secondNumber;

    int bitsFirstNumber[sizeInBits]{};
    int bitsSecontNumber[sizeInBits]{};

    translateNumber(bitsFirstNumber , firstNumber);
    translateNumber(bitsSecontNumber, secondNumber);

    int sum[sizeInBits]{};


    
    for (int k = sizeInBits-1; k >= 0; k--)
    {
        if (bitsFirstNumber[k] )
        {

        }
        if (true)
        {

        }
        if (true)
        {

        }
        if (true)
        {

        }
    }







    // printing bits First Number
    for (int i = 0; i < sizeInBits; i++)
    {
        std::cout << bitsFirstNumber[i];
    }
    // printing bits Secont Number
    for (int i = 0; i < sizeInBits; i++)
    {
        std::cout << bitsFirstNumber[i];
    }
 




    return 0;
}
