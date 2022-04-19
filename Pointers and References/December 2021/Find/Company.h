#ifndef Company_h
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

#define Company_h
#endif // !Company_h
