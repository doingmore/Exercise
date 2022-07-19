#include <iostream>

#define bitsSize 8

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

bool checkForPowerOfTwo(int* bits)
{
    int a{ 0 };
    for (int i = 0; i < bitsSize; i++)
    {
        a += bits[i];
    }
    return a == 1;
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
    int n{ 0 };
    std::cin >> n;

    int bitsNumber[bitsSize]{};

    translateNumber(bitsNumber, n);

    if (checkForPowerOfTwo(bitsNumber))
    {
        printBinaryNumber(bitsNumber);
        std::cout << " -> is power of two " << '\n';
    }


    return 0;
}
