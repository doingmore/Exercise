#include <iostream>
#include <cmath>

// b) Now add a member function named distanceTo that takes another Point2d as a parameter,
// and calculates the distance between them.Given two points(x1, y1) and (x2, y2),
// the distance between them can be calculated
// as std::sqrt((x1 - x2)* (x1 - x2) + (y1 - y2) * (y1 - y2)).The std::sqrt function lives in header cmath.
// The following program should run :


class Point2d
{
private:
    double m_x;
    double m_y;
public:
    Point2d() : m_x{ 0 }, m_y{0}
    {}
    Point2d(const double& x,const double& y) : m_x{x}, m_y{y}
    {}

    void print() const 
    {
        std::cout <<"Point2d("<< this->m_x << " : " << this->m_y <<")"<< '\n';
    }

    double distanceTo(const Point2d& object_parameter) const
    {
        // for convenience and readable
        double x1 = this->m_x;
        double y1 = this->m_y;
        double x2 = object_parameter.m_x;
        double y2 = object_parameter.m_y;

        double answer{ std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) };

        return answer;
    }

};



// skeleton
int main()
{
    Point2d first{};
    Point2d second{ 3,4 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    return 0;
}
// skeleton 