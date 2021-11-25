#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*
* Write a program, make a Class Student. For given numbers the program should filter the students by MINIMUM VOTE,
if the MINIMUM VOTE is greater or equal to the students vote, the program should give information. 
If the VOTE is lower than the filtered the program should NOT give information.
*/

class Student {

private:
	string m_name;
	string m_surname;
	int m_age;
	double m_vote;

public:

	Student(string name_, string surname_, int age_, double vote_) :
		m_name(name_),
		m_surname(surname_),
		m_age(age_),
		m_vote(vote_) {
	}

	// Setters
	// void setName(string name_) { m_name = name_; }
	// void setSurname(string surname_) { m_surname = surname_;  }
	// void setAge(int age_) { m_age = age_; }
	// void setVote(int vote_) { m_vote = vote_; }

	double getVote() { return m_vote; }

	string getData() {
		ostringstream ostr;

		ostr << "Name -> " << m_name << " " << m_surname << endl
			<< "Age -> " << m_age << endl
			<< "Vote -> " << m_vote;

		return ostr.str();
	}
};

void Problem1() {

	unsigned studentCount;
	string name;
	string surname;
	int age;
	double vote;
	vector<Student> students;

	cout << "How many students you want to input ?" << '\n';
	cin >> studentCount;

	while (studentCount--)
	{

		cout << "Enter name: " << '\n';
		cin >> name;
		cout << "Enter surname: " << '\n';
		cin >> surname;
		cout << "Enter age: " << '\n';
		cin >> age;
		cout << "Enter vote (the vote can be with decimal point): " << '\n';
		cin >> vote;

		students.push_back(Student(name, surname, age, vote));
	}

	double minVote;
	cout << "Which is the minimal vote that you would like to filter?" << '\n';
	cin >> minVote;

	cout.precision(1);
	cout << "The students with enough vote -> " << minVote << " are:" << '\n';

	for (vector<Student>::iterator itStud = students.begin(); itStud != students.end(); itStud++)
	{

		if (itStud->getVote() >= minVote)
		{
			cout << itStud->getData() << '\n';
		}
	}
}