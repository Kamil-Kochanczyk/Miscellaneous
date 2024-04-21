#pragma once

class Point
{
private:
	int x;
	int y;

public:
	Point(int x, int y);
	void OutputCoordinates();
	friend int GetX(Point& point);
	friend int GetY(Point& point);
};

int GetX(Point& point);
int GetY(Point& point);