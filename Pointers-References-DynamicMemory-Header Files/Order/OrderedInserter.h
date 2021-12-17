#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include <string>
#include "Company.h"

class OrderedInserter
{
private:
	std::string m_name;
	int m_iD;
public:
	OrderedInserter(std::string name, int iD)
	{
		m_name = name;
		m_iD = iD;
	}

	std::string getName() { return m_name; };
	int getID() { return m_iD; };

};
#endif // !ORDERED_INSERTER_H