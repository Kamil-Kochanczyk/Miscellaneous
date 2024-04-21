#include <iostream>

using namespace std;

class MusicTrack
{
public:
	bool favourite;

private:
	string title;
	string composer;
	unsigned short int year;

public:
	MusicTrack()
	{
		this->favourite = false;
		this->title = "Untitled";
		this->composer = "Unknown";
		this->year = 0;
	}

	MusicTrack(bool favourite, string title, string composer, unsigned short int year)
	{
		this->favourite = favourite;
		this->title = title;
		this->composer = composer;
		this->year = year;
	}

	string GetTitle()
	{
		return title;
	}

	void SetTitle(string newTitle)
	{
		title = newTitle;
	}

	void ShowInfo()
	{
		if (favourite)
		{
			cout << "This is one of your favourite music tracks!" << endl;
		}

		cout << "Title: " << title << endl;
		cout << "Composer: " << composer << endl;
		cout << "Year: " << year << endl;
	}
};

int main()
{
	MusicTrack faded;

	faded.ShowInfo();
	cout << endl;

	faded.SetTitle("Faded");
	cout << faded.GetTitle() << endl << endl;

	faded.favourite = true;

	faded.ShowInfo();
	cout << endl;

	MusicTrack victory(true, "Victory", "Thomas Bergersen", 2015);
	victory.ShowInfo();
	cout << endl;

	return 0;
}