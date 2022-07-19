#include <iostream>

#define bitsSize 8

void printBinaryNumber(int number)
{
    int bitsNumber[bitsSize]{};

    int it{ bitsSize - 1 };
    while (number > 0)
    {
        bitsNumber[it] = number % 2;
        it--;
        number /= 2;
    }

    for (int i = 0; i < bitsSize; i++)
    {
        std::cout << bitsNumber[i];
    }
}

int main()
{
    int a = 5, b = 9;

    std::cout << "a = " << a << " / ";
    printBinaryNumber(a);
    std::cout << '\n';
    std::cout << "b = " << b << " / ";
    printBinaryNumber(b);
    std::cout << '\n';


    std::cout << "a & b = ";
    printBinaryNumber(a & b);
    std::cout << '\n';

    std::cout << "a | b = ";
    printBinaryNumber(a | b);
    std::cout << '\n';

    std::cout << "a ^ b = ";
    printBinaryNumber(a ^ b);
    std::cout << '\n';

    std::cout << "~a = " << (~a) << '\n';   // print ?

    std::cout << "b << 1" << " = ";
    printBinaryNumber(int{ b << 1 });
    std::cout << '\n';


    std::cout << "b >> 1 " << "= ";
    printBinaryNumber(int{ b >> 1 });
    std::cout << '\n';

    return 0;
}
