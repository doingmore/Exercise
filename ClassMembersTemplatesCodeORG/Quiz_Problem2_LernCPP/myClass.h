#ifndef myClass_H
#define myClass_H

template <typename T, typename K>
class Pair
{
private:
	T m_firstNumber{};
	K m_secondNumber{};
public:
	Pair(const T first, const K second) : m_firstNumber{ first }, m_secondNumber{ second }
	{
	}

	const T& first() const { return m_firstNumber; }
	const K& second() const { return m_secondNumber; }

};


#endif // !myClass_H
