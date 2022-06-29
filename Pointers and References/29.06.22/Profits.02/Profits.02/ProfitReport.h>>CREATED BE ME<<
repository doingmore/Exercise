#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H
#include <string>
#include <vector>

#include "Company.h"
#include "ProfitCalculator.h"


std::string getProfitReport( Company* fromInclusive,   Company* toInclusive, const std::map<int, ProfitCalculator>& map)
{
	std::string answer;

	Company* iterate = fromInclusive;
	for (size_t i = 0; i < map.size(); i++)
	{
		answer += iterate->getName();
		answer += " = ";
		int id{ iterate->getId() };
		int profit{ map.find(id)->second.calculateProfit(*iterate) };
		answer += std::to_string(profit);


		answer += '\n';
		if (i < ( map.size()-1 ) ) // The iterate pointer in last iterate no go at next adres
		{
		iterate++;
		}
	}


	return answer;
}


#endif // !PROFIT_REPORT_H
