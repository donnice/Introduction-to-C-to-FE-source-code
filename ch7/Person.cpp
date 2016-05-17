//Person.cpp
//
// Person's name and age
//
// (C) Shujie CHEN @2016
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "Person.hpp"

using namespace std;

Person::Person()
{

}

Person::Person(const string& name, const int& age)
{
	nam = name;
	ag = age;
}

// Person::~Person()
// {
// 	cout << "Warning: Person is deleted" << endl;
// }

void Person::print() const
{
	cout << "\n **Person Data** \n";
	cout << "Name: " << nam << ",Age:" << age() << endl;
}

int Person::age() const
{
	return ag;
}