#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class RationalNumber
{
private:
	int m_numerator;
	int m_denumerator;
public:

	RationalNumber(int num_, int denum_)
	{
		m_numerator = num_;
		m_denumerator = denum_;
	}

	int getNumerator() { return m_numerator; }
	int getDenumerator() { return m_denumerator; }
	void setNumerator(int newNumerator) { m_numerator = newNumerator; }
	void setDenumerator(int newDenumerator) { m_numerator = newDenumerator; }

	RationalNumber Add(RationalNumber& RN)
	{
		int num;
		int denum;
		num = (((m_numerator) * (RN.getDenumerator())) + ((m_denumerator) * (RN.getNumerator())));
		denum = ((m_denumerator) * (RN.getDenumerator()));
		return RationalNumber(num, denum);
	}

	RationalNumber substraction(RationalNumber& firstRN, RationalNumber& secondRN)
	{
		int num;
		int denum;
		num = (((firstRN.getNumerator()) * (secondRN.getDenumerator())) - ((firstRN.getDenumerator()) * (secondRN.getNumerator())));
		denum = ((firstRN.getDenumerator()) * (secondRN.getDenumerator()));
		return RationalNumber(num, denum);
	}

	string toString()
	{
		ostringstream stream;
		stream << m_numerator << "/" << m_denumerator << '\n';
		return stream.str();
	}
	

	/*
	RationalNumber multiplication(RationalNumber& firstLocalRN, RationalNumber& secondLocalRN)
	{

	}

	RationalNumber division(RationalNumber& firstLocalRN, RationalNumber& secondLocalRN)
	{

	}
	*/
};


RationalNumber getValuesFromUser(string count)
{
	int num{ 0 };
	int denum{ 0 };
	cout << "Enter " << count << " rational number numerator : ";
	cin >> num;
	cout << "Enter " << count << " rational number denumerator : ";
	cin >> denum;

	if (denum == 0)
	{
		denum = 1;
	}

	return RationalNumber(num, denum);
}

void MyProblem4()
{
	int choice{ 0 };
	RationalNumber firstRationalNumber(getValuesFromUser("first"));
	RationalNumber secondRationalNumber(getValuesFromUser("second"));
	RationalNumber result(0, 0);

	while (choice != 5)
	{
		cout << "What would you wanna do with these two rational number?" << '\n'
			<< "Please select by the appropriate number." << "\n"
			<< "1. Additional" << '\n' << "2. Substraction" << "\n"
			<< "3. Multiplication" << "\n" << "4.Division" << '\n'
			<< "5. For exit." << '\n';
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout<<(firstRationalNumber.Add(secondRationalNumber)).toString()<<'\n';
			break;
		case 2:
			
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			cout << "Your choice is not correct, try again." << '\n';
		}
	}
	//print result
	//cout << result.getNumerator() << '\n' << "----" << '\n' << result.getDenumerator();;
}