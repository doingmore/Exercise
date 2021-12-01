#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class BankAccount
{
private:
	string m_userName;
	string m_accountNum;
	double m_balance;
public:
	BankAccount(string username, string accountNum, double balance) :
		m_userName(username),
		m_accountNum(accountNum),
		m_balance(balance) {
	}

	void print()
	{
		cout << "Name: " << m_userName << '\n'
			<< "Account number: " << m_accountNum << '\n'
			<< "Balance: " << m_balance << '\n';
	}

	void addBalance(double newAddBalance)
	{
		m_balance = m_balance + newAddBalance;
	}

	void withdrawBalance(double withdrawBalance)
	{
		m_balance = m_balance - withdrawBalance;
	}

};

enum conditions
{
	Exit = 0,
	Show,
	Add,
	Withdraw
};

conditions process(BankAccount& account)
{
	cout << "Would you like to do ?" << '\n';
	cout << "Press 1 to Show All Information..." << '\n';
	cout << "Press 2 to Add Balance..." << '\n';
	cout << "Press 3 to Withdraw Balance..." << '\n';
	cout << "Press 0 to Exit Program..." << '\n';

	int choice{ 0 };
	cin >> choice;
	double changeBalance{ 0 };
	if ((choice < 0) || (choice > 3))
	{
		cout << "Your choice is not currect, please choice what you wanna do again." << '\n';
	}
	else
	{
		switch (choice)
		{
		case 1:
			account.print();
			break;
		case 2:
			cin >> changeBalance;
			account.addBalance(changeBalance);
			break;
		case 3:
			cin >> changeBalance;
			account.withdrawBalance(changeBalance);
			break;
		default:
			break;
		}
	}
	return (conditions)choice;
}

void MyProblem3()
{
	string userName;
	string accountNum;
	double balance;

	cout << "Enter Name: " << '\n';
	cin >> userName;
	cout << "Enter 5 charactes IBAN Code: " << '\n';
	cin >> accountNum;
	cout << "Enter initial Balance: " << '\n';
	cin >> balance;

	BankAccount acc(userName, accountNum, balance);
	int breakNum{ 0 };

	while (true)
	{
		breakNum = process(acc);
		if (breakNum == conditions::Exit)
		{
			break;
		}
	}
}