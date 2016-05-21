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
			aCurrent = midPoint;
			bCurrent = bPrevious;
		}

		if(myF(midPoint) > 0.0)
		{
			aCurrent = aPrevious;
			bCurrent = midPoint;
		}

		myTol *= 0.5; // At each step we have a subdivision

		aPrevious = aCurrent;
		bPrevious = bCurrent;
		n++;

		if(myTol > tol) goto L1;

		// Now the answer
		midPoint = 0.5*(aPrevious + bPrevious);

		return midPoint;
	}

	double accuracy() const
	{
		// How close is our solution?
		return myTol;
	}

	void printStatistics()
	{
		double m = solve();

		cout << "\nData pertaining to Bisection method\n";
		cout << "Interval containing value:("<< aCurrent << ","
											<< bCurrent << ")\n";
		cout << "Value: " << m << endl;
		cout << "Number of iterations:" << n << endl;
		cout << "Number of iterations (scheduled):" << estimate() << endl;
	}

	long estimate() const
	{	// Estimates the # of needed iterations
		double tmp = (b-a)/tol;
		double val = 1.0 +(::log(tmp)/::log(2.0));

		return ::ceil(val);
	}
};

class NewtonRaphsonSolver : public NonlinearSolver
{
public:
	double (*derivative)(double x);

private:
	double x0;	// Initial guess
	double xCurrent;
	int n;		// Number of strps taken until now
};

}