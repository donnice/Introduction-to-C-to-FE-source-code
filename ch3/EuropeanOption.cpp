// EuropeanOption.cpp
//
// Author: Daniel Duffy
//
// (C) Shujie CHEN @2016
//	


#include "EuropeanOption.hpp"	// Declarations of functions
#include <math.h>				// For mathematical functions, exp()

// Kernel Functions
double EuropeanOption::CallPrice() const
{
	double tmp = sig * sqrt(T);

	double d1 = (log(U/K))
}