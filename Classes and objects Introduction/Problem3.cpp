#include <iostream>
#include <iomanip>

using namespace std;
/*
Write a class Sale holding the following data : town, win.
Read a list of salesand calculateand print the total sales by town as shown in the output.
*/

class Sales
{
private:
	double m_win;
public:
	double getSales() { return m_win; }
	void setWin(double add) { m_win = m_win + add; }
};

int Problem3()
{
	int count;
	cin >> count;

	string place, product;
	double price, profit;
	int amount;


	Sales Sofia{};
	Sales Plovdiv{};
	Sales Varna{};

	for (unsigned i = 0; i < count; i++)
	{
		cin >> place >> product >> price >> amount;
		profit = price * amount;
		if (place == "Sofia")
		{
			Sofia.setWin(profit);
		}
		else if (place == "Plovdiv")
		{
			Plovdiv.setWin(profit);
		}
		else if (place == "Varna")
		{
			Varna.setWin(profit);
		}
	}

	cout << "=========================" << '\n';

	cout << setprecision(6) << "Sofia -> " << Sofia.getSales() << '\n'
		<< "Plovdiv -> " << Plovdiv.getSales() << '\n'
		<< "Varna -> " << Varna.getSales() << '\n';
}