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

Complex myFunc(const Complex& z);
//Complex ComplexProduct(Complex* carr, int n);

int main()
{
	Complex z1(1.0,1.0);
	Complex z2(2.0, 3.0);
	Complex z3 = z1 * z2;
	Complex z4 = z3 * 2.0;

	int size = 4;
	Complex* cpArray = new Complex[size];
	cpArray[0] = z1;
	cpArray[1] = z2;
	cpArray[2] = z3;
	cpArray[3] = z4;

	for(int j = 0; j < size; j++)
	{
		Complex cpx = myFunc(cpArray[j]);
		cout << cpx.getReal() << cpx.getImag() << "i" << ",";
	}

	delete [] cpArray;

	return 0;
}

Complex myFunc(const Complex& z)
{
	return z * z;
}
