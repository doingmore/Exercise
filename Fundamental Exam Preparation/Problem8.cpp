#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
Write a program, use a class that has params:
•	Student Name
•	Student Surname
•	Total Average
The class should have Print method that for a given object prints all the information
Make a vector in main that for a given number ( passed thru user ) saves the objects
Make a function that calculates the Total AVERAGE of ALL students
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

	double getAssessment() { return m_assessment; }

	string printData()
	{
		ostringstream stream;
		stream << m_name << " " << m_surName << " " << m_assessment << "\n";
		return stream.str();
	}
};

double getAverageVote(vector<Student>& students)
{
	double averageVote{ 0 };
	int counterStudent{ 0 };
	vector<Student>::iterator it;
	for (it = students.begin(); it != students.end(); it++)
	{
		averageVote += it->getAssessment();
		counterStudent++;
	}
	averageVote = averageVote / counterStudent;
	return averageVote;
}

void Problem8()
{
	int numbersStudents{ 0 };
	cout << "How many student have? ";
	cin >> numbersStudents;
	string name;
	string surName;
	double assessment;
	vector<Student> students;

	for (int i = 0; i < numbersStudents; i++)
	{
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surName;
		cout << "Enter assissment: ";
		cin >> assessment;
		students.push_back(Student(name, surName, assessment));
	}

	vector<Student>::iterator it;
	for (it = students.begin(); it != students.end(); it++)
	{
		cout << it->printData();
	}

	cout << "Average vote on students is: " << getAverageVote(students) << '\n';
}