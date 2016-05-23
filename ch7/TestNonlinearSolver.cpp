// TestNonlinearSolver.cpp
//
// Testing Bisection method and Newton Raphson method.
//
// (C) Shujie CHEN @2016
//

#include "NonLinearSolver.hpp"
#include <math.h>
#include <assert.h>
#include <iostream>
using namespace std;

double Func1(double x)
{
	double tmp = 0.5 * x;

	return (tmp*tmp) - ::sin(x);
}

double DerivativeFunc1(double x)
{
	// Just the derivative, need for Newton's method
	return (0.5 * x) - ::cos(x);
}

int main()
{
	using namespace NS_NonlinearSolver;

	// 1. Bisection method

	// Initial interval
	double a = 1.52;
	double b = 2.0;

	// In this version all data is public; in a later version
	// make it private
	BisectionSolver bs;
	bs.myF = Func1;
	bs.a = a; bs.b = b;
	bs.tol = 0.0001;

	double result = bs.solve();
	cout << "Bisection:" << result << ", " << bs.accuracy() << endl;

	bs.printStatistics();

	// 2. Newton Methos
	

	return 0;

}