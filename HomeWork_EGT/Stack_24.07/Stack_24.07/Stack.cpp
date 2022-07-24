#include "Stack.h"

Stack::Stack() 
	: m_size{ 0 }
	, m_end{ NULL }
{
	m_begin = new int[default_start_capacity] {};
}

Stack::Stack(const Stack& other)
	: m_size{ other.m_size }
{
	m_begin = new int[default_start_capacity] {};
	if (other.m_size > 0) // when other object is default no need deep copy
	{
		for (unsigned int i = 0; i < m_size; i++)  // until m_size no capacity !!
		{
			m_begin[i] = other.m_begin[i];
		}
		m_end = &m_begin[m_size - 1];   // &m_begin[m_size - 1]     bind to last active element from all memory chunck
	}
	else
	{
		m_end = NULL;
	}
}

Stack& Stack::operator= (const Stack& other)
{
	if (this == &other)
	{
		return *this;
	}

	// every time default object hold memory data 
	// after erase() function end pointer set to NULL , important only in case when assignment from default object !
	this->erase();

	m_size = other.m_size;

	m_begin = new int[default_start_capacity] {};
	if (other.m_size > 0) // when other object is default no need deep copy
	{
		for (unsigned int i = 0; i < m_size; i++)  // until m_size no capacity !!
		{
			m_begin[i] = other.m_begin[i];
		}
		m_end = &m_begin[m_size - 1];   // &m_begin[m_size - 1]     bind to last active element from all memory chunck
	}
	
	return *this;
}

Stack::~Stack()
{
	erase();
}



void Stack::erase() // at real Stack( data structure ) no have erase function, because that this function will be private
{
	m_end = NULL;  // first unbind second pointer "end"
	delete[] m_begin;
	m_size = 0;
}

void Stack::push(const int& element)
{
	if (m_size+1 > default_start_capacity) // OVERFLOW
	{
		std::cout << "ERROR stack overflow";
		erase();                    // before throw
		throw _EXCEPTION_;
	}
	else 
	{
		m_begin[m_size] = element; 
		m_size++;
		m_end = &m_begin[m_size-1];  // need to actualization "m_end" pointer every time when we push new element
	}
}
void Stack::pop() // no return element just remove top element
{                                   // no reduce capacity 
	if (m_size > 0)
	{
		*m_end = 0;
		m_size--;
		m_end = &m_begin[m_size - 1]; // actualization end
	}
}

void Stack::swap (Stack& right)  //  no reverse stack just swap two diferent stack of that type !!!
{
	int* temp_begin{this->m_begin};
	int* temp_end{this->m_end};
	unsigned int temp_size{this->m_size};

	this->m_begin = right.m_begin;
	this->m_end = right.m_end;
	this->m_size = right.m_size;

	right.m_begin = temp_begin;
	right.m_end = temp_end;
	right.m_size = temp_size;
}

int& Stack::top()
{
	return *m_end;
}