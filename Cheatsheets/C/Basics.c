#include <stdio.h>

#define NOSEMICOLONHERE 520

int main()
{
	printf("Hello world!\n\n");

	printf("Sizes of all basic data types (in bytes):\n");
	printf("- int, %d \n", sizeof(int));
	printf("- float, %d \n", sizeof(float));
	printf("- double, %d \n", sizeof(double));
	printf("- char, %d \n", sizeof(char));
	printf("\n");

	int snake_case;
	snake_case = 10;
	float pi = 3.14, e = 2.72;
	double pi_precise = 3.141, e_precise = 2.718;
	char programming_language = 'C';

	printf("snake_case = %d \n", snake_case);
	printf("pi + pi_precise = %f, e + e_precise = %f \n", pi + pi_precise, e + e_precise);
	printf("I am learning %c language now.\n", programming_language);
	printf("I am learning %d language now.\n", programming_language);
	printf("\n");

	const int love_number = 520;
	printf("love_number = %d \n", love_number);
	printf("NOSEMICOLONHERE = %d \n", NOSEMICOLONHERE);
	printf("Both of the above values are constants.\n");
	printf("The difference between const and #define is that the former uses memory for storage and the latter does not.\n");
	printf("\n");

	char user_favourite_letter;
	printf("What is your favourite letter?\n");
	user_favourite_letter = getchar();
	printf("Your favourite letter is ");
	putchar(user_favourite_letter);
	printf(".\n\n");

	char user_name[100];
	printf("What is your name?\n");
	fgets(user_name, 100, stdin);	/* Getting rid of the trailing new line character by reading it */
	fgets(user_name, 100, stdin);
	fputs(user_name, stdout);
	printf("\n");

	printf("=%-10.5s= \n", "KamilKamilKamil");
	printf("=%10.5s= \n", "KamilKamilKamil");
	//printf("%*s \n", "KamilKamilKamil");
	printf("%% \n");
	printf("\n");

	int int1 = 69, int2 = 42;
	float float1 = 69, float2 = 42;
	printf("%d \n", int1 + int2);
	printf("%d \n", int1 - int2);
	printf("%d \n", int1 * int2);
	printf("%d \n", int1 / int2);
	printf("%f \n", float1 / float2);
	printf("%d \n", int1 % int2);
	printf("\n");

	printf("%f \n", (float)int1 / int2);
	printf("%f \n", int1 / (float)int2);
	printf("%f \n", (float)(int1 / int2));
	printf("\n");

	int x = 10;
	printf("%d \n", x += 1);
	printf("%d \n", x -= 2);
	printf("%d \n", x *= 3);
	printf("%d \n", x /= 9);
	printf("%d \n", x %= 2);
	printf("\n");

	float y = 6.9, z = 4.2;
	printf("%f \n", y++);
	printf("%f \n", ++z);
	printf("%f \n", y--);
	printf("%f \n", --z);

	return 0;
}