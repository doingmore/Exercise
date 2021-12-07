#include <iostream>

using namespace std;

/*
Write a program, make a Class Rectangle. For given numbers for the sides, the program should calculate the area and the perimeter of the Rectangle.
*/

class Rectangle
{
private:
	int m_height;
	int m_width;
public:
	Rectangle(int height, int width)
	{
		m_height = height;
		m_width = width;
	}

	int getArea()
	{
		int area = m_height * m_width;
		return area;
	}

	int getPerimeter()
	{
		int perimeter = (2 * (m_height)) + (2 * (m_width));
		return perimeter;
	}
};

void Problem5()
{
	int height{ 0 };
	int width{ 0 };
	cout << "Enter height on rectangle: ";
	cin >> height;
	cout << "Enter width on rectangle: ";
	cin >> width;

	Rectangle myRectangle(height, width);

	cout << "Area is: " << myRectangle.getArea() << '\n' << "Perimeter is: " << myRectangle.getPerimeter();
}