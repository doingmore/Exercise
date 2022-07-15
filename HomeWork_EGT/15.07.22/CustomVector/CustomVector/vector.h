#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <string>
#include <sstream>
#include <iterator>

#define incrementStep 2


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
		: m_size{other.m_size}
		, m_capacity{other.m_capacity}
	{
		m_list = new T[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_list[i] = other.m_list[i];
		}
	}

	~Vector()
	{
		erase();   // don't calling virtual functions from constructor or destructor , but other functions ??? 
	}

	// ======================================== Operations  =====================================================
	void push_back(const T& element)
	{
		// >>>>> case under 5 elements every new element will call OS for new memory
		if (m_size == m_capacity && m_size < 4 && m_capacity < 4)
		{
			increaseCapacity();
			m_list[m_size] = element;
			m_size++;                      // m_size++ must be last line 
		}
		else if (m_size == m_capacity && m_size >= 4 && m_capacity >= 4)  // case when I reach the capacity of vector
		{
			increaseCapacity();
			m_list[m_size] = element;
			m_size++;                       // m_size++ must be last line 
		}
		else if (m_capacity > m_size)       // case when I have a capacity -> fast
		{
			m_list[m_size] = element;
			m_size++;                      // m_size++ must be last line 
		} 
	}
	void pop_back()                        // can will be more performance  
	{
		T* oldArray = m_list;
		m_list = NULL;
		m_list = new T[m_capacity];

		for (int i = 0; i < m_size-1; i++)
		{
			m_list[i] = oldArray[i];
		}
		delete[] oldArray;
	}


	// ================================================= Element access ======================================================
	T& operator[] (const size_t& index) 
	{
		if (index < 0 && index > m_size)
		{
			std::cout << "EXCEPTION" << '\n';
			throw _EXCEPTION_;
		}
		return m_list[index]; 
	}
	T& first()                          { return m_list[0]; }           // reference to the first element 
	T& back()                           { return m_list[m_size - 1]; }  // Reference to the last element. 
	T& at(const size_t& index)          
	{
		if (index < 0 && index > m_size)
		{
			std::cout << "EXCEPTION" << '\n';
			throw _EXCEPTION_;
		}
		return m_list[index]; 
	}

	// =================================================== Iterators  ==================================================
	// T::iterator begin() { if (m_list != NULL) { return m_list[0]; } return NULL; }                                // ask about it
	// T::iterator end()   { if (m_list != NULL) { return m_list[m_size-1]; } return NULL; } 
		

	// =================================================== Capacity ==================================================
	size_t size()     const { return m_size; }
	size_t capacity() const { return m_capacity; }
	bool   empty()    const {  return m_list == NULL; }
	void   reserve(const size_t& newCapacity)  //Increase the capacity of the vector the total number of elements that the vector can hold without requiring reallocation. use for performance
	{
		if (newCapacity < m_size)   
		{
			resize(newCapacity);
		}
		else
		{
			T* oldArray = m_list;
			m_list = NULL;
			m_list = new T[newCapacity];

			// do copy if old array have some allocate memory
			if (oldArray != NULL)
			{
				for (int i = 0; i < m_size; i++)    //  attention! copy only elements until m_size 
				{
					m_list[i] = oldArray[i];
				}
				delete[] oldArray;
			}

			m_capacity = newCapacity;
		}
	}

	// ================================================== Modifiers  ==================================================
	void resize(const int& newSizeAndCapacity)   // after resize pushback must work after resized elements ! 
	{
		T* oldArray = m_list;
		m_list = NULL;
		m_list = new T[newSizeAndCapacity];

		// do copy if old array have some allocate memory
		if (oldArray != NULL)
		{
			for (int i = 0; i < newSizeAndCapacity; i++)    //  attention! copy only elements until newSizeAndCapacity
			{
				m_list[i] = oldArray[i];
			}
			delete[] oldArray;
		}

		m_capacity = newSizeAndCapacity;
		m_size = newSizeAndCapacity;

	}
	void erase()
	{
		m_size = 0;
		m_capacity = 0;
		delete[] m_list;
		m_list = NULL;
	}
	

private:
	void increaseCapacity()  // m_size > m_capacity by 1
	{
		if (m_size < 4)                                       // first case 
		{
			int newSize{ m_size + 1 };
			T* oldArray = m_list;
			m_list = NULL;

			m_list = new T[newSize];
			for (int i = 0; i < m_size; i++)
			{
				m_list[i] = oldArray[i];
			}

			if (oldArray != NULL)                           // only for first element 
			{
				delete[] oldArray;
			}

			m_capacity++;
		} 
		else if (m_size >= 4 && m_capacity >= 4)             // second case
		{
			m_capacity = m_capacity * incrementStep;

			T* oldArray = m_list;
			m_list = NULL;

			m_list = new T[m_capacity];                  // this time I increase new array with size on new capacity !
			for (int i = 0; i < m_size; i++)
			{
				m_list[i] = oldArray[i];
			}

			delete[] oldArray;
			
		}
	}

	int m_size;                                        // question signed / unsigned and sizeof
	int m_capacity;
	T*  m_list = NULL;
	
};





#endif // !VECTOR_H

