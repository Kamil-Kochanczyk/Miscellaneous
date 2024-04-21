#include <iostream>

using namespace std;

int main()
{
	cout << "bool: " << sizeof(bool) << " byte(s)" << endl;
	cout << "int: " << sizeof(int) << " byte(s)" << endl;
	cout << "short int: " << sizeof(short int) << " byte(s)" << endl;
	cout << "long int: " << sizeof(long int) << " byte(s)" << endl;
	cout << "float: " << sizeof(float) << " byte(s)" << endl;
	cout << "double: " << sizeof(double) << " byte(s)" << endl;
	cout << "long double: " << sizeof(long double) << " byte(s)" << endl;
	cout << "char: " << sizeof(char) << " byte(s)" << endl;
	cout << "string: " << sizeof(string) << " byte(s)" << endl;
	cout << endl;

	int myFavNum[10] = { 10, 8, 5, 3, 1, 42, 69, 520 };
	for (int i = 0; i < 10; i++)
	{
		cout << "myFavNum[" << i << "] = " << myFavNum[i] << endl;
	}
	cout << endl;

	char myFavLet[] = { 'C', 'D', 'V' };
	cout << myFavLet[0] << "\n" << myFavLet[1] << "\n" << myFavLet[2] << "\n";
	myFavLet[2] = 'K';
	cout << myFavLet[2] << endl << endl;

	char tableOfWords[3][5][8];
	tableOfWords[2][4][0] = 'K';
	tableOfWords[2][4][1] = 'A';
	tableOfWords[2][4][2] = 'M';
	tableOfWords[2][4][3] = 'I';
	tableOfWords[2][4][4] = 'L';
	tableOfWords[2][4][5] = '\0';
	cout << tableOfWords[2][4] << endl << endl;

	int variable = 18;
	int* pointer = &variable;
	cout << &variable << "\n" << pointer << "\n" << variable << "\n" << *pointer << "\n" << &pointer << "\n\n";

	/*
	Stack - static memory
	Heap - dynamic memory
	*/

	int* onHeap = new int;	// new returns the address of space reserved for the variable on heap
	*onHeap = 3;	// onHeap is stored on stack, 3 is stored on heap
	cout << onHeap << "\n";
	cout << *onHeap << endl << endl;
	delete onHeap;	// delete frees up the memory, onHeap is now a dangling pointer

	int* notGarbage = nullptr;
	int elements;
	cout << "How many elements in the array?" << endl;
	cin >> elements;
	cout << "Array:" << endl;
	notGarbage = new int[elements];
	for (int i = 0; i < elements; i++)
	{
		notGarbage[i] = i;
		cout << notGarbage[i] << endl;
	}
	cout << endl;
	delete[] notGarbage;

	/*
	new - delete (ok)
	new - delete[] (undefined behaviour)
	new[] - delete[] (ok)
	new[] - delete (undefined behaviour)
	*/

	float fArray[10];
	cout << sizeof(fArray) << "\n" << sizeof(fArray) / sizeof(fArray[0]) << "\n";

	return 0;
}