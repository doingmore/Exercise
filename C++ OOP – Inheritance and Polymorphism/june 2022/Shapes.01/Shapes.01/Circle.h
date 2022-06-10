#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vector2D.h"
#include "Shape.h"
#include "Constants.h"

class Circle : public Shape {
	double radius;
public:
	Circle(double radius, Vector2D center) : Shape(center), radius(radius) {
		this->area = PI * radius * radius;
	}
};

#endif // !CIRCLE_H

