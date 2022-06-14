#include <iostream>
#include <cmath>

// c) Change function distanceTo from a member function
// to a non - member friend function that takes two Points
// as parameters.Also rename it “distanceFrom”.
// The following program should run :


class Point2d
{
private:
    double m_x;
    double m_y;
public:
    Point2d() : m_x{ 0 }, m_y{ 0 }
    {}
    Point2d(const double& x, const double& y) : m_x{ x }, m_y{ y }
    {}

    void print() const
    {
        std::cout << "Point2d(" << this->m_x << " : " << this->m_y << ")" << '\n';
    }

    friend double distanceFrom(const Point2d& left, const Point2d& right);

};

double distanceFrom(const Point2d& left, const Point2d& right)
{
    // for convenience and readable
    double x1 = left.m_x;
    double y1 = left.m_y;
    double x2 = right.m_x;
    double y2 = right.m_y;

    double answer{ std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) };

    return answer;
}

// skeleton
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}
// skeleton 