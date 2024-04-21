#include <iostream>

using namespace std;

int main()
{
	cout << "Hello" << " " << "world" << "!" << "\n" << endl;

	// Use endl only if you really want to output data immediately

	/*
	endl - flushes the buffer
	\n - does not flush the buffer
	*/

	bool b;
	char c;
	string s;
	int i;
	float f;

	b = true;
	c = 'K';
	s = "Kamil";
	i = 10;
	f = 42.69;

	cout << b << c << s << i << f << endl << endl;

	string language;
	cout << "What is your favourite programming language?\n";
	cin >> language;
	cout << "Your favourite programming language is " << language << endl << endl;

	auto var = -520;
	cout << var << endl << endl;

	var = 0;
	var += 3;
	var -= 5;
	var *= 8;
	var /= 10;
	var %= 23;
	cout << var << endl;
	cout << --var << endl;
	cout << var++ << endl;
	cout << var << "\n";

	return 0;
}