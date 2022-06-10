#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include "Vector2D.h"

class Rectangle : public Shape {
	double width;
	double height;
public:
	Rectangle(double width, double height, Vector2D center) : Shape(center), width(width), height(height) {
		this->area = width * height;
	}
};

#endif // !RECTANGLE_H