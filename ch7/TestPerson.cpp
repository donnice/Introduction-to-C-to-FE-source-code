// TestPerson.cpp
//
// Simple app for printing person's information
//
// (C) Shujie CHEN @2016
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "Person.hpp"

using namespace std;

class Employee: public Person
{
public:
	string fun;	// Function
	double sal;	// Salary
	int wAge;	// Working age

	Employee();
	Employee(const string& name, const int& age, const string& function,
		const double& salary, const int& workingAge);
	//virtual ~Employee();
	void print() const;	// Print belongs to Employee
};

Employee::Employee()
{

}

Employee::Employee(const string& name, const int& age, const string& function,
		const double& salary, const int& workingAge)
{
	Person::Person(name, age);
	fun = function;
	sal = salary;
	wAge = workingAge;
}

// Employee::~Employee()
// {
// 	cout << "Warning: Employee is destructed!" << endl;
// }

void Employee::print() const
{
	cout << "\n **Employee Data** \n";
	Person::print();
	cout << "\nFunction: " << fun << ", Salary:" << sal
		<< ", has already worked for: " << wAge << " year(s)." << endl; 
}

int main()
{
	Person dd("Shujie CHEN",24);
	dd.print();

	cout << "===========================" << endl;

	Employee dd2("Shujie", 24, "Web Developer", 58000.0, 1);
	dd2.print();

	return 0;
}