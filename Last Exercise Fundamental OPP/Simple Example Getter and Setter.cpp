#include <iostream>

using namespace std;

class Date
{
private:
    int m_month;
    int m_day;
    int m_year;

public:
    int getMonth() { return m_month; } // getter for month
    void setMonth(int month) { m_month = month; } // setter for month

    int getDay() { return m_day; } // getter for day
    void setDay(int day) { m_day = day; } // setter for day

    int getYear() { return m_year; } // getter for year
    void setYear(int year) { m_year = year; } // setter for year
};

int main()
{
    Date toDay{};
    int userDay, userMonth, userYear;
    cout << "Enter today date:";
    cin >> userDay >> userMonth >> userYear;
    toDay.setDay(userDay);
    toDay.setMonth(userMonth);
    toDay.setYear(userYear);

    //print toDay info;
    cout << "You input today date: " << toDay.getDay() << " " << toDay.getMonth() << " " << toDay.getYear() << '\n';

    return 0;
}
