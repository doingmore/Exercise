#include <string>
#include <sstream>
#include <cassert>

#include "Resource.h"

bool operator< (const Resource& left, const Resource& right)
{
	return left.getId() < right.getId();
}



