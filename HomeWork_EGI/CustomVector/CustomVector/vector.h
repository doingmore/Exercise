
#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>


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




	// ready for test
	size_t capacity()const;
	size_t size()const;
	T& operator[] (const size_t& index) { return *m_list[index]; }




	Vector(const Vector& other) : m_capacity{ other.m_capacity }, m_size{ other.m_size }
	{
		m_list = new T * [m_size]; // question for "new T*[]{};"   ???????
		for (size_t i = 0; i < m_size; i++)
		{
			T* object = new T;
			*object = *other.m_list[i];
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
			T* object = new T;
			*object = *other.m_list[i];
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
inline size_t Vector<T>::capacity() const { return m_capacity; }


template<typename T>
inline size_t Vector<T>::size() const { return m_size; }







#endif // !VECTOR_H

