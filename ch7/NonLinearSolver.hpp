// NonLinearSolver.cpp
// 
// Various nonlinear solvers in one dimension
//
// (C) Shujie CHEN @2016
//

#include <math.h>
#include <assert.h>

#include <iostream>
using namespace std;

namespace NS_NonlinearSolver
{

class NonlinearSolver
{
public:
	double (*myF)(double x);	// Function whose root we want

	double tol;					// Desired accuracy

	NonLinearSolver() {}
	NonlinearSolver& operator = (const NonlinearSolver& n2) {}

public:
	NonlinearSolver(double (*function)(double))
	{
		
	}

};

class BisectionSolver: public NonLinearSolver
{
public:

	// Interval where we seek a solution
	double a;
	double b;

private:

	// Redundant data but useful as a log and postprocessing
	int n;			// Number of steps to take
	double myTol;
	double aCurrent; double bCurrent;
	double midPoint;

public:

	double solve()
	{
		double aPrevious = a;
		double bPrevious = b;
		n = 1;
		myTol = b - a; // Variable tolearance, starts at main interval
L1:
		midPoint = 0.5*(aPrevious + bPrevious);

		// Default interval
		if(myF(midPoint) <= 0.0)
		{
			aCurrent = 
		}
	}


};

}