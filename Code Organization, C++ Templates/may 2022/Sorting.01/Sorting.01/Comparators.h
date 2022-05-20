#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <string>
#include <set>
#include "Song.h"

template<typename T>
struct LessThan
{
    const bool operator()(const T& left, const T& right) const 
    {
        return left < right;
    };
};


template<typename T, typename LessThan>
struct Reverse 
{
    const bool operator()(const T& left, const T& right) const 
    {
        LessThan comparator;
        return !comparator(left, right);
    }
};


#endif // !COMPARATORS_H