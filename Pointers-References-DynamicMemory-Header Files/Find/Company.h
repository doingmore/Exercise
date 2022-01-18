#ifndef Company_H
#define Company_H
#include <string>

class Company
{
private:
	std::string m_name;
	int m_id;
public:
	Company( std::string name, int id)
	{
		m_name = name;
		m_id = id;
	}

	std::string getName() { return m_name; };
	int getId() { return m_id; };
};
#endif // !Company_H
