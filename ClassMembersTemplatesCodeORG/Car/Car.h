#ifndef Car
#define Car
#include <string>

class car
{
private:
	const std::string m_brand;
	const std::string m_model;
	const int m_year{ 0 };
public:
	car(std::string brand,std::string model,int year) : m_brand(brand), m_model(model), m_year(year)
	{
	// const member define not here ! 
	}

	//good practice getter const
	std::string getBrand() const { return m_brand; }
	std::string getModel() const { return m_model; }
	int getYear() const { return m_year; }
};

#endif // Car