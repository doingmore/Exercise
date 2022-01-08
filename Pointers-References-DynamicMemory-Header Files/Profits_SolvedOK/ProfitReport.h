#ifndef ProfitReport_h
#define ProfitReport_h
#include <map>        

std::string getProfitReport(Company* fromInclusive, Company* toInclusive, std::map<int, ProfitCalculator>& profitCalculatorsByCompany);

#endif // !ProfitReport_h
