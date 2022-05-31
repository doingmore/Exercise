#include <iostream>
#include <string>

/*
Write a class named Average that will keep track of the average of all integers passed to it.
Use two members: The first one should be type std::int_least32_t, and used to keep track
of the sum of all the numbers you’ve seen so far. The second should be of type std::int_least8_t,
and used to keep track of how many numbers you’ve seen so far. You can divide them to find your average.
*/

// .h
class Average
{
private:
	std::int_least32_t m_sum;
	std::int_least8_t m_number_digits;
public:
	Average() : m_sum{ 0 }, m_number_digits{ 0 }
	{}
	Average(const Average& other);

	friend std::ostream& operator<< (std::ostream& stream, const Average& object);
	Average& operator+= (const int& number);
};
// .h

// .cpp
Average::Average(const Average& other) : m_sum{ other.m_sum }, m_number_digits{ other.m_number_digits }
{}

std::ostream& operator<< (std::ostream& stream, const Average& object)
{
	stream << static_cast<double>(object.m_sum / object.m_number_digits);
	return stream;
}

Average& Average::operator+= (const int& number)
{
	this->m_sum = this->m_sum + static_cast<std::int_least32_t>(number);
	this->m_number_digits = this->m_number_digits + static_cast<std::int_least32_t>(1);
	return *this;
}
// .cpp


int main_1()
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