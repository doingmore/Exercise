#include <iostream>
#include <string>

// Instruction
// Add a new class to the previous program (problem1) called GrannySmith that inherits from Apple.
// The following code in main should run :


class Fruit
{
private:
	std::string m_name;
	std::string m_color;
public:
	Fruit(const std::string& name, const std::string& color) : m_name{ name }, m_color{ color }
	{
	}

	std::string getName() { return m_name; }
	std::string getColor() { return m_color; }
};

class Apple : public Fruit
{
// The previous constructor we used for Apple had a fixed name ("apple").
// We need a new constructor for GrannySmith to use to set the name of the fruit
protected: // protected so only derived classes can access
	Apple(const std::string& name, const std::string& color)
		: Fruit{ name, color }
	{
	}
public:
	Apple(const std::string& color) : Fruit{ "Apple" , color }
	{
	}
};

class Banana : public Fruit
{
public:
	Banana() : Fruit{ "Banana","Yellow" }
	{}
};

class GrannySmith : public Apple // Granny Smith is a dessert apple of a bright green variety
{
private:
	std::string m_name;
public:
	GrannySmith() : Apple{ "Granny Smith" , "green" }
	{
	}
};


// from here
int main()
{
	Apple a{ "red" };
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
// to here is skeleton