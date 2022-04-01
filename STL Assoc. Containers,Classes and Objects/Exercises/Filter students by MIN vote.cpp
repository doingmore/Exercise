#include <iostream>
#include <vector>

class Student
{
private:
	std::string m_name;
	std::string m_surname;
	int m_age;
	double m_vote;
public:
	Student(std::string name, std::string surname,int age,double vote) : 
		m_name{name},
		m_surname{surname},
		m_age{age},
		m_vote{ vote } 
	{}

	void report() const
	{
		std::cout << "Name" << " -> " << m_name<<" " << m_surname << '\n'
			<< "Age" << " -> " << m_age << '\n'
			<< "Vote" << " -> " << m_vote << '\n';
	}

	double getVote() const { return m_vote; }
};

int mainEX1()
{
	int numberStudents{ 0 };
	std::cin >> numberStudents;
	std::vector<Student> list;
	std::string name;
	std::string surname;
	int age;
	double vote;

	for (int i = 0; i < numberStudents; i++)
	{
		std::cin >> name >> surname >> age >> vote;
		list.emplace_back(Student{ name,surname,age,vote });
	}

	double minVote{ 0 };
	std::cout << "Enter minimum vote for students: ";
	std::cin >> minVote;

	for (Student s : list)
	{
		if (s.getVote() >= minVote)
		{
			s.report();
		}
	}

	return 0;
}