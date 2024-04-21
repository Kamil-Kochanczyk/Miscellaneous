#include <stdio.h>

#define MAX 100

struct Person
{
	char name[MAX];
	unsigned int age;
};

typedef struct
{
	char title[MAX];
	char artist[MAX];
} Song;

typedef struct
{
	struct Person composer;
	Song best_song;
} Soundtrack;

union Series
{
	char title[MAX];
	unsigned int year;
};

typedef union
{
	char name[MAX];
	unsigned int letters;
} Alphabet;

void show_person(struct Person*);

void show_song(Song*);

int main()
{
	struct Person me;
	me.age = 19;
	sprintf_s(me.name, MAX, "Kamil");
	printf("Name: %s \n", me.name);
	printf("Age: %d \n", me.age);
	printf("\n");

	struct Person older_sister = { "Karolina", 16 };
	printf("Name: %s \n", older_sister.name);
	printf("Age: %d \n", older_sister.age);
	printf("\n");

	struct Person younger_sister = { .age = 12, .name = "Weronika" };
	printf("Name: %s \n", younger_sister.name);
	printf("Age: %d \n", younger_sister.age);
	printf("\n");

	struct Person copy_of_me = me;
	printf("Name: %s (copy)\n", copy_of_me.name);
	printf("Age: %d (copy)\n", copy_of_me.age);
	printf("\n");

	Song uia = { .title = "uia", .artist = "ms" };
	printf("Title: %s \n", uia.title);
	printf("Artist: %s \n", uia.artist);
	printf("\n");

	Soundtrack lotr = { .composer = { .name = "Howard Shore", .age = 75 }, .best_song = { .title = "The Eagles", .artist = "Renée Fleming" } };
	printf("Composer: %s, %d \n", lotr.composer.name, lotr.composer.age);
	printf("Best song: %s, %s \n", lotr.best_song.title, lotr.best_song.artist);
	printf("\n");

	struct Person* person_pointer;
	person_pointer = &me;
	sprintf_s(person_pointer->name, MAX, "Limak");
	person_pointer->age = 91;
	printf("Name: %s \n", copy_of_me.name);
	printf("Age: %d \n", copy_of_me.age);
	printf("\n");

	Song* song_pointer = &uia;
	sprintf_s((*song_pointer).title, MAX, "aiu");
	sprintf_s((*song_pointer).artist, MAX, "sm");
	printf("Title: %s \n", uia.title);
	printf("Artist: %s \n", uia.artist);
	printf("\n");

	// Use pointers to save time and memory!
	show_person(&copy_of_me);
	printf("\n");
	show_song(&uia);
	printf("\n");

	struct Person persons[3] =
	{
		{ .name = "Geralt", .age = 99 },
		{ .name = "Yennefer", .age = 100 },
		{ .name = "Cirilla", .age = 21 }
	};
	for (int i = 0; i < 3; i++)
	{
		show_person(&persons[i]);
	}
	printf("\n");

	Song songs[3] = 
	{
		{ .title = "Finale", .artist = "Ramin Djawadi" },
		{ .title = "Mhysa", .artist = "Ramin Djawadi" },
		{ .title = "The Winds of Winter", .artist = "Ramin Djawadi" }
	};
	for (int i = 0; i < 3; i++)
	{
		show_song(&songs[i]);
	}
	printf("\n");

	union Series our_planet;
	sprintf_s(our_planet.title, MAX, "Our Planet");
	printf("Title: %s \n", our_planet.title);
	printf("Year: %d \n", our_planet.year);
	our_planet.year = 2019;
	printf("Title: %s \n", our_planet.title);
	printf("Year: %d \n", our_planet.year);
	printf("\n");

	Alphabet greek;
	sprintf_s(greek.name, MAX, "Greek");
	printf("Name: %s \n", greek.name);
	printf("Letters: %d \n", greek.letters);
	greek.letters = 24;
	printf("Name: %s \n", greek.name);
	printf("Letters: %d \n", greek.letters);

	return 0;
}

void show_person(struct Person* person)
{
	printf("Name: %s \n", person->name);
	printf("Age: %d \n", person->age);
}

void show_song(Song* song)
{
	printf("Title: %s \n", song->title);
	printf("Artist: %s \n", song->artist);
}