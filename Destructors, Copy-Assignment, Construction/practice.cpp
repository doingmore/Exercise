#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <cassert>

//#include "myClass.h"


class IntArray
{
private:
	int m_length;
	int* m_array;
public:
	IntArray(int length)
	{
		assert(length > 0);
		m_array = new int[static_cast<std::size_t>(length)]{};
		m_length=length;
	}

	~IntArray()
	{
		delete[] m_array;
	}

	//discuss this what do, in 13.14 ->> Converting constructors explicit and delete
	IntArray(const IntArray&) = delete;
	IntArray& operator= (IntArray&) = delete;
	//discuss this what do, in 13.14 ->> Converting constructors explicit and delete

	int getLength() const { return this->m_length; }

	void setValue(const int& index, const int& value) { m_array[index] = value; }

	int getValue(const int& index) const { return m_array[index];}
};



int main()
{
	IntArray array(10); //allocate 10 integers

	for (size_t i = 0; i < array.getLength() ; i++)
	{
		array.setValue(i, i + 1);
	}

	std::cout << "The value of element 5 is: " << array.getValue(5) << '\n';

	return 0;
}