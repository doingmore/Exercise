#include <iostream>

#include "Car.h"

/*
BMW
535i f10
2012
*/


// Function that call Print of all Getters
void PrintInfo(const Car& objCar)
{
    std::cout << "Brand -> " << objCar.getBrand() << '\n';

    std::cout << "Model -> " << objCar.getModel() << '\n';

    std::cout << "Year -> " << objCar.getYear() << '\n';
}

int main()
{
    std::string sBrand;

    std::string sModel;

    int nYear;

    std::cin >> sBrand >> sModel >> nYear;

    const Car objCar(sBrand, sModel, nYear);

    PrintInfo(objCar);

    return 0;
}
