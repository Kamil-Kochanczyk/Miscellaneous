#define MAX_LENGTH 100

#include <stdio.h>

void introduce();

int find_index(char[], char);

float triple(float number);

void compare_global_local(int local);

void count_calls();

int gcf(int x, int y);

void swap(int* x, int* y);

void triple_array(int array[]);

int global = 10;

int main()
{
	introduce();
	printf("\n");

	char text[MAX_LENGTH] = "I like C# more than C.";
	printf("Text: \"%s\" \n", text);
	printf("Position of \'#\' in text: %d \n", find_index(text, '#'));
	printf("\n");

	float phi = 1.618f;
	printf("Before: phi = %4.2f \n", phi);
	printf("Inside: phi = %4.2f \n", triple(phi));
	printf("After: phi = %4.2f \n", phi);
	printf("\n");

	int local = 8;
	compare_global_local(local);
	printf("\n");

	for (int i = 1; i <= 10; i++)
	{
		count_calls();
	}
	printf("\n");

	int x, y;
	printf("Enter two integer numbers x and y (y cannot be zero):\n");
	printf("x = ");
	scanf_s("%d", &x);
	printf("y = ");
	scanf_s("%d", &y);
	printf("gcf(x, y) = gcf(%d, %d) = %d \n", x, y, gcf(x, y));
	printf("\n");

	int favourite_numbers[3];
	favourite_numbers[0] = 520;
	favourite_numbers[1] = 69;
	favourite_numbers[2] = 42;
	printf("My favourite numbers:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%d \n", favourite_numbers[i]);
	}
	printf("\n");

	char favourite_letters[3] = { 'K', 'C', 'D' };
	printf("My favourite letters:\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%c \n", favourite_letters[i]);
	}
	printf("\n");

	printf("sizeof(favourite_numbers): %d \n", sizeof(favourite_numbers));
	printf("sizeof(favourite_letters): %d \n", sizeof(favourite_letters));
	printf("\n");

	float random[3][2][1] =
	{
		{ { 3.141f }, { -3.141f} },
		{ { 2.718f }, { -2.718f } },
		{ { 1.618f }, { -1.618f } }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 1; k++)
			{
				printf("%-6.3f \n", random[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

	int var = 5;
	printf("Address of var is a hecadecimal number: %p \n", &var);
	printf("\n");

	int* pointer = NULL;
	pointer = &var;
	printf("Address of var: %p \n", &var);
	printf("Address of var: %p \n", pointer);
	printf("Value of var: %d \n", var);
	printf("Value of var: %d \n", *pointer);	// Dereference
	printf("\n");

	printf("Changing the value of var...\n");
	*pointer -= 2;
	printf("Address of var: %p \n", &var);
	printf("Address of var: %p \n", pointer);
	printf("Value of var: %d \n", var);
	printf("Value of var: %d \n", *pointer);	// Dereference
	printf("\n");

	int digits[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* digit_pointer = digits;	// digits = &digits[0]
	printf("Digits:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", *(digit_pointer + i));
	}
	printf("\n");

	digit_pointer = &digits[9];
	printf("Digits reversed:\n");
	while (digit_pointer != digits)
	{
		printf("%d \n", *digit_pointer);
		digit_pointer--;
	}
	printf("%d \n", *digit_pointer);	// Last element will not be displayed in the loop
	printf("\n");

	int p = 10, q = 8;
	printf("Before swapping:\n");
	printf("p = %d \n", p);
	printf("q = %d \n", q);
	swap(&p, &q);
	printf("After swapping:\n");
	printf("p = %d \n", p);
	printf("q = %d \n", q);
	printf("\n");

	int negative_digits[10] = { 0, -1, -2, -3, -4, -5, -6, -7, -8, -9 };
	printf("Before tripling:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", negative_digits[i]);
	}
	triple_array(negative_digits);
	printf("After tripling:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", negative_digits[i]);
	}

	return 0;
}

void introduce()
{
	printf("Hello, my name is Kamil\n");
}

int find_index(char text[], char character)
{
	int index = -1;

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (text[i] == character)
		{
			index = i;
			break;
		}
	}

	return index;
}

float triple(float number)
{
	return number * 3;
}

void compare_global_local(int local)
{
	printf("global = %d \n", global);
	printf("local = %d \n", local);
}

void count_calls()
{
	static int calls = 1;
	printf("Function called %d time(s)\n", calls);
	calls++;
}

int gcf(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		return gcf(y, x % y);
	}
}

void swap(int* x, int* y)
{
	*x += *y;
	*y = *x - *y;
	*x -= *y;
}

void triple_array(int array[])
{
	for (int i = 0; i < 10; i++)
	{
		array[i] *= 3;
	}
}