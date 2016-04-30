//Conversions.cpp
//
//template of getString()
//
//(C) Shuije CHEN @2016
//

#ifndef Conversions_CPP
#define Conversions_CPP

#include "Conversions.hpp"

/////////////////Useful functions///////////////////
//getString()

template <typename T>
string getString(const T& value)
{
	stringstream s;
	s << value;
	return s.str();
}

////////////////////////////////////////////
#endif
