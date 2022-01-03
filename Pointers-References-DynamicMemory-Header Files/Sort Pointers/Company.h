#ifndef Company_H
#define Company_H

#include <vector>
#include <string>
#include <sstream>
#include <utility>

class Company
{
private:
	int m_id;
	std::string m_name;
public:
	Company(int id, std::string name)
	{
		m_id = id;
		m_name = name;
	}

	int getId() { return m_id; }
	std::string getName() { return m_name; }

	std::string toString()
	{
		std::ostringstream stream;
		stream << m_name << " " << m_id;
		return stream.str();
	}

};
#endif // !Company_H