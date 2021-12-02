#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
This task is not one of instruction. Created for exercise.
*/

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

	RationalNumber Add(RationalNumber& secondRN)
	{
		int num;
		int denum;
		num = (((m_numerator) * (secondRN.getDenumerator())) + ((m_denumerator) * (secondRN.getNumerator())));
		denum = ((m_denumerator) * (secondRN.getDenumerator()));
		return RationalNumber(num, denum);
	}

	RationalNumber substraction(RationalNumber& secondRN)
	{
		int num;
		int denum;
		num = (((m_numerator) * (secondRN.getDenumerator())) - ((m_denumerator) * (secondRN.getNumerator())));
		denum = ((m_denumerator) * (secondRN.getDenumerator()));
		return RationalNumber(num, denum);
	}

	RationalNumber multiplication(RationalNumber& secondRN)
	{
		int num;
		int denum;
		num = ((m_numerator) * (secondRN.getNumerator()));
		denum = ((m_denumerator) * (secondRN.getDenumerator()));
		return RationalNumber(num, denum);
	}

	RationalNumber division(RationalNumber& secondRN)
	{
		int num;
		int denum;
		num = ((m_numerator) * (secondRN.getDenumerator()));
		denum = ((m_denumerator) * (secondRN.getNumerator()));
		return RationalNumber(num, denum);
	}

	string toString()
	{
		ostringstream stream;
		stream << m_numerator << "/" << m_denumerator << '\n';
		return stream.str();
	}
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
	int newNumeratorRN{ 0 };
	int newDenumeratorRN{ 0 };
	RationalNumber firstRationalNumber(getValuesFromUser("first"));
	RationalNumber secondRationalNumber(getValuesFromUser("second"));

	while (choice != 6)
	{
		cout << "What would you wanna do with these two rational number?" << '\n'
			<< "Please select by the appropriate number." << "\n"
			<< "1. Additional" << '\n' << "2. Substraction" << "\n"
			<< "3. Multiplication" << "\n" << "4. Division" << '\n'
			<<"5. For input new rationals numbers."<<'\n'<< "6. For exit." << '\n'
			<<"Your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << (firstRationalNumber.Add(secondRationalNumber)).toString() << '\n';
			break;
		case 2:
			cout << (firstRationalNumber.substraction(secondRationalNumber)).toString() << '\n';
			break;
		case 3:
			cout << (firstRationalNumber.multiplication(secondRationalNumber)).toString() << '\n';
			break;
		case 4:
			cout << (firstRationalNumber.division(secondRationalNumber)).toString() << '\n';
			break;
		case 5:
		//example for getter and setter 
			cout << "Enter new numerator on first rational number: ";
			cin >> newNumeratorRN;
			firstRationalNumber.setNumerator(newNumeratorRN);
			cout << "Enter new denumerator on first rational number: ";
			cin >> newDenumeratorRN;
			firstRationalNumber.setNumerator(newDenumeratorRN);
			//input second rational number
			cout << "Enter new numerator on second rational number: ";
			cin >> newNumeratorRN;
			secondRationalNumber.setNumerator(newNumeratorRN);
			cout << "Enter new denumerator on second rational number: ";
			cin >> newDenumeratorRN;
			secondRationalNumber.setNumerator(newDenumeratorRN);
			break;
		case 6:
			//nothing just exit on next condition
			break;
		default:
			cout << "Your choice is not correct, try again." << '\n';
		}
	}
}