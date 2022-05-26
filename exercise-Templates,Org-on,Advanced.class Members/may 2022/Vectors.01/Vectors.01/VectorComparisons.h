#ifndef VECTOR_COMPARISONS_H
#define VECTOR_COMPARISONS_H

#include "Vector.h"

struct VectorLengthComparer
{
	bool operator()(const Vector& left, const Vector& right) const
	{
		return ( left.getLengthSq() < right.getLengthSq() );
	}
};
//      < Vector ,  VectorLengthComparer >                      
template<typename T, typename Comparer>
class ReverseComparer
{
private:
	Comparer com;
public:
	bool operator() (const T& left, const T& right) const
	{
		return com(right , left); // com member calling bool operator from struct VectorLengthComparer
	}
};

#endif // !VECTOR_COMPARISONS_H