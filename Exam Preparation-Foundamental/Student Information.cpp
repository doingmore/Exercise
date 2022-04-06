#include <iostream>
#include <vector>

class Student
{
private:
	std::string m_name;
	std::string m_surname;
	double m_totalAverage;
public:
	Student(std::string name, std::string surname, double evaulation) : 
		m_name{ name },
		m_surname{ surname },
		m_totalAverage{evaulation}
	{}

	void print() const
	{
		std::cout << m_name <<" "<< m_surname << " -> " << m_totalAverage << '\n';
	}

};

int main_6()
{
	std::vector<Student> list;
	int numberStudent{ 0 };
	std::string name;
	std::string surname;
	double evaulation{ 0 };
	std::cin >> numberStudent;
	for (int i = 0; i < numberStudent; i++)
	{
		std::cin >> name >> surname >> evaulation;
		list.emplace_back(Student{ name,surname,evaulation });
	}

	for ( Student s : list ) // base range for loop
	{
		s.print();
	}

	return 0;
}