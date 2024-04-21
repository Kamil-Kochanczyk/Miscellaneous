#include "Person.h"
#include <iostream>

Person::Person()
{
	name = "Unknown";
	age = 0;
}

Person::Person(std::string name, int age)
{
	Person::name = name;
	Person::age = age;
}

Person::~Person()
{
	std::cout << "Destructor has been called" << std::endl;
}

void Person::Introduce()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
}

void Person::Introduce() const
{
	std::cout << "Name: " << name << " (this name won't change)" << std::endl;
	std::cout << "Age: " << age << " (this age won't change)" << std::endl;
}

void Person::Scream() const
{
	std::cout << "Aaaaaa!" << std::endl;
}

Helper::Helper() : iAmNotConstant(0), iAmConstant(0)
{

}

Helper::Helper(int x, int y) : iAmNotConstant(x), iAmConstant(y)
{

}

void Helper::Show()
{
	std::cout << iAmNotConstant << " (not const)" << std::endl;
	std::cout << iAmConstant << " (const)" << std::endl;
}