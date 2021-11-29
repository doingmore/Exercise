#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class RationalNumber {
private:
	int nom;
	int denom;

public:
	RationalNumber() :
		nom(0),
		denom(1) {
	}

	RationalNumber(int nom, int denom) :
		nom(nom),
		denom(denom) {
	}

	int getNom(void) { return nom; }
	int getDenom(void) { return denom; }
	void setNom(int nom_) { nom = nom_; }
	void setDenom(int denom_) { denom = denom_ != 0 ? denom_ : 1; }
	void Print() { cout << toString(); }

	// adds this + other, returns the sum 
	RationalNumber Add(RationalNumber& other) {

		int newDenom = denom * other.getDenom();
		int newNom =
			nom * other.getDenom() +
			other.getNom() * denom;

		return RationalNumber(newNom, newDenom);
	}

	// subtracts this - other, returns the subtraction 
	RationalNumber Sub(RationalNumber& other) {
		int newDenom = denom * other.getDenom();
		int newNom =
			nom * other.getDenom() -
			other.getNom() * denom;

		return RationalNumber(newNom, newDenom);
	}

	// multiplicates this * other, returns the multiplication
	RationalNumber Multiply(RationalNumber& other) {
		return RationalNumber(
			nom * other.getNom(),
			denom * other.getDenom()
		);
	}

	// divides this / other, returns the division
	RationalNumber Divide(RationalNumber& other) {
		return RationalNumber(
			nom * other.getDenom(),
			denom * other.getNom()
		);
	}

	// converts the number to string: "nom/denom"
	string toString() {
		ostringstream str;
		str << nom << '/' << denom;
		return str.str();
	}

};

RationalNumber enterRationalNumber(string count) {
	int nom;
	int denom;

	cout << "Enter " << count << " rational number numerator : ";
	cin >> nom;

	cout << "Enter " << count << " rational number denominator : ";
	cin >> denom;

	if (!denom) {
		cout << "The denominator can't be 0, the denominator will be set to 1" << endl;
		denom = 1;
	}

	return RationalNumber(nom, denom);
}

void Problem4(void) {
	/*
	int nom1, denom1, nom2, denom2;

	cout << "Enter first rational number numerator : ";
	cin >> nom1;
	cout << "Enter first rational number denominator : ";
	cin >> denom1;

	cout << "Enter second rational number numerator : ";
	cin >> nom2;
	cout << "Enter second rational number denominator : ";
	cin >> denom2;
	*/

	RationalNumber num1 = enterRationalNumber("first");
	RationalNumber num2 = enterRationalNumber("second");

	cout << "Sum : " << (num1.Add(num2)).toString() << '\n';
	cout << "Difference : " << num1.Sub(num2).toString() << '\n';
	cout << "Multiplication : " << num1.Multiply(num2).toString() << '\n';
	cout << "Division : " << num1.Divide(num2).toString() << '\n';
}