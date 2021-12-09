#include <iostream>
#include <vector>

using namespace std;

class Product
{
private:
	string m_product;
	double m_price;
	int m_countProduct;
public:
	Product(string product, double price, int countProduct)
	{
		m_product = product;
		m_price = price;
		m_countProduct = countProduct;
	}

	double getPrice() { return m_price; };
	int getCountProduct() { return m_countProduct; };
	string getProduct() { return m_product; };

};

void Problem1()
{
	int numberOfProducts{ 0 };
	cin >> numberOfProducts;
	vector<Product> list;
	string product;
	double price{0};
	int countOfProduct{0};
	double totalSum{0};

	while (numberOfProducts--)
	{
		cin >> product >> price >> countOfProduct;
		list.push_back(Product(product, price, countOfProduct));
	}


	//For total sum
	vector<Product>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		totalSum += ((it->getPrice()) * (it->getCountProduct()));
	}
	cout << "The total sum is: " << totalSum << '\n';
	
	//for print info
	for (it = list.begin(); it != list.end(); it++)
	{
		cout << it->getProduct() << " " << ((it->getPrice()) * (it->getCountProduct())) << '\n';
	}
}