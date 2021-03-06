// Point.cpp
//
// Page 144. Header file for points in two dimensions
//
// (C) Shujie CHEN @2016
//

#include "Point.hpp"

using namespace std;

// Private functions
void Point::init(double dx, double dy)
{
	x = dx;
	y = dy;
}

Point::Point()
{ // Default constructor
	init(0.0,0.0);
}

Point::Point(double newx, double newy)
{ // Initialize using newx and newy
	init(newx, newy);
}

Point::Point(const Point& pt)
{ // Copy constructor
	x = pt.x;
	y = pt.y;
}

Point::~Point()
{
	cout << "I am destructed!" << endl;
}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

// Arithmetic functions
Point Point::add(const Point& p) const
{
	return Point(x + p.x, y + p.y);
}

Point Point::substract(const Point& p) const
{
	return Point(x - p.x, y - p.y);
}

Point Point::scale(const Point& p) const
{ // Scale a Point by another Point
	return Point(x*p.x, y*p.y);
}

// Copy
Point& Point::copy(const Point& p)
{ // Copy p in current
	x = p.x;
	y = p.y;

	return *this;
}

ostream& operator << (ostream& os, const Point& p)
{ // Output to screen

	os << "Point: (" << p.getX() << ", " << p.getY() << ")" << endl;

	return os;
}