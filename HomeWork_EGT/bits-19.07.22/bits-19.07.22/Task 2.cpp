#include <iostream>

#define sizeInBits 8


int main()
{
    int n;
    std::cin >> n;

    int bitNumber[sizeInBits]{};

    int i{ sizeInBits - 1 };      // last bit, writing right to left
    while (n > 0)
    {
        bitNumber[i] = n % 2;
        n /= 2;

        i--;
    }

    // printing bits array
    for (int i = 0; i < sizeInBits; i++)
    {
        std::cout << bitNumber[i];
    }



    return 0;
}
