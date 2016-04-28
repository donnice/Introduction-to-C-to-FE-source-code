//GenericInequalities.cpp
//
//Code file containing bodies of functions
//
//(C) Shujie CHEN @2016
//

#ifndef GenericInequalities_CPP
#define GenericInequalities_CPP

#include "GenericInequalities.hpp"

/////////////////Useful functions///////////////////

//Max and Min of two numbers
template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y)
{
	if(x > y)
		return x;
	return y;
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y)
{
	if(x < y)
		return x;
	return y;	
}

template <class Numeric>
Numeric Max(const Numeric& x, const Numeric& y, const Numeric& z)
{
	return Max<Numeric>(Max<Numeric>(x,y),z);
}

template <class Numeric>
Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z)
{
	return Min<Numeric>(Min<Numeric>(x,y),z);
}

#endif