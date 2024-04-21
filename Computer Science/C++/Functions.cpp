#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

float CalculateSomething(float x, float y);

void PrintNumbers(int x, int y = 10);

void PrintNumbers(float x, float y);

unsigned int Factorial(unsigned int n);

void PassByReference(int& x);

int main()
{
	srand(time(0));

	cout << CalculateSomething(18, 3) << endl << endl;

	cout << "Pseudo-random numbers:" << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << (rand() % 3) + 19 << "\n";
	}
	cout << endl;

	PrintNumbers(8);
	PrintNumbers(42, 69);
	cout << endl;

	PrintNumbers(0.1f, 3.5);
	cout << endl;

	cout << "10! = " << Factorial(10) << endl << endl;

	int x = -10;
	cout << x << endl;
	PassByReference(x);
	cout << x << endl;

	return 0;
}

float CalculateSomething(float x, float y)
{
	return sqrt(x * y);
}

void PrintNumbers(int x, int y)
{
	cout << x << endl;
	cout << y << endl;
}

void PrintNumbers(float x, float y)
{
	cout << x << endl;
	cout << y << endl;
}

unsigned int Factorial(unsigned int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

void PassByReference(int& x)
{
	x *= 2;
}