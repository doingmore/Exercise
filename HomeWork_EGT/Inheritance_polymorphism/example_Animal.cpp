#include <iostream>
#include <string>


#include "Animal.h"


int main()
{
    Cat cat{ "Fred" };
    Dog dog{ "Garbo" };
    Pinscher tenProcent_Doberman{ "Skil" , true };

    Animal* ptrC = new Cat{ cat };

    delete ptrC;

    tenProcent_Doberman.somethingNormalFunc();


    report(cat);
    report(dog);
    report(tenProcent_Doberman);

    return 0;
}
