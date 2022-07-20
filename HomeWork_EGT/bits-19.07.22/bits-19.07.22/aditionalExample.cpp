#include <iostream>

#define bitsSize 8

void printInBinary(int number)
{
    for (int i = bitsSize-1; i >= 0; i--)
    {
        int x{ number & (1 << i) };
        if (x == 0)
        {
            std::cout<<"0";
        }
        else
        {
            std::cout << "1";
        }
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
