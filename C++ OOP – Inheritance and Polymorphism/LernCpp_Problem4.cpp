#include <iostream>
#include <string>

/*
b) Now we’re going to create the Player class. The Player class inherits from Creature.
Player has one additional member, the player’s level, which starts at 1.
The player has a custom name (entered by the user), uses symbol ‘@’, has 10 health, does 1 damage to start,
and has no gold. Write a function called levelUp() that increases the player’s level and damage by 1.
Also write a getter for the level member. Finally, write a function called hasWon() that returns true if the player has reached level 20.

Write a new main() function that asks the user for their name and produces the output as follows:
Enter your name: Alex
Welcome, Alex.
You have 10 health and are carrying 0 gold.
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

class Monster : public Creature
{
public:
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

int main()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Welcome, " << name << "\n";

	Player player{ name };

	std::cout << "You have " << player.getHealth() << " health and are carring " << player.getGold() << " gold\n";

	return 0;
}
