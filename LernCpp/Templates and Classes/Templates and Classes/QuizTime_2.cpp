#include <iostream>

/*
Write a Pair class that allows you to specify separate types for each of the two values in the pair.
Note: We’re naming this class differently from the previous one because C++ does not currently allow you
to “overload” classes that differ only in the number or type of template parameters.

The following program should work:
*/


template<typename T, typename U>
class Pair
{
private:
	T m_first;
	U m_second;
public:
	Pair(const T& first, const U& second) : m_first{ first }, m_second{ second }
	{}

	T first() const { return m_first; }
	U second() const { return m_second; }
};


// skeleton from here
int main()
{
	Pair<int, double> p1{ 5, 6.7 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2{ 2.3, 4 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}
// to here