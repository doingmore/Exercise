#include <iostream>

class Rectangle
{
private:
    int m_hight;
    int m_width;
public:
    Rectangle(const int& hight, const int& width) : m_hight{ hight }, m_width{width}
    {}

    int getArea() const { return (m_width*m_hight);}
    int getPerimeter() const { return ( (2 * m_width) + (2 * m_hight) ); }

};


int main()
{
    int hight{ 0 };
    int width{ 0 };

    std::cin >> hight;
    std::cin >> width;

    Rectangle rec{ hight,width };

    std::cout << rec.getArea() << '\n' << rec.getPerimeter() << '\n';

    return 0;
}
