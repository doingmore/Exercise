#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person
{
public:
	Person(const std::string& name, const int& id)
		: m_name{name}
		, m_id{id}
	{
		std::cout << "Person constructor has been executed" << '\n';
	}
	~Person()
	{
		std::cout << "Person destructor has been executed" << '\n';
	}

	Person(const Person& other)
		: m_name{ other.m_name }
		, m_id{ other.m_id }
	{
		std::cout << "Person copy CTR has been executed" << '\n';
	}

	Person& operator= (const Person& other)
	{
		if (this == &other)
		{
			return *this;
		}

		m_name = other.m_name;
		m_id = other.m_id;

		std::cout << "Person assignment operator has been executed" << '\n';

		return *this;
	}


	std::string getReport() const
	{
		std::string answer;
		answer += m_name;
		answer += " ";
		answer += std::to_string(m_id);
		return answer;
	}

private:
	std::string m_name;
	int m_id;
};


#endif // !PERSON_H

