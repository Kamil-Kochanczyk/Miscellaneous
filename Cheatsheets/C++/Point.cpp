#include "Point.h"
#include <iostream>

Point::Point(int x, int y) : x(x), y(y)
{

}

void Point::OutputCoordinates()
{
	std::cout << "(" << x << "; " << y << ")" << std::endl;
}

int GetX(Point& point)
{
	return point.x;
}

int GetY(Point& point)
{
	return point.y;
}