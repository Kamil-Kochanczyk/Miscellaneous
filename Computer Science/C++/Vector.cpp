#include "Vector.h"
#include "Point.h"
#include <iostream>

Vector::Vector(Point head, Point tail) : head(head), tail(tail)
{

}

void Vector::OutputHeadAndTail()
{
	std::cout << "Head: ";
	head.OutputCoordinates();

	std::cout << "Tail: ";
	tail.OutputCoordinates();
}

void OutputComponents(Vector& vector)
{
	int headX = GetX(vector.head), headY = GetY(vector.head);
	int tailX = GetX(vector.tail), tailY = GetY(vector.tail);

	int iVectors = tailX - headX;
	int jVectors = tailY - headY;

	std::cout << "[" << iVectors << "; " << jVectors << "]" << std::endl;
}