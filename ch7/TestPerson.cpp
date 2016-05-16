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

int main()
{
	Person dd("Shujie CHEN",24);
	dd.print();

	return 0;
}