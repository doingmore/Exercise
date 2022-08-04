
#include <iostream>
#include <string>

class Animal
{
public:
    std::string getName() const { return m_name; }
    virtual std::string speak() const = 0;
    virtual int getSpecificDataForType() const = 0;
    virtual int numberOfLegs() const // only virtual, not pure
    {
        return 0;
    }
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal() {}
    Animal(const std::string& name)
        : m_name{ name }
    {
    }
    /* not necessary
    Animal(const Animal& other)
    {
        this->m_name = other.m_name;
    }
    */
public:
    virtual ~Animal() //  absolutely need virtual
    {
        std::cout << "Animal destructor has been executed" << '\n';
    }
};

class Cat final : public Animal // I don't want more derived class from cat, no need virtual destructor ??? 
{
private:
    std::string m_rev; // all cat have same rev
    int m_legs; // all cat have 4 legs
    int m_mouse_murders;
public:
    Cat(const std::string& name,const int& murders)
        : Animal{ name }
        , m_rev{ "Meow" }
        , m_legs{4}
        , m_mouse_murders{ murders }
    {
    }

    Cat(const Cat& other)
    {
        this->m_name = other.m_name;
        this->m_rev = other.m_rev;
    }

    ~Cat()
    {
        std::cout << "Cat destructor has been executed" << '\n';
    }

    std::string speak() const { return m_rev; }
    int numberOfLegs() const override { return m_legs; }
    int getSpecificDataForType() const override { return m_mouse_murders; }
};

class Dog : public Animal
{
public:
    Dog(const std::string& name,const int& murders)
        : Animal{ name }
        , m_rev{ "Woof" }
        , m_legs{ 4 }
        , m_cat_murders{ murders }
    {
    }
    Dog(const Dog& other)
        : m_rev{"Woof" }
        , m_legs{4}
    {
        this->m_name = other.m_name;
        this->m_cat_murders = other.m_cat_murders;
    }
    ~Dog()
    {
        std::cout << "Dog destructor has been executed" << '\n';
    }
    std::string speak() const { return m_rev; }
    int numberOfLegs() const override { return m_legs; }
    int getSpecificDataForType() const override { return m_cat_murders; }
private:
    std::string m_rev;
    int m_legs; 
    int m_cat_murders;
};

void report(const Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak()
        <<" and have "<< animal.numberOfLegs()
        << " legs and don't like neighbor pet from other kind "
        << animal.getSpecificDataForType() << '\n';
}

int main()
{
    Cat cat{ "Fred" ,3};
    Dog dog{ "Garbo" , 90 };

    Dog copy{ dog };

    Animal* ptrA = new Cat{ "Tom",0 };

    delete ptrA;

    report(cat);
    report(dog);
    report(copy);

    return 0;
}