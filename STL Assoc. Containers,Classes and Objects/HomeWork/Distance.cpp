#include <iostream>


class point
{
private:
	int m_x;
	int m_y;
public:
	point(int x, int y) : m_x{ x }, m_y{ y }
	{}

	int getX() const { return m_x; }
	int getY() const { return m_y; }

	double getDistance(point& toPoint)
	{
		double answer{ 0 };
		double sideOnX{ 0 };
		double sideOnY{ 0 };
		sideOnX = absD(this->m_x, toPoint.getX()); // get absolute distance
		sideOnY = absD(this->m_y, toPoint.getY()); // get absolute distance

		answer = (sideOnX * sideOnX) + (sideOnY * sideOnY);
		answer = sqrt(answer);
		return answer;
	}

	double absD(int a, int b)
	{
		if (a>b)
		{
			return a - b;
		}
		else
		{
			return b - a;
		}
	}

};


int main_12()
{
	int x{ 0 }, y{ 0 };
	std::cin >> x >> y;
	point first{ x,y };
	std::cin >> x >> y;
	point second{ x,y };

	std::cout << first.getDistance(second) << '\n';

	return 0;
}