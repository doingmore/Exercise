#include <iostream>
#include <vector>

class Country
{
private:
	std::string m_name;
	std::string m_capital;
	int m_population;
public:
	Country (std::string name,std::string capital, int population) : m_name(name), m_capital(capital), m_population(population)
	{}
	std::string getName() const { return m_name; }
	std::string getCapital() const { return m_capital; }
	int getPopulation() const { return m_population; }
};

int main()
{
	std::vector<Country> list;
	std::cout << "How many countries you want to input?" << '\n';
	int numberCountries{ 0 };
	int populationFilter{ 0 };
	std::cin >> numberCountries;
	std::string name;
	std::string capital;
	int population{ 0 };
	for (int i = 0; i < numberCountries; i++)
	{
		std::cout << "Enter country -> ";
		std::cin >> name;
		std::cout << "Enter capital -> ";
		std::cin >> capital;
		std::cout << "Enter population -> ";
		std::cin >> population;
		list.emplace_back(Country{ name,capital,population });
	}
	std::cout << "Which is the population(millions) that you want to filter ?" << '\n';
	std::cin >> populationFilter;
	if (list.size() > 0)
	{
		std::cout << "The countries with population, more or equal on " << populationFilter << " are: " << '\n';
	}
	for (Country country : list)
	{
		if (country.getPopulation() >= populationFilter)
		{
			std::cout << "Country -> " << country.getName() << '\n';
			std::cout << "Capital -> " << country.getCapital() << '\n';
			std::cout << "Population -> " << country.getPopulation() << '\n';
			std::cout << "========== SPACE =========" << '\n';
		}
	}

	return 0;
}