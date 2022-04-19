#include <iostream>
#include <vector>
#include <string>

class Coffee
{
private:
	std::string m_product;
	double m_price;
	double m_rating;
public:
	Coffee(std::string name, double price, double rating) : m_product{ name }, m_price{price}, m_rating{rating} 
	{}

	std::string getName() const { return m_product; }
	double getRating() const { return m_rating ; }
	double getPrice() const { return m_price; }

	void changePrice()
	{
		this->m_price = this->m_price * 0.9;
	}

	~Coffee()
	{}
};

void actualization(std::vector<Coffee>& menu)
{
	std::vector<Coffee> temporary{ menu };
	menu.clear();
	for (Coffee o : temporary)
	{
		if (o.getRating() > 4)
		{
			menu.emplace_back(o);
		}
	}
	temporary.clear();

	for (size_t i = 0; i < menu.size(); i++)
	{
		if (menu[i].getRating() >= 4 && menu[i].getRating() < 6)
		{
			menu[i].changePrice();
		}
	}
} 


int main()
{
	std::vector<Coffee> menu;
	int numberDrinks{ 0 };
	std::cin >> numberDrinks;
	std::string name;
	double price;
	double rating;

	for (int i = 0; i < numberDrinks; i++)
	{
		std::cin.ignore();
		std::getline(std::cin, name);
		std::cin >> price >> rating;
		menu.emplace_back(Coffee{name,price,rating});
	}
	
	actualization(menu);

	for (size_t i = 0; i < menu.size(); i++)
	{
		std::cout << menu[i].getName() << " " << menu[i].getPrice() << '\n';
	}
	return 0;
}