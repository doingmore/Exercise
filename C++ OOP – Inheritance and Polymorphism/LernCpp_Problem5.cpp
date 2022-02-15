#include <iostream>
#include <string>
#include <array> // for getDefaultCreature

/*
c) Next up is the Monster class. Monster also inherits from Creature. Monsters have no non-inherited member variables.

First, write an empty Monster class inheriting from Creature, and then add an enum inside the Monster class named Type
that contains enumerators for the 3 monsters that we’ll have in this game: DRAGON, ORC, and SLIME 
(you’ll also want a max_types enumerator, as that will come in handy in a bit).

d) Each Monster type will have a different name, symbol, starting health, gold, and damage. Here is a table of stats for each monster Type:

Type	Name	Symbol	Health	Damage	Gold
dragon	dragon	D	20	4	100
orc	orc	o	4	2	25
slime	slime	s	1	1	10

Next step is to write a Monster constructor, so we can create monsters. The Monster constructor should take a Type enum as a parameter, 
and then create a Monster with the appropriate stats for that kind of monster. There are a number of different ways to implement this
(some better, some worse). However in this case, because all of our monster attributes are predefined (not random), we’ll use a lookup table. 
A lookup table is an array that holds all of the predefined attributes. We can use the lookup table to look up the attributes for a given monster as needed.
So how do we implement this lookup table? It’s not hard. We just need an array that contains an element for each monster Type. Each array element 
will contain a Creature that contains all of the predefined attribute values for that Type of Monster. We place this array inside of a static member 
function of Monster so that we can get a default Creature for a given Monster::Type. Now we can call this function to lookup any values we need!
For example, to get a Dragon’s gold, we can call getDefaultCreature(Type::dragon).getGold().
*/

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_amountOfHealth;
	int m_amountOfDamage;
	int m_amountOfGold;
public:

	Creature(const std::string& name, const char& symbol, int helth, int damage, int gold) :
		m_name(name), m_symbol(symbol), m_amountOfHealth(helth), m_amountOfDamage(damage), m_amountOfGold(gold)
	{

	}

	std::string getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_amountOfHealth; }
	int getDamage() const { return m_amountOfDamage; }
	int getGold() const { return m_amountOfGold; }


	void reduceHealth(const int& health)
	{
		m_amountOfHealth -= health;
	}

	bool isDead()
	{
		if (m_amountOfHealth > 0) // if a creature is live
		{
			return false;
		}
		return true; // when the creature is dead
	}

	void addGold(const int& gold)
	{
		m_amountOfGold += gold;
	}

};

class Monster : public Creature
{
public:
	enum class Type
	{
	dragon,
	orc,
	slime,
	max_types
	};
private:
	// As a private member of Monster
	static const Creature& getDefaultCreature(Type type)
	{
		static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
		  { { "dragon", 'D', 20, 4, 100 },
			{ "orc", 'o', 4, 2, 25 },
			{ "slime", 's', 1, 1, 10 } }
		};

		return monsterData.at(static_cast<std::size_t>(type));
	}
public:
	Monster(Type type) : Creature{ getDefaultCreature(type) }
	{

	}
};

class Player : public Creature
{
protected:
	int m_playerLevel;
public:
	Player(std::string name) : m_playerLevel(1), Creature{ name, '@' , 10 , 1 , 0 }
	{
	}

	void levelUp()
	{
		m_playerLevel += 1;
		m_amountOfDamage += 1;
	}

	int getLevel() const { return m_playerLevel; }

	bool hasWon()
	{
		if (m_playerLevel > 20) // return true if a player has reached 20 lvl
		{
			return true;
		}
		return false;
	}
};

// skeleton from here
int main()
{
	Monster m{ Monster::Type::orc };
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	return 0;
}
// to here
