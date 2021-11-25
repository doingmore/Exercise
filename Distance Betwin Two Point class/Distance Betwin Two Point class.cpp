#include <iostream>
#include <cmath>

using namespace std;

/*
Write a program to calculate the (Euclidean) distance between two points p1 {x1, y1} and p2 {x2, y2}.
You should write a class to represent such points and a method in it which calculates
the distance from the point to another point.
*/

class Rectangle
{
private:
	double m_sideC{};
public:
	Rectangle(int localSideA, int localSideB)
		: m_sideC{ sqrt((localSideA * localSideA) + (localSideB * localSideB)) }
	{
	}
	void print()
	{
		cout << "The distance betwin this two point is: " << m_sideC << '\n';
	}
};

int main()
{
	int x1, y1; // First point on x and y
	int x2, y2; // Second point on x and y
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	int sideA = abs(y1 - y2);
	int sideB = abs(x1 - x2);

	Rectangle unknown“riangle{ sideA,sideB };

	unknown“riangle.print(); //sideC

	return 0;
}