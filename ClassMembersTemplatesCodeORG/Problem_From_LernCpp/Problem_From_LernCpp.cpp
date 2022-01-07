#include <iostream>

#include "Fraction.h"

fraction operator*(const fraction& f1, const fraction& f2)
{
    return ((f1.getNumerator()*f2.getNumerator()),(f1.getDenumerator()*f2.getDenumerator()));
}

fraction operator*(const fraction& f1, int value)
{
    return((f1.getNumerator() * value), f1.getDenumerator());
}

fraction operator*(int value, const fraction& f2)
{
    return((f2.getDenumerator()), (f2.getNumerator() * value));
}

int main()
{
    fraction f1{ 1, 4 };
    f1.print();

    fraction f2{ 1, 2 };
    f2.print();

    fraction f3{ f1 * f2 };
    f3.print();

    fraction f4{ f1 * 2 };
    f4.print();

    fraction f5{ 2 * f2 };
    f5.print();

    fraction f6{fraction{1, 2} *fraction{2, 3} *fraction{3, 4} };
    f6.print();

    return 0;
}