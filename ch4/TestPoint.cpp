// TestPoint.cpp
//
// Constant objects testing
//
// (C) Shujie CHEN @2016

#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
	void init(double xs, double ys);

	double x;
	double y;

public:

	Point();						// Default constructor
	Point(double xs, double ys);	// Constructor with coordinates
	Point(const Point& source);		// Copy of constructor
	virtual ~Point();				// Destructor

	double X() const;				// return X
	double Y() const;				// return Y

	void X(double NewX);			// Set X
	void Y(double NewY);			// Set Y

};

double Point::X() const
{
	return x;
}

double Point::Y() const
{
	return y;
}