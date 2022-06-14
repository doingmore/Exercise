#include <iostream>

//Write a class named Point2d.Point2d should contain two member variables of type double : m_x, and m_y,
//  both defaulted to 0.0.Provide a constructor and a print function.
//The following program should run :


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
};



// skeleton
int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    first.print();
    second.print();

    return 0;
}
// skeleton 