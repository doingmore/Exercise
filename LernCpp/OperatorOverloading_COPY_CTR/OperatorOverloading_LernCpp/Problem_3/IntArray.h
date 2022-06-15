#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>
#include <sstream>
#include <cassert>

class IntArray
{
private:
	int m_length;
	int* m_data;
public:
	explicit IntArray(const int& length);

	int& operator[] (const int& index) const;

	friend std::ostream& operator<< (std::ostream& stream, const IntArray& left);

	IntArray(const IntArray& other);
	IntArray& operator= (const IntArray& other);


	~IntArray();
};





#endif // !INTARRAY_H
