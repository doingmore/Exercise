#ifndef Fraction
#define Fraction

class fraction
{
private:
	int m_numerator;
	int m_denumerator;
public:
	fraction(int numerator, int denumerator=1)
	{
		m_numerator = numerator;
		m_denumerator = denumerator;
	}

	int getNumerator() const { return m_numerator; }
	int getDenumerator() const { return m_denumerator; }

	void print() const
	{
		std::cout << this->getNumerator() << "/" << this->getDenumerator() << '\n';
	}

	// We don't want to pass by value, because copying is slow.
	// We can't and shouldn't pass by non-const reference, because then
	// our functions wouldn't work with r-values.
	friend fraction operator*(const fraction& f1, const fraction& f2);
	friend fraction operator*(const fraction& f1, int value);
	friend fraction operator*(int value, const fraction& f1);
};

#endif // !Fraction

