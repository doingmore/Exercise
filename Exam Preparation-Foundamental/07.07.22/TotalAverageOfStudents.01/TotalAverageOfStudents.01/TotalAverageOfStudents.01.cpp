#include <iostream>
#include <vector>
#include <string>

class Student
{
private:
    std::string m_name;
    std::string m_surname;
    double m_average;
public:
    Student(const std::string& name, const std::string& surname, const double& average) 
        : m_name{name}
        , m_surname{surname}
        , m_average{average}
    {}

    double getAverage()const { return m_average; }

    void print() const
    {
        std::cout << m_name << " " << m_surname << " " << m_average << '\n';
    }
};



int main()
{
    int numberStudents{ 0 };
    std::cin >> numberStudents;
    std::vector<Student> students;
    for (int i = 0; i < numberStudents; i++)
    {
        std::string name;
        std::string surname;
        double average;
        std::cin >> name;
        std::cin >> surname;
        std::cin >> average;

        students.emplace_back(Student{ name,surname,average });
    }

    double totalAverage{ 0 };
    for (const Student& s : students)
    {
        s.print();
        totalAverage = totalAverage + s.getAverage();
    }
    std::cout << totalAverage/numberStudents << '\n';

    return 0;
}
