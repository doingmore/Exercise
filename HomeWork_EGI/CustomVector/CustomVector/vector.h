#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <string>
#include <sstream>


template<typename T>
class Vector
{
private:
	T** m_list;
	size_t m_capacity;
	size_t m_size;
protected:

	void make_one_position()
	{
		T** temporary = m_list;
		m_list = new T * [m_size]; // m_size already with new size

		for (size_t i = 0; i < m_size - 1; i++)
		{
			m_list[i] = temporary[i];
		}
		delete[] temporary;
		temporary = NULL;
	}

	bool isEmpty() const { if (m_size == 0) { return true; }return false; }



public:
	Vector() : m_capacity{ 0 }, m_size{ 0 }
	{
		m_list = NULL;
		std::cout << "The constructor has been executed" << '\n';
	}
	// Operations 
	void push_back(T public_object)
	{
		m_size++;
		if (m_capacity <= m_size)
		{
			m_capacity++;
		}
		make_one_position();

		T* newObject = new T;
		*newObject = public_object;

		m_list[m_size - 1] = newObject;
	}
	void erase()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete m_list[i];
		}
		delete[] m_list;
		m_list = NULL;
		m_size = 0;
		m_capacity = 0;
	}
	void pop_back()
	{
		delete m_list[m_size - 1];
		m_size--;
	}
	void resize(const size_t& new_cap)
	{
		assert(new_cap >= 0 && new_cap > m_size);
		if (m_capacity > new_cap)
		{

		}
		else if (m_capacity < new_cap)
		{
			
		}
		// else they are = do nothing
	}






	//Capacity 
	size_t capacity() const             { return m_capacity; }
	size_t size()     const             { return m_size; }
	bool empty()      const             { if (m_size == 0) { return true; } return false; }
	size_t max_size() const             { return m_size; } // Return value maximum number of elements.
	void reserve (const size_t& new_cap);                  // implemented down after end of the class  just that method is litlle long...
	// reserve total number of elements that the vector can hold without requiring reallocation
	// posible exeed with no exeption



	// Element access 
	T& operator[] (const size_t& index) { assert(index >= 0 && index <= m_size); return *m_list[index]; }
	T& first()                          { return *( m_list[0] ); } // reference to the first element 
	T& back()                           { return *( m_list[m_size - 1] ); }  // Reference to the last element. 
	//T& at()       (const size_t& index) { assert(index >= 0 && index <= m_size); return *m_list[index]; } //  PROBLEM !



	// rule of three
	Vector(const Vector& other) : m_capacity{ other.m_capacity }, m_size{ other.m_size }
	{
		m_list = new T * [m_size]; // question for "new T*[]{};"   ???????
		for (size_t i = 0; i < m_size; i++)
		{
			// step 1
			std::stringstream stream;
			stream << *other.m_list[i];
			// step 2
			std::string for_istream;
			std::string input;
			while (stream >> input)
			{
				for_istream += input;
				for_istream += ' ';
			}
			// step 3
			std::istringstream in(for_istream);


			// step 4
			T* object = new T;
			in >> (*object);
			m_list[i] = object;
		}
		std::cout << "The copy constructor has been executed" << '\n';
	}
	Vector& operator= (const Vector& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (m_list != NULL)
		{
			for (size_t i = 0; i < m_size; i++)
			{
				delete m_list[i];
			}
			delete[] m_list;
			m_list = NULL;
		}

		m_capacity = other.m_capacity;
		m_size = other.m_size;

		m_list = new T * [m_size]; // question for "new T*[]{};"   ???????
		for (size_t i = 0; i < m_size; i++)
		{
			// step 1
			std::stringstream stream;
			stream << *other.m_list[i];
			
			// step 2
			std::string for_istream;
			std::string input;
			while (stream >> input )
			{
				for_istream += input;
				for_istream += ' ';
			}
			// step 3
			std::istringstream in(for_istream);
			

			// step 4
			T* object = new T;
			in>>(* object);
			m_list[i] = object;
		}

		std::cout << "The assignment operator has been executed" << '\n';

		return *this;
	}
	~Vector()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			delete m_list[i];
		}
		delete[] m_list;
		m_list = NULL;
		std::cout << "The destructor has been executed" << '\n';
	}
};


template<typename T>
inline void Vector<T>::reserve(const size_t& new_cap)
{
	assert(new_cap >= 0 && new_cap >= m_size);
	if (m_capacity < new_cap)
	{
		m_capacity = new_cap;
	}
	else if (m_capacity > new_cap)
	{
		if (m_size > new_cap)
		{
			std::cout << "Error with new capacity, LOSE DATA" << '\n';
			throw _EXCEPTION_;
		}
		m_capacity=new_cap ;
	}
	// else null statement , 
}





#endif // !VECTOR_H

