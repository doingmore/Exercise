#include <iostream>
#include <cassert>
#include <chrono>
#include <random>
#include <vector>


#include "monster.h"


std::string Monster::getTypeString(const  Type& type) const
{
    assert(type >= begin_zero && type < Monster::Type::max_monster);
    std::string answer;
    if (type == 0)
    {
        answer = "dragon";
    }
    else if (type == 1)
    {
        answer = "goblin";
    }
    else if (type == 2)
    {
        answer = "ogre";
    }
    else if (type == 3)
    {
        answer = "src";
    }
    else if (type == 4)
    {
        answer = "skeleton";
    }
    else if (type == 5)
    {
        answer = "troll";
    }
    else if (type == 6)
    {
        answer = "vampire";
    }
    else if (type == 7)
    {
        answer = "zombie";
    }
    else
    {
        answer = "max type";
    }
    return answer;
}

Monster::Monster(Type type, const std::string& name, const std::string& roar, const int& hit_points) :
    m_type{ type },
    m_name{ name },
    m_roar{ roar },
    m_number_of_hit_points{ hit_points }
{}

void Monster::print() const
{
    std::cout << this->m_name << " the " << getTypeString(this->m_type) <<
        " has " << this->m_number_of_hit_points << " hit points and says " << this->m_roar << '\n';
}


//=================================================>> MonsterGenerator <<=========================================================

int MonsterGenerator::getRandomNumber(const int& down_limit , const int& up_limit)
{
    // Seed our Mersenne Twister using the
    std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
    // Create a reusable random number generator that generates uniform numbers between 0 and 3
    std::uniform_int_distribution<> die6{ down_limit, up_limit }; // for C++14, use std::uniform_int_distribution<> die6{ 0, 10 };
    int number{ static_cast<int>(die6(mt)) };
    return number;
}

Monster MonsterGenerator::generateMonster()
{
    static std::vector<std::string> list_names = { "Brand","Skoby","Guinder","Nick","Kitter","Kolep","Lorx","Badboy","NONAME","OZARK" };
    static std::vector<std::string> list_roars{ "*ROAR*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*" };
    //Making list_names and list_roars static causes
    //them to be initialized only once. 
    //Otherwise, they would get reinitialized every time generateMonster() was called.
    int random_number_for_type{ getRandomNumber(begin_zero , Monster::Type::max_monster - 1) };

    auto type = static_cast<Monster::Type>(random_number_for_type);

    // local copy
    Monster answer{
        type ,
        list_names[getRandomNumber(begin_zero , list_names.size() - 1)],
        list_roars[getRandomNumber(begin_zero , list_roars.size() - 1)],
        getRandomNumber(begin_zero , max_hit_points)
    };

    return answer;
}
