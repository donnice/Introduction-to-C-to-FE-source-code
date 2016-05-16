// Person.hpp
//
// Person's name and age
//
// (C) Shujie CHEN @2016
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Person
{
public:

	string nam;
	int ag;

public:
	Person();
	Person(const string& name, const int& age);
	virtual ~Person();
	void print() const;
	int age() const;
};