#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


static int numberStudent{ 0 };
static int numberProfessors{ 0 };
class Person
{
protected:
    std::string m_name;
    int m_age;
public:
    Person() {}
    ~Person()
    {
        std::cout << "Hello i'm Person destructor" << "\n";
        delete this;
    }
    virtual void getdata() {}
    virtual void putdata() const {}
};
class Professor : public Person
{
protected:
    int m_publications;
    int m_cur_id;
public:
    Professor() {}
    ~Professor()
    {
        std::cout << "Hello i'm a Professor destructor" << "\n";
        delete this;
    }
    virtual void getdata()
    {
        numberProfessors++;
        this->m_cur_id = numberProfessors;
        std::cin >> this->m_name;
        std::cin >> this->m_age;
        std::cin >> this->m_publications;
    }
    virtual void putdata() const
    {
        std::cout << this->m_name << " " << this->m_age << " " << this->m_publications << " " << this->m_cur_id << '\n';
    }
};
class Student : public Person
{
protected:
    int m_marks[6];
    int m_cur_id;
public:

    Student() {}
    ~Student()
    {
        std::cout << "Hello i'm a Student destructor" << "\n";
        delete this;
    }
    virtual void getdata()
    {
        numberStudent++;
        m_cur_id = numberStudent;
        std::cin >> this->m_name;
        std::cin >> this->m_age;
        for (int i = 0; i < 6; i++)
        {
            std::cin >> this->m_marks[i];
        }
    }
    virtual void putdata() const
    {
        int sum{ 0 };
        for (int i = 0; i < 6; i++)
        {
            sum = sum + m_marks[i];
        }
        std::cout << this->m_name << " " << this->m_age << " " << sum << " " << this->m_cur_id << '\n';
    }

};



int main() {
    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[4]; // visual studio <= 2013 not happy with this line 

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
