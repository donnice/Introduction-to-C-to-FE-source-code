// TestNonlinearSolver.cpp
//
// Testing Bisection method and Newton Raphson method.
//
// (C) Shujie CHEN @2016
//

#include "NonlinearSolver.hpp"
#include <math.h>
#include <iostream>
using namespace std;

double Func1(double x)
{
	double tmp = 0.5 * x;

	return (tmp*tmp) - ::sin(x);
}

double DerivativeFunc1(double x)
{
	
}