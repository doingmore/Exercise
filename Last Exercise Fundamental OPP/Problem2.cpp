#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Country {

private:
	string m_name;
	string m_capital;
	int m_millionsPopulation;

public:

	Country(string name, string capital, int millionsPopulation) :
		m_name(name),
		m_capital(capital),
		m_millionsPopulation(millionsPopulation) {
	}

	bool populationEquals(int millions) {return m_millionsPopulation == millions; }
	
	ostringstream stream;
	
	string getData(void) {
		stream << "Country -> " << m_name << '\n'<< "Capital -> " << m_capital << '\n'<< "Population(millions) -> " << m_millionsPopulation;
		return stream.str();
	}

};

void Problem2(void) {

	unsigned countriesCount;
	string name;
	string capital;
	int millions;
	int millionsToFilter;

	cout << "How many countries you want to input ?" << '\n';
	cin >> countriesCount;

	vector<Country> countries;

	while (countriesCount--) 
	{
		cout << "Enter Country ->" << '\n';
		cin >> name;
		cout << "Enter Capital ->" << '\n';
		cin >> capital;
		cout << "Enter Population ->" << '\n';
		cin >> millions;

		countries.push_back(Country(name, capital, millions));
	}

	cout << "Which is the populations (millions) that you want to filter ?" << '\n';
	cin >> millionsToFilter;

	cout << "The countries with Population " << millionsToFilter << " millions are:" << '\n';

	for (vector<Country>::iterator itCountry = countries.begin(); itCountry != countries.end(); itCountry++)
	{

		if (itCountry->populationEquals(millionsToFilter))
		{
			cout<<itCountry->getData();
			'\n';
		}
	}
}