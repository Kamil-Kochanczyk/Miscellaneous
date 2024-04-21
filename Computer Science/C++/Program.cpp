#include "Person.h"
#include "Point.h"
#include "Vector.h"
#include <iostream>

using namespace std;

class Auxiliary
{
public:
	int x;

public:
	Auxiliary(int x)
	{
		this->x = x;
	}

	void Show()
	{
		int x = 10;
		cout << "Local x = " << x << endl;
		cout << "Global x = " << this->x << endl;
	}

	Auxiliary operator+(Auxiliary& rhs)
	{
		return Auxiliary(this->x + rhs.x);
	}
};

char c = 'g';

int main()
{
	char c = 'l';
	cout << "Local: " << c << endl;
	cout << "Global: " << ::c << endl << endl;

	Person unknown;
	unknown.Introduce();
	unknown.Scream();
	cout << endl;

	Person programmer("Kamil", 19);
	programmer.Introduce();
	programmer.Scream();
	cout << endl;

	const Person adeline("Adeline", 30);
	adeline.Introduce();
	adeline.Scream();
	cout << endl;

	const float phi = 1.618f;
	cout << phi << endl << endl;

	Helper helper1, helper2(42, 69);
	helper1.Show();
	helper2.Show();
	cout << endl;

	Vector iHat(Point(0, 0), Point(1, 0));
	iHat.OutputHeadAndTail();
	OutputComponents(iHat);
	cout << endl;

	Vector jHat(Point(0, 0), Point(0, 1));
	jHat.OutputHeadAndTail();
	OutputComponents(jHat);
	cout << endl;

	Vector v(Point(10, 8), Point(42, 69));
	v.OutputHeadAndTail();
	OutputComponents(v);
	cout << endl;

	Auxiliary aux(8);
	aux.Show();
	cout << endl;

	Auxiliary lhs(42);
	Auxiliary rhs(69);
	Auxiliary result = lhs + rhs;
	cout << result.x << endl << endl;

	Person* p1 = new Person;
	Person* p2 = new Person();
	p1->Introduce();
	p2->Introduce();
	delete p1;
	delete p2;
	cout << "Program is still running here" << endl;

	return 0;
}