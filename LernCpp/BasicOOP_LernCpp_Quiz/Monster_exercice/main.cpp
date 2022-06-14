#include <iostream>
#include <cmath>

#include "monster.h"

// skeleton
int main()
{
	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

    return 0;
}
// skeleton 