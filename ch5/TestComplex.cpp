// TestComplex.cpp
//
// Operator overloading testing
//
// (C) Shujie CHEN @2016

#include <iostream>
#include <string>
#include <complex>
#include <stdio.h>

using namespace std;

//Complex

int main()
{
	complex<long> comx1(32,45);
	complex<float> comx2(32.5,45.5);

	cout << "Real of comx1:" << comx1.real() << "::::Imaginary of comx1:" << comx1.imag() << endl;
	cout << "Real of comx2:" << comx2.real() << "::::Imaginary of comx2:" << comx2.imag() << endl;
	return 0;
}