#include <iostream>


class Time
{
private:
	int m_seconds;
	int m_minutes;
	int m_hours;
public:
	Time(int seconds, int minutes, int hours) : m_seconds{ seconds }, m_minutes{minutes}, m_hours{hours}
	{}

	void printAbsoluteTime() // in seconds
	{
		std::cout << m_seconds << '\n'
			<< m_seconds + (m_minutes * 60) << '\n' 
			<< m_seconds + ((m_minutes * 60) + m_hours * 3600) << '\n';
	}

};


int main_5()
{
	int hours{ 0 };
	int minutes{ 0 };
	int seconds{ 0 };
	std::cin >> seconds >> minutes >> hours;

	Time t{ seconds,minutes,hours };

	t.printAbsoluteTime();
	return 0;
}