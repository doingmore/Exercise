#include <iostream>
#include <string>

/*
A string-value pair is a special type of pair where the first value is always a string type, 
and the second value can be any type. Write a template class named StringValuePair
that inherits from a partially specialized Pair class (using std::string as the first type,
and allowing the user to specify the second type).
The following program should run:
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

	const T first() const { return m_first; }
	const U second() const { return m_second; }
};

template<typename U>
class StringValuePair : public Pair<std::string,U>
{
public:
	StringValuePair(const std::string& first, const U& second) : Pair<std::string,U>{ first , second}
	{}
};


// skeleton from here
int main()
{
	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}
// to here