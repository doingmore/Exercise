#include <iostream>
#include <cassert>
#include <string>

/*
Write your own integer array class named IntArray from scratch (do not use std::array or std::vector).
Users should pass in the size of the array when it is created, and the array should be dynamically allocated.
Use assert statements to guard against bad data. Create any constructors or
overloaded operators needed to make the following program operate correctly:
*/

// .h
class IntArray
{
private:
	int m_length;
	int* m_data;
public:
	IntArray(const int& length);
	IntArray(const IntArray& other);


	friend IntArray fillArray();
	int& operator[] (const int& index);
	IntArray& operator=(const IntArray& other);
	friend std::ostream& operator<< (std::ostream& stream, const IntArray& object);
	~IntArray();
};
// .h






// .cpp
IntArray::IntArray(const int& length) : m_length{ length }
{
	assert(m_length >= 0);
	m_data = new int[m_length] {};
}

IntArray::IntArray(const IntArray& other) : m_length{ other.m_length }
{
	m_data = new int[m_length] {};
	for (int i = 0; i < m_length; i++)
	{
		m_data[i] = other.m_data[i];
	}
	std::cout << "The copy CTR been executed" << '\n';
}

int& IntArray::operator[] (const int& index)
{

	return m_data[index];
}


IntArray& IntArray::operator=(const IntArray& other)
{
	if (this == &other)
	{
		return *this;
	}

	m_length = other.m_length;
	assert(other.m_length > 0);

	if (m_data)
	{
		delete[] m_data;
	}

	m_data = new int[m_length] {};
	for (int i = 0; i < m_length; i++)
	{
		m_data[i] = other.m_data[i];
	}

	return *this;
}

std::ostream& operator<< (std::ostream& stream, const IntArray& object)
{
	for (int i = 0; i < object.m_length; i++)
	{
		stream << object.m_data[i] << " ";
	}
	return stream;
}

IntArray::~IntArray()
{
	delete[] m_data;
	m_data = NULL;
	std::cout << "The destructor been executed" << '\n';
}

// .cpp



// skeleton
IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main_2()
{
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a };
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';
	return 0;
}
// skeleton