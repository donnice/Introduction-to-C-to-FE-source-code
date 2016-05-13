// TestSmallApp.cpp
//
// A small application related to Complex number
//
// (C) Shujie CHEN @2016
//

#include <iostream>
#include <string>
#include <complex>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include "Complex.hpp"

using namespace std;

int main()
{
	Complex z1(1.0,1.0);
	Complex z2(2.0, 3.0);
	Complex z3 = z1.add(z2);
	return 0;
}