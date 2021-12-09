#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Coffee
{
private:
	string m_name;
	double m_price;
	double m_rating;
public:
	Coffee(string name, double price, double rating)
	{
		m_name = name;
		m_price = price;
		m_rating = rating;
	}
	string getName() { return m_name; };
	double getPrice() { return m_price; };
	double getRating() { return m_rating; };

	Coffee changePrice(double newPrice)
	{
		m_price = newPrice;
	}
};

void Problem3()
{
	int numberOfDrinks{ 0 };
	cin >> numberOfDrinks;
	vector<Coffee> menu;

	string name;
	double price{ 0 };
	double rating{ 0 };
	while (numberOfDrinks--)
	{
		cin >> name; //getline for product name of two words
		cin >> price;
		cin >> rating;
		if (rating < 4.00)
		{
			//do nothing
		}
		else if ((rating > 4) && (rating < 5.99))
		{
		price = price * 0.9;
		menu.push_back(Coffee(name, price, rating));
		}
		else
		{
		menu.push_back(Coffee(name, price, rating));
		}
	}

	vector<Coffee>::iterator it;
	for ( it = menu.begin(); it != menu.end(); it++)
	{
		cout << it->getName() << " " << it->getPrice()<<'\n';
	}
}