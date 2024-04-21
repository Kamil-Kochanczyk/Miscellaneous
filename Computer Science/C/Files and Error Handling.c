#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

typedef struct
{
	char* name;
	int age;
} Item;

int main()
{
	errno = 0;

	FILE* pointer_w;
	pointer_w = fopen("C:\\Users\\kocha\\Desktop\\Test Folder\\Test File.txt", "w");

	if (pointer_w != NULL)
	{
		printf("File opened for writing.\n");
		printf("\n");

		fputc('\n', pointer_w);
		fputs("This is a test file.\n", pointer_w);
		fputs("It can be read using C.\n", pointer_w);
		fputs("0 1 2 3 4 5 6 7 8 9\n", pointer_w);
		fputs("!@#$%^&*()\n", pointer_w);
		fputc('\n', pointer_w);

		fclose(pointer_w);
	}
	else
	{
		perror("Error");
		fprintf_s(stderr, "Error code: %d\n", errno);
		fprintf_s(stderr, "%s\n", strerror(errno));
	}

	FILE* pointer_r;
	pointer_r = fopen("C:\\Users\\kocha\\Desktop\\Test Folder\\Test File.txt", "r");

	if (pointer_r != NULL)
	{
		printf("File opened for reading.\n");
		printf("\n");

		printf("The content of the file:\n");
		printf("------------------------------------------------------------\n");

		int c;
		while ((c = fgetc(pointer_r)) != EOF)
		{
			printf("%c", c);
		}

		if (feof(pointer_r))
		{
			printf("End of file reached.\n");
		}

		printf("------------------------------------------------------------\n");
		printf("\n");

		rewind(pointer_r);
		while ((fgetc(pointer_r)) != '\n');

		int counter = 0;
		while (fgetc(pointer_r) != '\n')
		{
			counter++;
		}
		printf("%d\n", counter);
		printf("\n");

		rewind(pointer_r);
		while ((fgetc(pointer_r)) != '\n');

		char* first_line;
		first_line = malloc((counter + 1) * sizeof(*first_line));
		fgets(first_line, counter + 1, pointer_r);
		printf("%s\n", first_line);
		printf("\n");

		fclose(pointer_r);
	}
	else
	{
		perror("Error");
		fprintf_s(stderr, "Error code: %d\n", errno);
		fprintf_s(stderr, "%s\n", strerror(errno));
	}

	Item items[5] =
	{
		{ .name = "Item 1", .age = 1 },
		{ .name = "Item 2", .age = 2 },
		{ .name = "Item 3", .age = 3 },
		{ .name = "Item 4", .age = 4 },
		{ .name = "Item 5", .age = 5 }
	};
	Item copies[5];
	Item first, third, last;
	FILE* binary;

	binary = fopen("C:\\Users\\kocha\\Desktop\\Test Folder\\Test Binary File.bin", "wb");
	fwrite(items, sizeof(items[0]), sizeof(items) / sizeof(items[0]), binary);
	fclose(binary);

	binary = fopen("C:\\Users\\kocha\\Desktop\\Test Folder\\Test Binary File.bin", "rb");
	fread(copies, sizeof(items[0]), sizeof(items) / sizeof(items[0]), binary);

	printf("------------------------------------------------------------\n");
	printf("Copies:\n");
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		printf("Name: %s\nAge: %d\n", copies[i].name, copies[i].age);
		printf("\n");
	}

	printf("------------------------------------------------------------\n");
	printf("\n");

	fseek(binary, 0, SEEK_SET);
	fread(&first, sizeof(items[0]), 1, binary);

	fseek(binary, 1 * sizeof(items[0]), SEEK_CUR);
	fread(&third, sizeof(items[0]), 1, binary);

	fseek(binary, -1 * (int)(sizeof(items[0])), SEEK_END);
	fread(&last, sizeof(items[0]), 1, binary);

	Item current;
	for (int i = 1; i <= 3; i++)
	{
		switch (i)
		{
		case 1:
			current = first;
			printf("First item\n");
			break;
		case 2:
			current = third;
			printf("Third item\n");
			break;
		case 3:
			current = last;
			printf("Last item\n");
			break;
		}

		printf("Name: %s\nAge: %d\n", current.name, current.age);
		printf("\n");
	}

	fclose(binary);

	int divident, divisor;
	
	printf("Enter an integer divident and an integer divisor separeted by space: ");
	scanf_s("%d %d", &divident, &divisor);

	if (divisor == 0)
	{
		printf("Dividing by 0 is undefined.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d / %d = %d\n", divident, divisor, divident / divisor);
		printf("\n");
	}

	float x = -1, y = 1000000, z;

	errno = 0;
	z = sqrt(x);
	if (errno == EDOM)
	{
		fprintf_s(stderr, "%s\n\n", strerror(errno));
	}

	errno = 0;
	z = exp(y);
	if (errno == ERANGE)
	{
		fprintf_s(stderr, "%s\n\n", strerror(errno));
	}

	printf("All error codes are listed below.\n");
	for (int i = 0; i < 135; i++)
	{
		fprintf_s(stderr, "%d: %s\n", i, strerror(i));
	}
	printf("\n");

	return 0;
}