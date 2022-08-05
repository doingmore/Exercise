#ifndef ANIMAL_H
#define ANIMAL_H

// It is possible to make the assignment operator virtual. However, unlike the destructor case where virtualization
// is always a good idea, virtualizing the assignment operator 
// really opens up a bag full of worms and gets into some advanced topics

class Animal
{
public:
    std::string getName() const { return m_name; }
    virtual std::string speak() const = 0;
    virtual int getSpecificDataForType() const = 0;
    virtual int numberOfLegs() const = 0;
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    // Animal() {}
    Animal(const std::string& name)
        : m_name{ name }
    {
    }
    
public:
    virtual ~Animal() //  absolutely need virtual
    {
        std::cout << "Animal destructor has been executed" << '\n';
    }
};

class Cat final : public Animal // I don't want more derived class from cat, no need virtual destructor ??? 
{
public:
    Cat(const std::string& name)
        : Animal{ name }
        , m_rev{ "Meow" }
        , m_legs{ 4 }
        , m_mouse_murders{ 0 }
    {
    }

    Cat(const Cat& other)
        : Animal{ other.getName() }
    {
        this->m_rev = other.m_rev;
        this->m_legs = other.m_legs; // or just m_legs = 4 
        this->m_mouse_murders = other.m_mouse_murders;
    }
    Cat& operator= (const Cat& other)
    {
        if (this == &other)
        {
            return *this;
        }
        // in this case no need other action 
        this->m_rev = other.m_rev;
        this->m_legs = other.m_legs; // or just m_legs = 4 
        this->m_mouse_murders = other.m_mouse_murders;

        return *this;
    }
    ~Cat() // no need virtual ????
    { // first this destructor 
        std::cout << "Cat destructor has been executed" << '\n';
    }

    std::string speak() const override { return m_rev; }
    int numberOfLegs() const override { return m_legs; }
    int getSpecificDataForType() const override { return m_mouse_murders; }
private:
    std::string m_rev; // all cat have same rev
    int m_legs; // all cat have 4 legs
    int m_mouse_murders;
};

class Dog : public Animal
{
public:
    Dog(const std::string& name)
        : Animal{ name }
        , m_rev{ "Woof" }
        , m_legs{ 4 }
        , m_cat_murders{ 0 }
    {
    }
    Dog(const Dog& other)
        : Animal{ other.getName() }
        , m_rev{ "Woof" }
        , m_legs{ 4 }
    {
        this->m_cat_murders = other.m_cat_murders;
    }

    Dog& operator= (const Dog& other)
    {
        if (this == &other)
        {
            return *this;
        }
        // in this case no need other action 
        this->m_rev = other.m_rev;
        this->m_legs = other.m_legs; // or just m_legs = 4 
        this->m_cat_murders = other.m_cat_murders;


        // m_name member ??????



        return *this;
    }

    virtual ~Dog()
    {
        std::cout << "Dog destructor has been executed" << '\n';
    }
    std::string speak() const override { return m_rev; }
    int numberOfLegs() const override { return m_legs; }
    int getSpecificDataForType() const override { return m_cat_murders; }
private:
    std::string m_rev;
    int m_legs;
    int m_cat_murders;
};



class Pinscher : public Dog 
{
public:
    Pinscher(const std::string& name, const bool& house  )
        : Dog{ name }
        , m_livingAtHouse{ true }
    {
    }
    Pinscher(const Pinscher& other)
        : Dog{ other.getName() }
    {
        this->m_livingAtHouse = other.m_livingAtHouse;
    }

    Pinscher& operator= (const Pinscher& other)
    {
        if (this == &other)
        {
            return *this;
        }
        
        this->m_livingAtHouse = other.m_livingAtHouse;

        return *this;
    }

    virtual ~Pinscher()
    {
        std::cout << "Pinscher destructor has been executed" << '\n';
    }
    bool getLivingPlace() const { return m_livingAtHouse; }

    // no need obligatory implement pure virtual function from base class 
    // ????

private:
    bool m_livingAtHouse;
};



void report(Animal& animal) // no constant ref because of dynamic_cast.
{
    std::cout << animal.getName() << " says " << animal.speak()
        << " and have " << animal.numberOfLegs()
        << " legs and don't like neighbor pet from other kind "
        << animal.getSpecificDataForType() << '\n';

    { // this action is specific for Pinscher
        Animal* ptrA = &animal;
        Pinscher*  ptrP = dynamic_cast<Pinscher*>(ptrA); // return NULL if cast not successful
        if (ptrP)
        {
            if (ptrP->getLivingPlace())
            {
                std::cout << "Living at house" << '\n';
            }
        }
    }
}



#endif // !ANIMAL_H
