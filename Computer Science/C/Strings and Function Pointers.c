#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void clear_buffer();

void say_hello();

double arithmetic_mean(int x, int y);

double geometric_mean(int x, int y);

double weighted_mean(int x, int y);

double test(double (*)(int, int), int, int);

void* swap(void*, void*);

void* square(const void*);

void* cube(const void*);

int main()
{
	printf("Every string is a char array\n");
	printf("Every string should end with a null character \'\\0\' \n");
	printf("\n");

	char first_name[6] = "Kamil";
	char second_name[] = "Micha³";

	printf("First name: %s \n", first_name);
	printf("Second name: %s \n", second_name);
	printf("\n");

	printf("First name length: %d \n", strlen(first_name));
	printf("Second name length: %d \n", strlen(second_name));
	printf("\n");

	printf("First name size: %d \n", sizeof(first_name));
	printf("Second name size: %d \n", sizeof(second_name));
	printf("\n");

	char third_name[] = { 'J', 'a', 'n', '\0' };
	printf("Third name: %s \n", third_name);
	printf("\n");

	char* surname = "Kochañczyk";
	printf("Surname: %s \n", surname);
	printf("\n");

	char letter;
	printf("Enter a letter: ");
	letter = getchar();
	clear_buffer();
	putchar(letter);
	printf("\n\n");

	char user_name[MAX];
	printf("Enter your name: ");
	fgets(user_name, MAX, stdin);
	fputs(user_name, stdout);
	printf("\n");

	char user_surname[MAX];
	printf("Enter your surname: ");
	fgets(user_surname, MAX, stdin);
	fputs(user_surname, stdout);
	printf("\n");

	printf("sprintf()\n");
	char building[MAX];
	int floors[3] = { 1, 2, 3 };
	sprintf_s(building, MAX, "Floor %d, Floor %d, Floor %d", floors[0], floors[1], floors[2]);
	printf("%s \n", building);
	printf("\n");

	printf("sscanf()\n");
	char date[MAX] = "04 05 2002";
	int day, month, year;
	sscanf_s(date, "%d %d %d", &day, &month, &year);
	printf("Day: %d \n", day);
	printf("Month: %d \n", month);
	printf("Year: %d \n", year);
	printf("\n");

	char hidden_number[MAX] = "123def";
	char* pointer;
	double number = strtod(hidden_number, &pointer);
	printf("Hidden number: %s \n", hidden_number);
	printf("Number: %lf \n", number);
	printf("Pointer: %p \n", pointer);
	printf("Value of pointer: %c \n", *pointer);
	printf("\n");

	char* array_of_strings[] = { "C#", "C++", "C", "HTML", "CSS", "JavaScript", "Python" };
	char** string_pointer = array_of_strings;
	int i = 0;
	while (i < 7)
	{
		printf("%s \n", *(string_pointer + i));
		i++;
	}
	printf("\n");
	
	void (*say_hello_pointer)();
	say_hello_pointer = say_hello;
	for (int i = 1; i <= 5; i++)
	{
		say_hello_pointer();
	}
	printf("\n");

	double (*mean_pointer[3])(int, int) = { arithmetic_mean, geometric_mean, weighted_mean };
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			printf("Arithmetic mean of 8 and 10: ");
			break;
		case 1:
			printf("Geometric mean of 8 and 10: ");
			break;
		case 2:
			printf("Weighted mean of 8 and 10: ");
			break;
		}

		printf("%.2lf \n", mean_pointer[i](8, 10));
	}
	printf("\n");

	printf("Arithmetic mean of 42 and 69: %.2lf \n", test(mean_pointer[0], 42, 69));
	printf("\n");

	void* generic_pointer = NULL;
	int random_number = 10;
	char random_letter = 'K';
	char random_word[3] = "C#";

	generic_pointer = &random_number;
	printf("Generic pointer: %p \n", generic_pointer);
	printf("Generic pointer points to: %d \n", *((int*)generic_pointer));

	generic_pointer = &random_letter;
	printf("Generic pointer: %p \n", generic_pointer);
	printf("Generic pointer points to: %c \n", *((char*)generic_pointer));

	generic_pointer = random_word;
	printf("Generic pointer: %p \n", generic_pointer);
	printf("Generic pointer points to: ");
	for (int i = 0; i < strlen(random_word); i++)
	{
		printf("%c", *((char*)generic_pointer + i));
	}
	printf("\n\n");

	int a = 10, b = 8;
	printf("a = %d, b = %d \n", a, b);
	swap(&a, &b);
	printf("a = %d, b = %d \n", a, b);
	printf("\n");

	float c = 69.42f, d = 42.69f;
	printf("c = %.2f, d = %.2f \n", c, d);
	swap(&c, &d);
	printf("c = %.2f, d = %.2f \n", c, d);
	printf("\n");

	int e = 5, e_squared = square(&e);
	printf("e = %d, e_squared = %d \n", e, e_squared);
	printf("\n");

	int f = 3;
	int* f_cubed_pointer = cube(&f);
	int f_cubed = *f_cubed_pointer;
	printf("f = %d, f_cubed_pointer = %p, *f_cubed_pointer = %d, f_cubed = %d \n", f, f_cubed_pointer, *f_cubed_pointer, f_cubed);
	printf("\n");

	return 0;
}

void clear_buffer()
{
	while ((getchar()) != '\n');
}

void say_hello()
{
	printf("Hello world!\n");
}

double arithmetic_mean(int x, int y)
{
	return (x + y) / 2.0;
}

double geometric_mean(int x, int y)
{
	return sqrt(x * y);
}

double weighted_mean(int x, int y)
{
	return (double)(x * x + y * y) / (x + y);
}

double test(double (*function_pointer)(int, int), int x, int y)
{
	return function_pointer(x, y);
}

void* swap(void* x_pointer, void* y_pointer)
{
	(*(int*)x_pointer) += (*(int*)y_pointer);
	(*(int*)y_pointer) = (*(int*)x_pointer) - (*(int*)y_pointer);
	(*(int*)x_pointer) -= (*(int*)y_pointer);
}

void* square(const void* x_pointer)
{
	return (*(int*)x_pointer) * (*(int*)x_pointer);
}

void* cube(const void* x_pointer)
{
	int result = (*(int*)x_pointer) * (*(int*)x_pointer) * (*(int*)x_pointer);
	return &result;
}