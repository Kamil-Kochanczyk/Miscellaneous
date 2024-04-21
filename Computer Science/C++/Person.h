#pragma once

#include <string>

class Person
{
private:
	std::string name;
	int age;

public:
	Person();
	Person(std::string name, int age);
	~Person();
	void Introduce();
	void Introduce() const;
	void Scream() const;
};

class Helper
{
private:
	int iAmNotConstant;
	const int iAmConstant;

public:
	Helper();
	Helper(int x, int y);
	void Show();
};