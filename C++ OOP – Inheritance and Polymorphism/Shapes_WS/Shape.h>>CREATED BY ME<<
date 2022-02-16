#ifndef Shape_H
#define Shape_H


#include <iostream>
#include <sstream>

#include "Vector2D.h"

class Shape
{
protected:
	double area;
	Vector2D m_center;
public:
	Shape() : area(0), m_center(0,0) {}

	Shape(Vector2D center) : m_center(center)
	{
	}

	std::string getCenter() const;
	std::string getArea() const;
};


#endif // !Shape_H
