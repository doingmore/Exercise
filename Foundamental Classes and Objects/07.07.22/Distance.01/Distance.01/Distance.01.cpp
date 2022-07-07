#include <iostream>
#include <cmath>

class Point2d
{
private:
    int m_x;
    int m_y;
public:
    Point2d(const int& x, const int& y) : m_x{ x }, m_y{y}
    {}

    int getX()const { return m_x; };
    int getY()const { return m_y; };
};

int main()
{
    int x{ 0 }, y{ 0 };
    std::cin >> x >> y;
    Point2d pFirst{ x,y };
    std::cin >> x >> y;
    Point2d pSecond{ x,y };

    std::cout <<
        std::sqrt((pFirst.getX() - pSecond.getX()) * (pFirst.getX() - pSecond.getX())
            + (pFirst.getY() - pSecond.getY()) * (pFirst.getY() - pSecond.getY())) << '\n';


    return 0;
}
