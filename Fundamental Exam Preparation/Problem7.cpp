#include <iostream>
#include <string>

using namespace std;

/*
Write a program, use a class that has params:
•	Student Name
•	Student Surname
•	Total Average
The class should have Print method that for a given object prints all the information
*/

class Student
{
private:
	string m_name;
	string m_surName;
	double m_assessment;

public:
	Student(string name, string surName, double assessment)
	{
		m_name = name;
		m_surName = surName;
		m_assessment = assessment;
	}

	void printData()
	{
		cout << m_name << " " << m_surName << " " << m_assessment << '\n';
	}

};

void Problem7()
{
	string name;
	string surName;
	double assessment;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surName;
	cout << "Enter total average: ";
	cin >> assessment;

	Student myStudent(name, surName, assessment);

	myStudent.printData();
}