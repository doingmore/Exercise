#ifndef VectorComparisons_H
#define VectorComparisons_H

#include "Vector.h"

struct VectorLengthComparer
{
	bool operator() (const Vector& a, const Vector& b) const
	{
		return  ( a.getLength() < b.getLength() );
	}
};

template<typename T, typename Comp>
class ReverseComparer
{
	Comp comparer;
public:
	bool operator() (const T& a, const T& b) const
	{
		return comparer(b, a);
	}

};


#endif // !VectorComparisons_H