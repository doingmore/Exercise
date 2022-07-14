#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <sstream>

class Person
{
private:
	std::string m_name;
	int m_id;
public:
	Person(std::string name, int id) : m_name{ name }, m_id{id}
	{}

	std::string getName()const { return m_name; }
	int getId()const { return m_id; }
	void setName(const std::string& input){ m_name = input; }
	void setId(const int& number) {  m_id=number; }


	
};

std::ostream& operator<< (std::ostream& stream, const Person& object)
{
	stream << object.getName() << " " << object.getId() << '\n';
	return stream;
}

std::istream& operator>> (std::istream& in, Person& object)
{
	std::string name;
	int id;
	in >> name;
	in >> id;
	object.setName(name);
	object.setId(id);
	return in;
}

#endif // !PERSON_H
