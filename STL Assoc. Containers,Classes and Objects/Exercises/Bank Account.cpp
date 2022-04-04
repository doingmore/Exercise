#include <iostream>


class BankAccount
{
private:
	std::string m_name;
	std::string m_codeIBN;
	double m_balance;
public:
	BankAccount(std::string name,std::string codeIBN,double balance) : m_name{name}, m_codeIBN{codeIBN}, m_balance{balance}
	{
	}

	void print() const
	{
		std::cout << "Account name: " << m_name << '\n' << "IBN: " << m_codeIBN << '\n' << "Balance: " << m_balance << '\n';
	}

	void addBalance(const double& operateSUM) { m_balance += operateSUM; }
	void withdrawBalance(const double& operateSUM)
	{
		if (m_balance < operateSUM)
		{
			std::cout << "Not enought balance!" << '\n';
		}
		else
		{
			m_balance -= operateSUM;
		}
	}
};

void withdrawBalance(BankAccount& object)
{
	double operateSUM{ 0 };
	std::cout << "Enter balance to Withdraw:" << '\n';
	std::cin >> operateSUM;
	object.withdrawBalance(operateSUM);
}

void addBalance(BankAccount& object)
{
	double operateSUM{ 0 };
	std::cout << "Enter balance to add:" << '\n';
	std::cin >> operateSUM;
	object.addBalance(operateSUM);
}

int main_EX3()
{
	std::string name;
	std::string IBN;
	double balance{ 0 };
	int choice{ 0 };
	bool flag = true;
	std::cin >> name >> IBN >> balance;
	BankAccount object{ name,IBN,balance };
	while (flag)
	{
	std::cout << "Would you like to do ?" << '\n';
	std::cout << "Press 1 to Show All Information" << '\n'
		<< "Press 2 to Add Balance" << '\n'
		<< "Press 3 to Withdraw Balance" << '\n'
		<< "Press 0 to Exit Program" << '\n';
		std::cin >> choice;
		switch (choice)
		{
			case 1: // show all information
				object.print();
				break;
			case 2: // add balance
				addBalance(object);
				break;
			case 3: // withdraw balance
				withdrawBalance(object);
				break;
			case 0: // to exit program
				flag = false;
				break;
		default:
			flag = false;
			break;
		}
	}

	return 0;
}