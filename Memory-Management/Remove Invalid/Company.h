#ifndef Company_H
#define Company_H

#include <iostream>
#include <string>
#include <xlocnum>


class Company
{
private:
	int m_id{ 0 };
	std::string m_name;
public:
	Company(int id,std::string name) 
	{
		m_id = id;
		m_name = name;
	}
	~Company()
	{
		m_id;
		m_name;
		std::cout << "Hello I'm destructor"<<'\n';
	}
	//Getters
	int getID() { return m_id; };
	std::string getName() { return m_name; };

};

#endif // !Company_H