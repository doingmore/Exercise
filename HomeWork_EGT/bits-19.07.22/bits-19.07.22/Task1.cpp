#include <iostream>
#include <string>

#define bitsSize 16

void translateNumber(int* bits, int number)
{
    int it{ bitsSize - 1 };
    while (number > 0)
    {
        bits[it] = number % 2;
        it--;
        number /= 2;
    }
}

bool checkForPowerOfTwo(int* number, int* previousNumber)
{
    bool flag{ true };
    for (int i = bitsSize-1 ; i >= 0; i--)
    {
        if ( number[i] & previousNumber[i] )
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void printBinaryNumber(int* bits)
{
    for (int i = 0; i < bitsSize; i++)
    {
        std::cout << bits[i];
    }
}

int main()
{
    for (int i = 1; i < 50000; i++)
    {
        int n{ i }; // The number we are checking
        int nMinusOne{ n - 1 };

        int nNumber[bitsSize]{};            // binary
        int previousNumber[bitsSize]{};     // binary

        translateNumber(nNumber, n);
        translateNumber(previousNumber, nMinusOne);

        if (checkForPowerOfTwo(nNumber , previousNumber) ) 
        {
            std::cout << "binary: ";
            printBinaryNumber(nNumber);
            std::cout <<" -> "<< i << " -> is power of two " << '\n';
        }
    }

    return 0;
}
