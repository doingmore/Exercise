#ifndef MONSTER_H
#define MONSTER_H

#define begin_zero 0
#define max_hit_points 100

#include <iostream>
#include <cassert>
#include <chrono>
#include <random>
#include <vector>

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        src,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster
    };
private:
    Type m_type;
    std::string m_name;
    std::string m_roar;
    int m_number_of_hit_points;
protected:
    std::string getTypeString(const  Type& type) const;
public:
    Monster(Type type, const std::string& name, const std::string& roar, const int& hit_points);

    void print() const;

};

class MonsterGenerator
{
protected:
    static int getRandomNumber(const int& down_limit , const int& up_limit);
public:
    static Monster generateMonster();
};



#endif // !MONSTER_H
