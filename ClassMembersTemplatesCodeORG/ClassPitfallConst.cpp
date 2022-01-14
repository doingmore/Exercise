#include <iostream>
#include <string>

class Person {
	int m_age;
public:
	const std::string m_name;

	// correct constructor: 
	// Person(std::string name, int age) : m_name(name), m_age(age) {}
	Person(std::string name, int age) {
		this->m_name = name;
		this->m_age = age;
	}

	// correct getter, so that the printOlderPerson function below compiles:
	//int getAge() const {
	//	return this->m_age;
	//}
	int getAge() const {
		return this->m_age;
	}
};

void printOlderPerson(const Person& a, const Person& b) {
	if (a.getAge() >= b.getAge()) {
		std::cout << a.m_name << std::endl;
	}
	else {
		std::cout << b.m_name << std::endl;
	}
}

int main() {
	Person a{ "joro", 26 };
	Person b{ "ben dover", 46 };

	printOlderPerson(a, b);

	return 0;
}
