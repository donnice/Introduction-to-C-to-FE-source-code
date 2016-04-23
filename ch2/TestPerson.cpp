//TestPerson.cpp
//
//"Hello World" Testing the C++ class
//
//(C) Shujie CHEN 2016
//
#include "Person.hpp"
#include <string>
using namespace std;

int main(){
	int myAge = 24;;
	string myName("Shujie CHEN");
	Person dd(myName,myAge);
	dd.print();

	return 0;
}