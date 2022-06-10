#ifndef SHAPE_H
#define SHAPE_H

#include <sstream>


#include "Vector2D.h"


class Shape
{
private:

protected:
	double area;
	Vector2D m_center;
public:

	Shape() : m_center{ 0,0 }, area{ 0 }{}

	Shape(Vector2D center) : m_center{ center }{}

	std::string getCenter() const {return std::string(m_center);} // overloaded operator in class Vector2D
	double getArea() const {return area;}

};


#endif // !SHAPE_H
