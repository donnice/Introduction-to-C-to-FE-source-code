// Point.hpp
//
// Page 142, Header file for points in two dimensions
//
// (C) Shujie CHEN @2016
//

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Shape
{
};

class Point:public Shape
{
private:
	double x;	// X coordinate
	double y;	// Y coordinate

	void init(double dx, double dy);

public:
	// Constructors
	Point();								// Default constructor
	Point(double xval, double yval);		// Initialize with value
	Point(const Point& pt);					// Copy constructor
	~Point();								// Destructor

	// Accessing functions
	double getX() const;					// The x-coordinate
	double getY() const;					// The y-coordinate

	// Arithmetic functions
	Point add(const Point& p) const;		// Return current + p;
	Point substract(const Point& p) const; 	// Return current - p;
	Point scale(const Point& p) const;		// Return current * p;

	// Copy
	Point& copy(const Point& p);			// Copy p in current
};

	ostream& operator << (ostream& os, const Point& p);

#endif