#ifndef myClass_H
#define myClass_H

#include <string>

template<typename T>
class StringValuePair
{
private:
	std::string str;
	T somethingType;
public:
	StringValuePair(const std::string string, const T something) : str{ string }, somethingType{ something }
	{

	}

	const std::string first() const { return str; }
	const T& second() const { return somethingType; }


};


#endif // !myClass_H
