#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int user_age;
	printf("How old are you?\n");
	scanf("%d", &user_age);
	printf("You are %d year(s) old.\n", user_age);
	if (user_age == 19)
	{
		printf("So am I!\n");
	}
	printf("\n");

	if (user_age >= 18)
	{
		printf("You are an adult, you can proceed.\n");
	}
	else
	{
		printf("You are not an adult yet, you cannot proceed.\n");
	}
	printf("\n");

	if (user_age)
	{
		printf("Non-zero\n");
	}
	else
	{
		printf("Zero\n");
	}
	printf("\n");

	float favourite_number;
	printf("What is your favourite number?\n");
	scanf("%f", &favourite_number);
	int number_property = (favourite_number > 0) ? 1 : ((favourite_number == 0) ? 0 : -1);
	if (number_property > 0)
	{
		printf("%.2f is a positive number.\n", favourite_number);
	}
	else
	{
		if (number_property == 0)
		{
			printf("%.2f is zero.\n", favourite_number);
		}
		else
		{
			printf("%.2f is a negative number.\n", favourite_number);
		}
	}
	printf("\n");

	char subject[100];
	printf("Choose a subject (math/physics/computer science): ");
	fgets(subject, 100, stdin);
	fgets(subject, 100, stdin);
	if (subject == "math")
	{
		printf("math - matematyka\n");
	}
	else if (subject == "physics")
	{
		printf("physics - fizyka\n");
	}
	else if (subject == "computer science")
	{
		printf("computer science - informatyka\n");
	}
	else
	{
		printf("Wrong input.\n");
	}
	printf("\n");

	int number1, number2;
	char operation;
	printf("Enter two integer numbers.\n");
	scanf("%d %d", &number1, &number2);
	printf("Choose operation (+, -, * or /).\n");
	operation = getchar();
	operation = getchar();
	switch (operation)
	{
	case '+':
		printf("%d + %d = %d\n", number1, number2, number1 + number2);
		break;
	case '-':
		printf("%d - %d = %d\n", number1, number2, number1 - number2);
		break;
	case '*':
	case 'x':
		printf("%d * %d = %d\n", number1, number2, number1 * number2);
		break;
	case '/':
	case ':':
		printf("%d / %d = %.2f\n", number1, number2, (float)number1 / (float)number2);
		break;
	default:
		printf("Wrong operation.\n");
		break;
	}
	printf("\n");

	int oct = 052;
	int hex = 0x45;

	if (oct != 69 && hex != 42)
	{
		printf("Correct!\n");
	}
	if (oct == 42 || hex == 69)
	{
		printf("Correct!\n");
	}
	if (!(42 != 69) == 0)
	{
		printf("Correct!\n");
	}
	printf("\n");

	int counter = 0;
	char character = ',';
	char sentence[100] = "You can be one person to the world, but you can be the world to one person.";

	while (counter < 100)
	{
		printf("%c", sentence[counter]);

		if (sentence[counter] == character)
		{
			break;
		}

		counter++;
	}

	printf("\n");
	counter = -1;

	do
	{
		counter++;

		if (counter <= 34)
		{
			continue;
		}

		printf("%c", sentence[counter]);
	} while (counter < 100);

	printf("\n\n");

	for (int i = 0; i < 100; i++)
	{
		printf("%c", sentence[i]);
	}

	return 0;
}