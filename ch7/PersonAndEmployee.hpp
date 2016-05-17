// PersonAndEmployee.cpp
//
// 'Hello World' Inheritance Example
//
// (C) Shujie CHEN @2016
//

#include <string>

using namespace std;

class Person
{
public:

	// Data
	string nam;
	int ag;

public:
	Person(const string& name, const int& age)
	{
		nam = name;
		ag = age;
	}

	void print() const
	{
		
	}
}