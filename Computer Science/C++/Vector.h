#pragma once

#include "Point.h"

class Vector
{
private:
	Point head;
	Point tail;

public:
	Vector(Point head, Point tail);
	void OutputHeadAndTail();
	friend void OutputComponents(Vector& vector);
};

void OutputComponents(Vector& vector);