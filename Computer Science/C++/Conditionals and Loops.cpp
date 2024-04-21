#include <iostream>

using namespace std;

int main()
{
	int number;
	cout << "What is your favourite number?" << endl;
	cin >> number;

	if (number == 10)
	{
		cout << "This is my favourite number too!" << endl;
	}
	else if (number == 42)
	{
		cout << "This is Answer to the Ultimate Question of Life, the Universe, and Everything!" << endl;
	}
	else
	{
		cout << "Nice!" << endl;
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4)
		{
			break;
		}

		cout << i << endl;
	}
	cout << endl;

	int counter = -1;
	while (++counter < 10)
	{
		if (counter == 4)
		{
			continue;
		}

		cout << counter << endl;
	}
	cout << endl;

	int integer;
	int sum = 0;
	cout << "Keep entering integers to get sum greater than 10 or smaller than -10!" << endl;

	do
	{
		cin >> integer;
		sum += integer;
	} while (sum <= 10 && sum >= -10);

	cout << "sum = " << sum << endl << endl;

	char letter;
	cout << "What is your favourite letter?" << endl;
	cin >> letter;

	switch (letter)
	{
		case 'C':
		case 'c':
			cout << "This is my favourite letter too!";
			break;
		case 'K':
		case 'k':
			cout << "I like this letter too!";
			break;
		default:
			cout << "Nice!";
			break;
	}
	cout << endl << endl;

	float realNumber;
	string message;

	cout << "Enter some real number" << endl;
	cin >> realNumber;

	message = (realNumber == 0) ? "zero" : ((realNumber > 0) ? "positive" : "negative");

	cout << "Your number is " << message << endl;

	return 0;
}