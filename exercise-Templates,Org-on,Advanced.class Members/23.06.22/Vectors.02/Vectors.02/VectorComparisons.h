#ifndef VECTOR_COMPARISONS_H
#define VECTOR_COMPARISONS_H

#include "Vector.h"


struct VectorLengthComparer
{

	bool operator() (const Vector& left, const Vector& right)const
	{
		return ( left.getLengthSq() > right.getLengthSq() );
	}

};

template <typename Vector , typename VectorLengthComparer>
struct ReverseComparer
{
	bool operator() (const Vector& left, const Vector& right)const
	{
		VectorLengthComparer biggerThan;
		return biggerThan(left, right);
	}
};

#endif // !VECTOR_COMPARISONS_H
