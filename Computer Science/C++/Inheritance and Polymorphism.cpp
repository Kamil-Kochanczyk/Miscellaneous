#include <iostream>

using namespace std;

class Animal
{
private:
	bool intelligent;

protected:
	string name;

public:
	Animal() : intelligent(false), name("Unknown")
	{
		cout << "Animal created" << endl;
	}

	~Animal()
	{
		cout << "Animal destroyed" << endl;
	}

	void ShowInfo()
	{
		cout << "Intelligent: " << intelligent << endl;
		cout << "Name: " << name << endl;
	}

	friend void MakeException(Animal& a);
};

void MakeException(Animal& a)
{
	a.intelligent = true;
}

class Human : public Animal
{
private:
	int privateNum = 42;

protected:
	int protectedNum = 69;

public:
	int publicNum = 520;

	Human()
	{
		MakeException(*(this));

		this->name = "Human";

		cout << "Human created" << endl;
	}

	~Human()
	{
		cout << "Human destroyed" << endl;
	}
};

class PublicTeenager : public Human
{
	/*
	pritvateNum -> private
	protectedNum -> protected
	publicNum -> public
	*/
};

class ProtectedTeenager : protected Human
{
	/*
	privateNum -> private
	protectedNum -> protected
	publicNum -> protected
	*/
};

class PrivateTeenager : private Human
{
	/*
	privateNum -> private
	protectedNum -> private
	publicNum -> private
	*/
};

class Tower
{
public:
	virtual void Attack()
	{
		cout << "No weapon specified" << endl;
	}
};

//class Tower	// Abstract class
//{
//public:
//	virtual void Attack() = 0;	// Pure virtual function
//};

class NinjaMonkey : public Tower
{
	void Attack()
	{
		cout << "Shuriken attack!" << endl;
	}
};

class BoomerangThrower : public Tower
{
	void Attack()
	{
		cout << "Boomerang attack!" << endl;
	}
};

int main()
{
	Animal a;
	a.ShowInfo();
	cout << endl;

	Human h;
	h.ShowInfo();
	cout << endl;

	Tower t;
	NinjaMonkey nm;
	BoomerangThrower bt;
	Tower towerObjects[3] = { t, nm, bt };

	for (int i = 0; i < 3; i++)
	{
		towerObjects[i].Attack();
	}
	cout << endl;

	Tower* towerPointers[3] = { &t, &nm, &bt };
	for (int i = 0; i < 3; i++)
	{
		towerPointers[i]->Attack();
	}
	cout << endl;

	Tower* ptr;
	
	ptr = new NinjaMonkey;
	ptr->Attack();
	cout << endl;
	delete ptr;

	ptr = new BoomerangThrower;
	ptr->Attack();
	cout << endl;
	delete ptr;

	return 0;
}