#include <iostream>

bool checkForPowerOfTwo(const int& number)
{
    double a = (double)number;   // is it good choice C cast in production  ?? static_cast<>() ?? 

    while (true)
    {
        if (a == 2)
        {
            return true;
        }
        else if (a < 2)
        {
            break;
        }
        a /= 2;
    }
    return false;
}


int main()
{
    // All numbers numbers until 50 000; 
    for (int i = 0; i < 50000; i++)
    {
        if (checkForPowerOfTwo(i))
        {
            std::cout << i << " -> is power of two " << '\n';
        }
    }
    return 0;
}
