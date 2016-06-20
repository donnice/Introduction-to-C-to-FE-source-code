// Point.cpp
//
// Page 144. Header file for points in two dimensions
//
// (C) Shujie CHEN @2016
//

#include "Point.hpp"

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

