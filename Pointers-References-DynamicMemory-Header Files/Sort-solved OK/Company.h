#ifndef Company_H
#define Company_H
//This file is skeleton 


#include <string>
#include <sstream>
#include <vector>
#include <utility>

class Company
{
private:
	int m_id;
	std::string m_name;
public:
	Company() {}

	Company(int id, std::string name)
	{
		m_id = id;
		m_name = name;
	}
	
	std::string toString()
	{
		std::ostringstream stream;
		stream << m_name << " " << m_id;
		return stream.str();
	}

	std::string getName() { return m_name; }
	int getID() { return m_id; }

};
#endif // !Company_H
