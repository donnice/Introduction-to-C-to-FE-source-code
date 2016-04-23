//Person.cpp
//
//"Hello World" class
//
//(C) Shujie CHEN 2016
//
#include "Person.hpp"

Person::Person(const string& name,const int& age)
{
	nam = name;
	ages = age;
}

int Person::age() const
{
	return ages;
}

void Person::print() const
{
	cout << "\n** Person Data **\n";
	cout << "Name: "<< nam << ", Age:" << age() << endl;
}