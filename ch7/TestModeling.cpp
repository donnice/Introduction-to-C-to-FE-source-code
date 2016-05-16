// TestModeling.cpp
//
// Modeling functions in C++
//
// (C) Shujie CHEN @2016

#include <iostream>
#include <stdio.h>

using namespace std;

void genericFunction(double myX, double myY,
						double (*f)(double x, double y))
{
	// Call function f with arguments myX and myY
	// Passed to the pointer function f
	// f represents pointer function
	double result = (*f)(myX, myY);	

	cout << "Result is: " << result << endl;
}

double add(double x, double y)
{
	std::cout << "** Adding two numbers: " << x << "," << y << endl;
	return x+y;
}

double multiply(double x, double y)
{
	cout << "** Multiplying two numbers:" << x << ", " << y << endl;
	return x*y;
}

double substract(double x, double y)
{
	cout << "** Substracting two numbers:" << x << ", " << y << endl;
	return x - y;	
}

namespace StandardInterface
{
	// Namespace consisting of function pointers
	double (*func1)(double x);
	double (*func2)(double x, double y);
}

namespace Implementation1
{
	double F1(double x) { return x; }
	double F2(double x, double y){ return x*y; }
}

namespace Implementation2
{
	double G1(double x){ return -x; }
	double G2(double x, double y){ return -x*y; }
}

using namespace StandardInterface;
using namespace Implementation2;

int main()
{
	double x = 3.0;
	double y = 2.0;
	genericFunction(x,y,add);
	genericFunction(x,y,multiply);
	genericFunction(x,y,substract);

	StandardInterface::func1 = Implementation1::F1;
	StandardInterface::func2 = Implementation1::F2;

	func1 = G1;
	func2 = G2;

	cout << func1(2.0) << ", " << func2(3.0, -4.0) << endl; 

	return 0;
}