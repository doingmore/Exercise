#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <sstream>

class HasInfo
{

};


class Company : public HasInfo
{
private:
	int id;
	std::string name;
	std::vector<std::pair<char, char> > employees;
public:
	Company() {}
	Company(int id, std::string name, std::vector<std::pair<char, char> > employees)
		: id(id)
		, name(name)
		, employees(employees) {}

	int getId() const;
	std::string getName() const;
	std::vector<std::pair<char, char> > getEmployees() const;
	std::string getInfo() const;

	friend std::ostream& operator<<(std::ostream& stream, const Company& c);
	friend std::istream& operator>>(std::istream& stream, Company& c);
};


#endif // !COMPANY_H
