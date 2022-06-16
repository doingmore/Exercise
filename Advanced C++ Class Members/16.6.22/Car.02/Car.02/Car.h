#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>


class Car
{
private:
	std::string m_brand;
	std::string m_model;
	int m_year;
public:
	Car(const std::string& brand, const std::string& model, const int& year);

	std::string getBrand()const { return m_brand;}
	std::string getModel()const { return m_model;}
	int getYear()const { return m_year; }

};


#endif // !CAR_H


