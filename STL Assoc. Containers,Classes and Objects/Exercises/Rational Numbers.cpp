#include <iostream>
#include <sstream>
#include <string>

class RationalNumbers
{
private:
	int m_numerator;
	int m_denumerator{1};
public:
	RationalNumbers() {}
	RationalNumbers(int& numerator, int& denumerator) : m_numerator{ numerator }, m_denumerator{ denumerator }
	{}

	void setDenumerator(int& denumerator) { m_denumerator = denumerator; }
	void setNumerator(int& numerator) { m_numerator = numerator; }
	int getNumerator() const { return m_numerator; }
	int getDenumerator() const { return m_denumerator; }

	RationalNumbers& difference(const RationalNumbers& number) const
	{
		RationalNumbers answer;
		int answerNumerator{ (this->getNumerator() * number.getDenumerator() ) - (number.getNumerator() * this->getDenumerator()) };
		int answerDenumerator{ this->getDenumerator() * number.getDenumerator() };
		answer.setDenumerator(answerDenumerator);
		answer.setNumerator(answerNumerator);
		return answer;
	}
	RationalNumbers& sum(const RationalNumbers& number) const
	{
		RationalNumbers answer;
		int answerNumerator{ (this->getNumerator() * number.getDenumerator()) + (number.getNumerator() * this->getDenumerator()) };
		int answerDenumerator{ this->getDenumerator() * number.getDenumerator() };
		answer.setDenumerator(answerDenumerator);
		answer.setNumerator(answerNumerator);
		return answer;
	}
	RationalNumbers& multiplication(const RationalNumbers& number) const
	{
		RationalNumbers answer;
		int answerNumerator{ this->getNumerator() * number.getNumerator() };
		int answerDenumerator{ this->getDenumerator() * number.getDenumerator() };
		answer.setDenumerator(answerDenumerator);
		answer.setNumerator(answerNumerator);
		return answer;
	}
	RationalNumbers& division(const RationalNumbers& number) const
	{
		RationalNumbers answer;
		int answerNumerator{ this->getNumerator() * number.getDenumerator() };
		int answerDenumerator{ this->getDenumerator() * number.getNumerator() };
		answer.setDenumerator(answerDenumerator);
		answer.setNumerator(answerNumerator);
		return answer;
	}

	std::string print() const
	{
		std::stringstream stream;
		stream<< m_numerator << "/" << m_denumerator;
		return stream.str();
	}

};

int mainEX4()
{
	int fNumerator{ 0 };
	int fDenumerator{ 0 };
	int sNumerator{ 0 };
	int sDenumerator{ 0 };
	std::cout << "Enter first rational number numerator: ";
	std::cin >> fNumerator;
	std::cout << "Enter first rational number denumerator: ";
	std::cin >> fDenumerator;
	std::cout << "Enter second rational number numerator: ";
	std::cin >> sNumerator;
	std::cout << "Enter second rational number denumerator: ";
	std::cin >> sDenumerator;

	RationalNumbers first{ fNumerator,fDenumerator };
	RationalNumbers second{ sNumerator,sDenumerator };
	RationalNumbers sum{first.sum(second)};
	RationalNumbers difference{ first.difference(second) };
	RationalNumbers multiplication{first.multiplication(second)};
	RationalNumbers division{first.division(second)};

	std::cout << "Sum: " << sum.print() << '\n'
		<< "Difference: " << difference.print() << '\n'
		<< "Multiplication: " << multiplication.print() << '\n'
		<< "Division: " << division.print() << '\n';

	return 0;
}