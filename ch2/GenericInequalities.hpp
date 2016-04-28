//GenericInequalities.hpp
//
//Header file containing declarations of functions
//
//This is the template/generic version
//
//(C) Shujie CHEN 2016
//

#ifdef GenericInequalities_HPP
#define GenericInequalities_HPP

/////////////////Useful functions///////////////////

//Max and Min of two numbers
template <class Numeric>
	Numeric Max(const Numeric& x, const Numeric& y);
template <class Numeric>
	Numeric Min(const Numeric& x, const Numeric& y);

//Max and min of three numbers
template <class Numeric>
	Numeric Max(const Numeric& x, const Numeric& y, const Numeric& z);
template <class Numeric>
	Numeric Min(const Numeric& x, const Numeric& y, const Numeric& z);

#endif

