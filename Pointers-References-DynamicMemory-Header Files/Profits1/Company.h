#ifndef Company_h
#include <string>

class Company
{
private:
	std::string m_name;
	int m_iD;
	int m_revenue;
	int m_costs;
public:
	Company(std::string name, int iD, int revanue, int costs)
	{
		m_name = name;
		m_iD = iD;
		m_revenue = revanue;
		m_costs = costs;
	}

	//getters
	std::string getName() { return m_name; };
	int getID() { return m_iD; };
	int getRevenue() { return m_revenue; };
	int getCosts() { return m_costs; };

};


#define Company_h
#endif // !Company_h