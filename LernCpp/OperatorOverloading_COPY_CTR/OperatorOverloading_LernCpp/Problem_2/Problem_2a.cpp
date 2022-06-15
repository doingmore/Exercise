#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <iomanip>

/*
Write a class named Average that will keep track of the average of all integers
passed to it. Use two members: The first one should be type std::int_least32_t,
and used to keep track of the sum of all the numbers you’ve seen so far. The second should
be of type std::int_least8_t, and used to keep track of how many numbers you’ve seen so far.
You can divide them to find your average.
2a) Write all of the functions necessary for the following program to run:
*/

class Average
{
private:
	std::int_least32_t m_sum;
	std::int_least8_t m_number_of_numbers;

public:
	Average() : m_sum{ 0 }, m_number_of_numbers{ 0 }
	{}

	std::int_least32_t getSum() const { return m_sum; }
	std::int_least8_t getNumberOf() const { return m_number_of_numbers; }

	Average& operator+= (const int& left);



};

Average& Average::operator+= (const int& left)
{
	m_sum = m_sum + left;
	m_number_of_numbers++;
	return *this;
}

std::ostream& operator<< (std::ostream& stream, const Average& left)
{
	stream << static_cast<double>(left.getSum()) / static_cast<double>(left.getNumberOf());
	return stream;
}



// skeleton
int main()
{
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';
	return 0;
}
// skeleton