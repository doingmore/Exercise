#ifndef Shape_H
#define Shape_H

#include <sstream>
#include <string>

#include "Vector2D.h"

class Shape
{
public:
	double area;
	Vector2D m_center;

	Shape() : area(0), m_center(0,0)
	{

	}

	Shape(Vector2D center) : m_center(center)
	{
	}


	std::string getCenter()
	{
		return m_center.operator std::string();
	}

	std::string getArea()
	{
		std::string answer;
		answer = std::to_string(this->area);
		return answer;
	}


};



#endif // !Shape_H
