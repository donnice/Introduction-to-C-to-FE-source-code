// TestPersonAndEmployee.cpp
//
// 'Hello World' Inheritance Example
//
// (C) Shujie CHEN @2016
//

#include <iostream>
#include <string>
#include "PersonAndEmployee.hpp"

using namespace std;

int main()
{
	Person dd("Shujie CHEN",25);
	dd.print();

	cout << "==========================" << endl;

	Employee dde("Shujie CHEN",25,"Web Developer", 58000.0, 1);
	dde.print();

	cout << "==========================" << endl;

	cout << "Working with pointers I\n"; // Non-polymorphic function
	Person* p = &dd;
	p -> print();

	cout << "==========================" << endl;

	cout << "Working with pointers II\n"; // Non-polymorphic function
	Employee* pe = &dde;
	pe -> print();


	return 0;

}