#include "Shape.h"

std::string Shape::getCenter() const
{
	std::string answer = std::string(m_center);
	return answer;
}

std::string Shape::getArea() const
{
	std::stringstream answer;
	answer << area;
	return answer.str();
}
