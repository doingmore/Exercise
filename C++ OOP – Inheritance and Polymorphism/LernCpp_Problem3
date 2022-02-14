#include <iostream>
#include <string>


/*
Challenge time! The following quiz question is more difficult and lengthy. We’re going to write a simple game where you fight monsters. The goal of
the game is to collect as much gold as you can before you die or get to level 20.

Our program is going to consist of 3 classes: A Creature class, a Player class, and a Monster class. Player and Monster both inherit from Creature.

a) First create the Creature class. Creatures have 5 attributes: A name (std::string), a symbol (a char), an amount of health (int), the amount of damage
they do per attack (int), and the amount of gold they are carrying (int). Implement these as class members. Write a full set of getters
(a get function for each member). Add three other functions: void reduceHealth(int) reduces the Creature’s health by an integer amount.
bool isDead() returns true when the Creature’s health is 0 or less. void addGold(int) adds gold to the Creature.
*/


class Creature
{
public:
	std::string m_name;
	char m_symbol;
	int m_amountOfHealth;
	int m_amountOfDamage;
	int m_amountOfGold;

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

class Monsters : public Creature
{
public:
};

class Players : public Creature
{
public:

};

// skeleton from here
int main()
{
	Creature o{ "orc", 'o', 4, 2, 10 };
	o.addGold(5);
	o.reduceHealth(1);
	std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

	return 0;
}
// to here
