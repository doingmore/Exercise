#include <iostream>
#include "Car.h"

int main()
{
    car favoriteCar("BMW", "535i F10", 2012);

    std::cout << favoriteCar.getBrand() << " " <<
        favoriteCar.getModel() << " " <<
        favoriteCar.getYear() << '\n';

    return 0;
}