//Person.hpp
//
//"Hello World" class. Function declarations
//
//(C) Shujie CHEN 2016

#ifndef Person_HPP
#define Person_HPP

#include <string>
#include <iostream>
using namespace std;

class Person
{
public:
	//Data
	string nam;				//Name of person
	int ages;	//Created date;
public:
	Person(const string& name, const int& age);
	void print() const;
	int age() const;
};
#endif