#ifndef VECTOR_H
#define VECTOR_H

#define increaseCapacityStep 2

template<typename T>
class Vector
{
public:
	Vector()
		: m_data{NULL}
		, m_size{0}
		, m_capacity{0}
	{}
	// Rule of three
	Vector(const Vector& other)
		: m_size{other.m_size}
		, m_capacity{other.m_capacity}
	{
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
	}
	Vector& operator= (const Vector& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (m_data) 
		{
			delete[] m_data;
			m_data = NULL;
		}

		m_size= other.m_size ;
		m_capacity= other.m_capacity ;
		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}

		return *this;
	}
	~Vector()
	{
		delete[] m_data;
	}
	// Rule of three
	// Move semantics
	Vector( Vector&& other)
		: m_size{ other.m_size }
		, m_capacity{ other.m_capacity }
	{
		other.m_size = 0;
		other.m_capacity = 0;

		m_data = other.m_data;
		other.m_data = NULL;
		 
	}
	Vector& operator= ( Vector&& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (m_data)
		{
			delete[] m_data;
		}

		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_data = other.m_data;

		other.m_size = 0;
		other.m_capacity = 0;
		other.m_data = NULL;

		return *this;
	}
	// Move semantics

	void push_back(const T& object)
	{
		if (m_data==NULL)
		{
			m_data = new T[1 * increaseCapacityStep];
			*m_data = object;
			m_size++;
			m_capacity=1* increaseCapacityStep;
		}
		else if(m_size < m_capacity)
		{
			m_data[m_size] = object; // here add new element 
			m_size++;
		}
		else if (m_size == m_capacity)
		{
			T* newData = new T[m_capacity * increaseCapacityStep];
			T* oldData = m_data;
			m_data = newData;

			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = oldData[i];
			}

			delete[] oldData;

			m_data[m_size] = object; // here add new element 

			m_size++;
			m_capacity = m_capacity * increaseCapacityStep;
		}
		else
		{
			std::cout << "Error with push_back" << '\n';
			throw _EXCEPTION_;
		}
	}

	const size_t& size() const { return m_size; }
	const size_t& capacity() const { return m_capacity; }


	// Iterators 
	
	class iterator
	{
		T* it_ptr;
		public:

		iterator(): it_ptr { NULL } {};
		iterator( T* object) 
		{
			it_ptr = object;
		}

		iterator& operator= (const iterator& object)
		{
			it_ptr = object.it_ptr;
			return *this;
		}

		iterator& operator++ () { it_ptr++; return *this; }

		iterator operator++ (int) { ++(*this); return *this; }

		T* operator-> () { return it_ptr; }
		T& operator* () const { return *it_ptr; }
	};


	iterator begin() { return iterator{ &m_data[0] }; }

	iterator end() { return iterator{ &m_data[m_size-1] }; }
	// Iterators 


	// Element access 
	T& front()
	{
		if (m_data)
		{
			return m_data[0];
		}
		return NULL;
	}
	T& back()
	{
		if (m_data)
		{
			return m_data[m_size-1];
		}
		return NULL;
	}
	T& at(const int& index)
	{
		if (m_data)
		{
			return m_data[index];
		}
		return *m_data;
	}
	T& operator[] (const int& index)
	{
		if (m_data)
		{
			if (index >= 0 && index < m_size)
			{
				return m_data[index];
			}
		}
		return *m_data;
	}
	// Element access 
private:

	T* m_data;
	size_t m_size;
	size_t m_capacity;
};


#endif // !VECTOR_H
