#ifndef ParseCompanies
#define ParseCompanies
#include <string>
#include <sstream>
#include <list>
#include "Company.h"

Company* parseUniqueCompanies(std::string streamWithCompanies, int& numCompanies, std::string choseFunction(const Company& c));

#endif // !ParseCompanies
