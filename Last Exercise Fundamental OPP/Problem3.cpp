#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class BankAccount 
{

private:
    string m_user;
    string m_accountNum;
    double m_ballance;
public:
    BankAccount(string user, string accountNum, double ballance) :
        m_user(user),
        m_accountNum(accountNum),
        m_ballance(ballance) {
    }

    void setInitialBallance(double ballance_) {
        m_ballance = ballance_;
    }

    void setAccountNumber(string newAccNumber) {
        m_accountNum = newAccNumber;
    }

    double GetBallance(void) { return m_ballance; }

    void Print(ostream& output) {
        output << "Name : " << m_user << '\n'
            << "Account number : " << m_accountNum << '\n'
            << "Ballance : " << m_ballance << '\n';
    }

    void addBallance(double addedBallance, ostream& output) {
        m_ballance += addedBallance;
        output << "Added: " << addedBallance << '\n'
            << "New Ballance: " << m_ballance << '\n';
    }

    void withdrawBallance(double withdrawedBallance, ostream& output) {
        if (m_ballance < withdrawedBallance) {
            output << "Not Enought Balance !" << '\n';
            return;
        }
        m_ballance -= withdrawedBallance;
    }

};


enum conditions 
{
    Exit = 0,
    ShowAll,
    Add,
    Withdraw 
};

conditions Process(BankAccount& account) {

    cout << "Would you like to do ?" << '\n';
    cout << "Press 1 to Show All Information..." << '\n';
    cout << "Press 2 to Add Balance..." << '\n';
    cout << "Press 3 to Withdraw Balance..." << '\n';
    cout << "Press 0 to Exit Program..." << '\n';

    int choice;
    cin >> choice;

    double ballanceChange;

    switch ((conditions)choice) 
    {
    case conditions::ShowAll:
        account.Print(cout);
        break;
    case conditions::Add:
        cout << "Enter Balance to Add :" << '\n';
        cin >> ballanceChange;
        account.addBallance(ballanceChange, cout);
        break;
    case conditions::Withdraw:
        cout << "Enter Balance to Withdraw :" << '\n';
        cin >> ballanceChange;
        account.withdrawBallance(ballanceChange, cout);
        break;
    case conditions::Exit: break;
    default:
        // error message, incorrect choice by the user
        break;
    }

    return (conditions)choice;
}

void Problem3(void) {

    string user;
    string accountNum;
    double ballance;

    cout << "Enter Name :" << '\n';
    cin >> user;
    cout << "Enter 5 charactes IBAN Code :" << '\n';
    cin >> accountNum;
    cout << "Enter Initial Balance :" << '\n';
    cin >> ballance;

    BankAccount acc(user, accountNum, ballance);

    while (Process(acc) != conditions::Exit);

}