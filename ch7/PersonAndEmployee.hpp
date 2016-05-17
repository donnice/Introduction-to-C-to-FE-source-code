// PersonAndEmployee.cpp
//
// 'Hello World' Inheritance Example
//
// (C) Shujie CHEN @2016
//

#include <iostream>
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
		cout << "\n** Personal Data **\n";

		cout << "Name: " << nam << ", age:" << age() << endl;
	}

	int age() const
	{
		return ag;
	}
};

class Employee: public Person
{
public: 

	string fun;	// Function
	double sal; // Salary
	int wAge; 	// Working age

public:

	Employee(const string& name, const int& age,
		const string& function, double salary, int working) : Person(name, age)
	{
		fun = function;
		sal = salary;
		wAge = working;
	}

	void print() const
	{
		cout << "\n** Employee Data **\n";
		Person::print();

		cout << "\nFunction: " << fun << ", Salary:" << sal
		<< ", has already worked for: " << wAge << " year(s)." << endl;
	}

	int YearsOfWorking() const
	{
		return wAge;
	}
};