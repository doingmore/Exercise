#include <map>        
#include <sstream>

#include "ProfitReport.h"
#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(Company* fromInclusive, Company* toInclusive, std::map<int, ProfitCalculator>& profitCalculatorsByCompany)
{
	std::string something = "yes";
	int profit{ 0 };
	std::ostringstream stream;
	std::string space = " = ";

	unsigned int numberIteration{ profitCalculatorsByCompany.size() };
	Company* ptr = fromInclusive;
	while (numberIteration--)
	{

		std::map<int, ProfitCalculator>::iterator it = profitCalculatorsByCompany.begin();
		for (size_t i = 0; i < profitCalculatorsByCompany.size(); i++)
		{
			if (ptr->getId() == (it->first))
			{
				profit = it->second.calculateProfit(*ptr);
				stream << ptr->getName();
				stream << space;
				stream << profit;
				stream << '\n';
				break;
			}
			it++;
		}
		ptr++;
	}

	return stream.str();
}
