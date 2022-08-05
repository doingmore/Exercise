#include <iostream>
#include <string>


#include "Animal.h"


int main()
{
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };
    Pinscher tenProcent_Doberman{ "Skub" , true };

    report(cat);
    report(dog);
    report(tenProcent_Doberman);

    return 0;
}
