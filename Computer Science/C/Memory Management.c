#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int capacity;
	int count;
	int* elements;
} List;

typedef struct
{
	char* title;
	char* author;
	unsigned int year;
} Book;

void clear_buffer();

void initialize_list(List* list, int initial_capacity);

void add_element(List* list, int element);

void expand_list(List* list, int number);

void display_list(List* list);

int main()
{
	printf("malloc(size) - function that allocates a block of memory of specified size.\n");
	printf("This block consists of contiguous subblocks, just like in the case of arrays.\n");
	printf("Elements in those subblocks are not initialized to default values though and could be garbage in the beginning.\n");
	printf("\n");

	unsigned int howMany;
	printf("How many integers would you like to enter?\n");
	scanf_s("%lu", &howMany);
	printf("\n");

	int* pointer;
	pointer = (int*)malloc(howMany * sizeof(*pointer));

	if (pointer != NULL)
	{
		if (howMany != 0)
		{
			for (int i = 0; i < howMany; i++)
			{
				printf("Integer %d: ", i + 1);
				scanf_s("%d", pointer + i);
				clear_buffer();
				printf("You entered: %d \n", *(pointer + i));
				printf("\n");
			}
		}

		printf("Needed memory: %d \n", howMany * sizeof(*pointer));
	}
	else
	{
		printf("There is not enough memory for that many integers.\n");
	}
	printf("\n");

	printf("free(pointer) - function that frees a specific block of memory, so that it can be used again for other purposes.\n");
	printf("The data in that block of memory is not erased, although accessing it after freeing results in undefined behaviour.\n");
	printf("\n");

	if (pointer != NULL)
	{
		free(pointer);

		if (howMany != 0)
		{
			printf("Proof: ");

			for (int i = 0; i < howMany; i++)
			{
				printf("%d%s", *(pointer + i), (i == howMany - 1) ? "\n" : ", ");
			}

			printf("\n");
		}
	}

	printf("calloc(number_of_items, item_size) - function that allocates a block of memory for specified number of items, each of the same size.\n");
	printf("Additionaly, all values are set to 0.\n");
	printf("\n");

	Book* book_pointer;
	book_pointer = (Book*)calloc(3, sizeof(Book));

	if (book_pointer != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				book_pointer->title = "1984";
				book_pointer->author = "George Orwell";
				book_pointer->year = 1949;
				break;
			case 1:
				book_pointer->title = "Fahrenheit 451";
				book_pointer->author = "Ray Bradbury";
				book_pointer->year = 1953;
				break;
			case 2:
				book_pointer->title = "Brave New World";
				book_pointer->author = "Aldous Huxley";
				book_pointer->year = 1932;
				break;
			}

			printf("Title: %s \n", book_pointer->title);
			printf("Author: %s \n", book_pointer->author);
			printf("Year: %d \n", book_pointer->year);
			printf("\n");
		}
	}

	printf("realloc(pointer, size) - function that reallocates a block of memory so that it can grow or shrink.\n");
	printf("After reallocating, all values remain unchanged.\n");
	printf("\n");

	char* character;
	char* name;

	character = (char*)malloc(1 * sizeof(*character));

	if (character != NULL)
	{
		*character = 'K';

		name = realloc(character, 6 * sizeof(*character));

		if (name != NULL)
		{
			*(name + 1) = 'a';
			*(name + 2) = 'm';
			*(name + 3) = 'i';
			*(name + 4) = 'l';
			*(name + 5) = '\0';

			printf("My name is %s.\n", name);
			printf("\n");

			free(name);
		}
	}

	char text[100];
	strcpy_s(text, 100, "Hello world!");

	printf("%s \n", text);
	printf("Length: %d \n", strlen(text));
	printf("Size: %d \n", sizeof(text));
	printf("\n");

	char* trimmed;
	trimmed = malloc(strlen(text) + 1);
	strcpy_s(trimmed, strlen(text) + 1, text);

	printf("%s \n", trimmed);
	printf("Length: %d \n", strlen(trimmed));
	printf("Size: %d \n", sizeof(trimmed));
	printf("\n");

	List list;
	List* list_pointer = &list;

	initialize_list(list_pointer, 10);

	for (int i = 0; i < list.capacity; i++)
	{
		add_element(list_pointer, i);
	}

	printf("Original list:\n");
	display_list(list_pointer);
	printf("\n");

	expand_list(list_pointer, 90);

	for (int i = list.count; i < 50; i++)
	{
		add_element(list_pointer, i);
	}

	printf("Expanded list:\n");
	display_list(list_pointer);
	printf("\n");

	printf("Count: %d \n", list.count);
	printf("Capacity: %d \n", list.capacity);

	return 0;
}

void clear_buffer()
{
	while ((getchar()) != '\n');
}

void initialize_list(List* list, int initial_capacity)
{
	if (list != NULL && initial_capacity >= 0)
	{
		int* test_pointer;
		test_pointer = calloc(initial_capacity, sizeof(*(list->elements)));

		if (test_pointer != NULL)
		{
			list->capacity = initial_capacity;
			list->count = 0;
			list->elements = test_pointer;
		}
		else
		{
			printf("There is not enough memory for that big list.\n");
		}
	}
	else
	{
		printf("Error.\n");
		printf("Pointer is NULL or initial capacity is negative.\n");
	}
}

void add_element(List* list, int element)
{
	if (list != NULL && list->count < list->capacity)
	{
		list->elements[list->count] = element;
		(list->count)++;
	}
	else
	{
		printf("Error.\n");
		printf("Pointer is NULL or there is not enough space for next element.\n");
	}
}

void expand_list(List* list, int number)
{
	if (list != NULL && number > 0)
	{
		list->capacity += number;
		
		int* test_pointer;
		test_pointer = realloc(list->elements, (list->capacity) * sizeof(*(list->elements)));

		if (test_pointer != NULL)
		{
			list->elements = test_pointer;
		}
		else
		{
			printf("Error.\n");
			printf("There is not enough memory to expand list that much.\n");
			list->capacity -= number;
		}
	}
	else
	{
		printf("Error.\n");
		printf("Pointer is NULL or number is not positive.\n");
	}
}

void display_list(List* list)
{
	if (list != NULL)
	{
		for (int i = 0; i < list->count; i++)
		{
			printf("Element %d: %d \n", i, list->elements[i]);
		}
	}
	else
	{
		printf("Error.\n");
		printf("Pointer is NULL.\n");
	}
}