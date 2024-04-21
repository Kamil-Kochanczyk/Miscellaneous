#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <typename T>
void Swap(T* x, T* y)
{
	T auxiliary = *x;
	*x = *y;
	*y = auxiliary;
}

template <typename T, typename U>
auto Bigger(T tArg, U uArg)
{
	return (tArg > uArg) ? tArg : uArg;
}

template <typename T, typename U>
class Generic
{
private:
	T t;
	U u;

public:
	Generic(T t, U u) : t(t), u(u)
	{

	}

	void Display()
	{
		cout << "t = " << t << endl;
		cout << "u = " << u << endl;
	}

	void Change(T t, U u)
	{
		this->t = t;
		this->u = u;
	}

	bool Compare();
};

template <typename V, typename W>
bool Generic<V, W>::Compare()
{
	return t == u;
}

template<>
class Generic<bool, bool>
{
private:
	bool t;
	bool f;

public:
	Generic(bool t, bool f) : t(t), f(f)
	{
		cout << "t = " << ((this->t == true) ? "True" : "False") << endl;
		cout << "f = " << ((this->f == false) ? "False" : "True") << endl;
	}
};

template <typename U>
U Sum(U lhs, U rhs)
{
	cout << "Generic\n";
	return lhs + rhs;
}

template<>
string Sum<string>(string lhs, string rhs)
{
	cout << "Specialized\n";
	return lhs.append(rhs);
}

int main()
{
	int integer1 = 42, integer2 = 69;
	int* intPointer1 = &integer1;
	int* intPointer2 = &integer2;

	cout << *intPointer1 << endl << *intPointer2 << endl << endl;
	Swap(intPointer1, intPointer2);
	cout << *intPointer1 << endl << *intPointer2 << endl << endl;

	string string1 = "C++", string2 = "C#";
	string* stringPointer1 = &string1;
	string* stringPointer2 = &string2;

	cout << *stringPointer1 << endl << *stringPointer2 << endl << endl;
	Swap(stringPointer1, stringPointer2);
	cout << *stringPointer1 << endl << *stringPointer2 << endl << endl;

	auto bigger = Bigger(9.99, 9);
	cout << bigger << endl;
	bigger = Bigger(9, 9.99);
	cout << bigger << endl << endl;

	Generic<int, double> generic(-520, 42.69);
	generic.Display();
	cout << endl;

	generic.Change(520, 42.69);
	generic.Display();
	cout << endl;

	bool areEqual = generic.Compare();
	cout << areEqual << endl << endl;

	int intSum = Sum<int>(10, 8);
	char charSum = Sum<char>('a', 'z');
	string stringSum = Sum<string>("C", "++");

	cout << intSum << endl;
	cout << charSum << endl;
	cout << stringSum << endl;
	cout << endl;

	Generic<bool, bool> obj(false, true);
	cout << endl;

	try
	{
		int userInput;
		cout << "Please enter an integer between -10 and 10: ";
		cin >> userInput;

		if (userInput < -10)
		{
			throw (-1);
		}

		if (userInput > 10)
		{
			throw 1;
		}

		if (userInput == 0)
		{
			throw exception("Wrong input");
		}

		cout << "You entered: " << userInput << endl << endl;
	}
	catch (...)
	{
		cout << "Something went wrong" << endl << endl;
	}
	//catch (int e)
	//{
	//	cout << "Incorrect integer value" << endl;
	//	cout << "Exception code: " << e << endl << endl;
	//}
	//catch (const exception& e)
	//{
	//	cout << e.what() << endl << endl;
	//}

	ofstream outputStream;
	outputStream.open("C:\\Users\\kocha\\Desktop\\Test Folder\\C++ Test File.txt");

	if (outputStream.is_open())
	{
		for (int i = 0; i <= 99; i++)
		{
			outputStream << "Number " << i << endl;
		}

		outputStream.close();
	}
	else
	{
		cout << "Cannot output to the file" << endl;
	}

	ifstream inputStream;
	inputStream.open("C:\\Users\\kocha\\Desktop\\Test Folder\\C++ Test File.txt");

	if (inputStream.is_open())
	{
		string text;
		inputStream >> text;
		cout << text << endl << endl;

		string line;
		while (getline(inputStream, line))
		{
			cout << line << endl;
		}

		inputStream.close();
	}
	else
	{
		cout << "Cannot input from the file" << endl;
	}

	return 0;
}