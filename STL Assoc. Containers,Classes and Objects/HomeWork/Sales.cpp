#include <iostream>
#include <vector>
#include <map>
class Sales
{
private:
	std::string m_city;
	std::string m_product;
	double m_price;
	int m_quantity;
public:
	Sales(std::string city , std::string product , double price , int quantity) :
		m_city{city},
		m_product{product},
		m_price{price},
		m_quantity{quantity} {}

	std::string getCity() const { return m_city; }
	std::string getProduct() const { return m_product; };
	double getPrice() const { return m_price; };
	int getQuantity() const { return m_quantity; };
};

void update(std::map<std::string, double>& listTown , const std::vector<Sales>& all)
{
	std::map<std::string, double>::iterator it;
	for (size_t i = 0; i < all.size(); i++)
	{
		it=listTown.find(all[i].getCity());
		it->second += all[i].getPrice() * all[i].getQuantity();
	}
}


int main()
{
	int nubmerSales{ 0 };
	std::cin >> nubmerSales;
	std::vector<Sales> allSales;
	std::map<std::string, double> listTown;
	std::string city;
	std::string product;
	double price;
	int quantity;
	for (int i = 0; i < nubmerSales; i++)
	{
		std::cin >> city >> product >> price >> quantity;
		allSales.emplace_back(Sales{ city,product,price,quantity });
		listTown.emplace(city, 0);
	}
	update(listTown, allSales);
	
	std::map<std::string, double>::iterator it;
	for (it = listTown.begin(); it != listTown.end(); it++)
	{
		std::cout << it->first << " -> " << it->second << '\n';
	}

	return 0;
}