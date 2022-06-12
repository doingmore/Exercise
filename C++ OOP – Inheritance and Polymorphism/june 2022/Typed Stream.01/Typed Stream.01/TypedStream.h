#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H

#include <vector>
#include "Vector2D.h"

template<typename T>
class TypedStream
{
private:
protected:
	std::istringstream stream;
public:
	TypedStream(const std::string& input) : stream{input}
	{}

	virtual TypedStream<T>& operator>>(T& v) = 0;

	std::string readToEnd()
	{
		std::string answer;
		std::string temp;
		while (stream >> temp)
		{
			answer = answer + temp;
			answer = answer + " ";
			temp.erase();
		}
		return answer;
	}
	
};


#endif // !TYPED_STREAM_H

