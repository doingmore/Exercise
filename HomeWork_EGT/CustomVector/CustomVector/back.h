#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <string>
#include <sstream>
#include <iterator>

#define incrementStep 2
#define startExtendFrame 5


template<typename T>
class Vector
{
public:

	Vector() : m_size{ 0 }, m_capacity{ 0 }
	{}
	Vector& operator= (const Vector& other) // only for types without members pointers
	{
		if (this == &other)
		{
			return *this;
		}
		if (this->m_list != NULL)
		{
			delete[] m_list;
		}

		m_size = other.m_size;
		m_capacity = other.m_capacity;

		m_list = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_list[i] = other.m_list[i];
		}

		return *this;
	}

	Vector(const Vector& other) // only for types without members pointers
		: m_size{ other.m_size }
		, m_capacity{ other.m_capacity }
	{
		m_list = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_list[i] = other.m_list[i];
		}
	}

	~Vector()
	{
		erase();
		// no need reset other members
	}

	// ======================================== Operations  =====================================================
	void push_back(const T& element)
	{
		// >>>>> case under 5 elements every new element will call OS for new memory
		if (m_size == m_capacity && m_size < 5 && m_capacity < 5)
		{
			int newSize{ m_size + 1 };
			T* oldArray = m_list;        // bind temp pointer to old array or (NULL for first push_back)
			m_list = NULL;               // redundant but just for readable 
			m_list = new T[newSize];     // get new part of memory for new objects

			// do deep copy
			for (int i = 0; i < m_size; i++)  // here m_size stil is with previous oldArray size
			{
				m_list[i] = oldArray[i];
			}
			m_list[newSize - 1] = element;

			if (oldArray != NULL)
			{
				delete[] oldArray;
			}
			m_size++;
			increaseCapacity();
		}
		else if (m_capacity > m_size)       // case when I have a capacity
		{
			m_list[m_size] = element;
			m_size++;
		}
		else if (m_size == m_capacity && m_size >= 5 && m_capacity >= 5)
		{
			increaseCapacity();
			m_list[m_size] = element;
			m_size++;
		}
	}

	void resize(const int& newSizeAndCapacity)   // after resize pushback must work after resized elements ! 
	{

		T* oldArray = m_list;
		m_list = NULL;
		m_list = new T[newSizeAndCapacity];

		// do deep copy if have old array
		if (oldArray != NULL)
		{
			for (int i = 0; i < newSizeAndCapacity; i++)
			{
				m_list[i] = oldArray[i];

			}
			delete[] oldArray;
		}

		m_size = newSizeAndCapacity;
		m_capacity = newSizeAndCapacity;



	}

	void erase()
	{
		delete[] m_list;
		m_size = 0;
		m_capacity = 0;
		needForExtend = startExtendFrame;
	}



	// ================================================= Element access ======================================================
	T& operator[] (const size_t& index) { return m_list[index]; }
	T& first() { return m_list[0]; }           // reference to the first element 
	T& back() { return m_list[m_size - 1]; }  // Reference to the last element. 

	// =================================================== Iterators  ==================================================
	// T::iterator begin() { if (m_list != NULL) { return m_list[0]; } return NULL; }        // ask about it
	// T::iterator end()   { if (m_list != NULL) { return m_list[m_size-1]; } return NULL; } 


	// =================================================== Capacity ==================================================
	size_t size()     const { return m_size; }
	size_t capacity() const { return m_capacity; }
	bool empty()      const { return m_list == NULL; }


	// ================================================== Modifiers  ==================================================
	void pop_back() { delete m_list[m_size - 1]; m_size--; }

private:

	void increaseCapacity()  // m_size > m_capacity by 1
	{
		if (m_size < 5)
		{
			needForExtend--;
		}
		if (m_size < 5 && m_capacity < 5)
		{
			if (needForExtend == 0)    // when this functions is called over certain times make my capacity more and new posible request for capacity
			{
				m_capacity = m_capacity * incrementStep;
				needForExtend = startExtendFrame; // set again default use that only in first range until 4 elements

				T* oldArray = m_list;        // bind temp pointer to old array or (NULL for first push_back)
				m_list = NULL;               // redundant but just for readable 
				m_list = new T[m_capacity];     // get new part of memory for new objects

				// do deep copy
				for (int i = 0; i < m_size; i++)  // here m_size stil is with previous oldArray size
				{
					m_list[i] = oldArray[i];
				}

				delete[] oldArray;
			}
			else
			{
				m_capacity++;
			}
		}
		else
		{
			m_capacity = m_capacity * incrementStep;

			T* oldArray = m_list;             // bind temp pointer to old array or (NULL for first push_back)
			m_list = NULL;                    // redundant but just for readable 
			m_list = new T[m_capacity];       // get new part of memory for new objects

			// do deep copy
			for (int i = 0; i < m_size; i++)  // here m_size stil is with previous oldArray size
			{
				m_list[i] = oldArray[i];
			}

			delete[] oldArray;
		}
	}

	int needForExtend{ startExtendFrame };
	int m_size;                                        // question signed / unsigned and sizeof
	int m_capacity;
	T* m_list = NULL;

};





#endif // !VECTOR_H

