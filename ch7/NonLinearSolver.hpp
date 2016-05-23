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
	int n;		// Number of steps taken until now

public:
	NewtonRaphsonSolver(double guess)
	{
		x0 = guess;
	}

	double solve()
	{
		double xPrevious = x0;
		double hn = 100.0;
		n = 1;
L1:
		hn = -myF(xPrevious) / derivative(xPrevious);
		xCurrent = xPrevious + hn;

		xPrevious = xCurrent;
		n++;
		if(fabs(hn) > tol) goto L1;

		return xCurrent;
	}

	void printStatistics() const
	{
		cout << "\nData pertaining to Newton Raphson method\n";
		cout << "Value: " << xCurrent << endl;
		cout << "Number of iterations (actual): " << n << endl;
	}

};

class SecantMethodSolver : public NonLinearSolver
{
	// Two-step nonlinear solver

private:

	double x0;				// Initial guess
	double x1;				// Initial guess

	// Parameters in iterations
	double xOld, xNew;		// x(n-1) and x(n)
	double fOld, fNew;		// f(n-1) and f(n)
	double xCurrent;
	long n;

public:

	SecantMethodSolver(double guessZero, double guessOne,
						double (*myFunction)(double x))
	{
		x0 = guessZero;
		x1 = guessOne;
		myF = myFunction;

		xOld = x0;
		xNew = x1;
		xCurrent = xNew;
		fOld = myF(xOld); fNew = myF(xNew);
	}

	double solve()
	{
		double diff;
		double hn;
		n = 1;
L1:
		assert(fOld != fNew);
		diff = (xNew - xOld)/(fNew - fOld);
		hn = -myF(xNew) * diff;
		xCurrent = xNew + hn;

		n++;
		if(::fabs(hn) <= tol)
		{
			return xCurrent;
		}

		//update all registers
		xOld = xNew; xNew = xCurrent;
		fOld = myF(xOld); fNew = myF(xNew);

		goto L1;
	}

	void printStatistics() const
	{
		cout << "\nData pertaining to Secant method\n";
		cout << "Value: " << xCurrent << endl;
		cout << "Number of iterations (actual): " << n << endl;
	}

};

class SteffensensSolver : public NonlinearSolver
{ // One-step nonlinear solver
private:
	SteffensensSolver(double guess, double(*myFunction)(double x))
	{
		x0 = guess; xPrevious = x0;
		myF = myFunction;
	}

	double solve()
	{
		double tmp;
		double hn;
		n = 1;
		xPrevious = x0;
L1:
		tmp = myF(xPrevious);
		hn = (myF(xPrevious + tmp) - tmp)/tmp;
		hn = tmp/hn;
		xCurrent = xPrevious - hn;
		xPrevious = xCurrent;

		n++;
		if(::fabs(fn) <= tol)
		{
			return xCurrent;
		}

		goto L1;
	}

	void printStatistics() const
	{
		cout << "\nData pertaining to Secant method\n";
		cout << "Value: " << xCurrent << endl;
		cout << "Number of iterations (actual): " << n << endl;
	}

};

}