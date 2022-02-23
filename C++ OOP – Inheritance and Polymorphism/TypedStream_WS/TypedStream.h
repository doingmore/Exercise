#ifndef TypedStream_H
#define TypedStream_H

#include <string>
#include <sstream>
#include <vector>

#include "Vector2D.h"

template <typename T>
class TypedStream
{
protected:
	std::istringstream stream;

	virtual TypedStream<T>& operator>> (T& something) = 0; // pure virtual 
	
public:

	TypedStream(std::string input) : stream(input)
	{
	}

	std::vector<T> readToEnd()
	{
		T element;
		std::vector<T> all;
		while (this->operator>>(element).stream.good())
		{
			all.push_back(element);
		}
		return all;
	}
};
#endif // !TypedStream_H
