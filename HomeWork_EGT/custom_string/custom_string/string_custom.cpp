#include "string_custom.h"
#include <iostream>
string::string()
	: m_capacity{ defaultCapacity }
    , m_size{ 0 }
{
	m_data = new char[defaultCapacity] {};
}

string::string(const char* literalArray)
	: m_capacity{ defaultCapacity }
{
	const size_t localSize{ getSizeFromLiteralCharPTR(literalArray) };

	while (localSize > m_capacity)
	{
		m_capacity *= incrementStep;
	}

	m_data = new char[m_capacity] {};
	m_size = localSize;

	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = literalArray[i];
	}
}
// ========================================== COPY and MOVE semantic =====================================================
string::string(const string& other)
	: m_capacity{ other.m_capacity }
	, m_size{ other.m_size }
{
	m_data = new char[m_capacity] {};
	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

string& string::operator= (const string& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (m_data)
	{
		this->deallocateMemory();
	}

	m_data = new char[other.m_capacity]{};   // MyClass * p2 = new (std::nothrow) MyClass; check alloc ??? 
	for (size_t i = 0; i < other.m_size; i++)
	{
		m_data[i] = other.m_data[i];
	}


	m_capacity = other.m_capacity;
	m_size = other.m_size;
	return *this;
}

string::~string()
{
	this->deallocateMemory();
}

string::string(string&& other)
	: m_capacity{ other.m_capacity }
	, m_size{ other.m_size }
	, m_data{ other.m_data }
{
	// transfer all members already done

	// define state on right operand
	// default state
	other.m_data = new char[defaultCapacity] {};
	other.m_capacity = defaultCapacity;
	other.m_size = 0;
}

string& string::operator= (string&& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (m_data)  // for deallocate memory from left operand
	{
		this->deallocateMemory();
	}


	// transfer all members
	this->m_capacity = other.m_capacity;
	this->m_size = other.m_size;
	m_data = other.m_data;

	// define state on right operand
	// default state
	other.m_data = new char[defaultCapacity] {};
	other.m_capacity = defaultCapacity;
	other.m_size = 0;

	return *this;
}
// ========================================== COPY and MOVE semantic =====================================================
// 
// ========================================== Private function =====================================================
void string::deallocateMemory()
{
	delete[] m_data;
	m_data = NULL;
}

size_t string::getSizeFromLiteralCharPTR(const char* literalArray)
{
	size_t answer{ 0 };
	int i{ 0 };
	while (literalArray[i] != '\0')
	{
		answer++;
		i++;
	}
	return answer;
}

// ========================================== Private function =====================================================
//
// ========================================== Element access =======================================================

char& string::at(const size_t& index)
{
	if (index >= m_size)
	{
		// something error handling
		std::cout<<"ERROR"<<'\n';
		return m_data[firstIN];
	}
	return m_data[index];
}


char& string::operator[] (const size_t& index)
{
	return m_data[index];
}

char& string::front() // need for error handling when use that function on object with size 0
{
	if (m_size == firstIN)
	{
		return m_data[firstIN];
	}
	return m_data[firstIN];
}

char& string::back() // need for error handling when use that function on object with size 0
{
	if (m_size == firstIN)
	{
		return m_data[firstIN];
	}
	return m_data[m_size-1];
}

char* string::data()
{
	return &m_data[firstIN]; // here will create char* 
}

// ========================================== Element access =======================================================
//
// ========================================== Capacity =============================================================
const size_t& string::size() const { return m_size; }

const size_t& string::capacity() const { return m_capacity; }

bool string::empty() const
{
	if (m_size > firstIN)
	{
		return true;
	}
	return false;
}

size_t string::max_size() const
{
	return static_cast<size_t>(UINT64_MAX);
}

void string::reserve(const size_t& newCapacity)
{
	if (newCapacity < m_capacity) // If new_cap is less than or equal to the current capacity(), there is no effect. 
	{
		return;
	}
	else
	{
		char* temp = m_data;
		m_capacity = newCapacity;
		m_data = new char[m_capacity] {};  // no error handling 
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = temp[i];
		}
		delete[] temp;
	}
}

// ========================================== Capacity =============================================================
//
// ========================================== Operations =============================================================

void string::clear() // not deallocate existing memory, only resset the character
{
	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i] = 0;
	}
	m_size = 0;
}

void string::resize(const size_t& newSize)
{
	if (m_capacity >= newSize) // no need touch m_capacity
	{
		if (m_size > newSize)
		{
			for (size_t i = newSize ; i < m_capacity; i++)
			{
				m_data[i] = 0;
			}
		}
		m_size = newSize;
	}
	else
	{
		while (m_capacity < newSize)
		{
			m_capacity *= incrementStep;
		}

		char* temp = m_data;
		m_data = new char[m_capacity] {};
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = temp[i];
		}
		delete[] temp;
		m_size = newSize;
	}
}




// ========================================== Operations =============================================================
//
// ========================================== Overloaded Operators ===================================================
std::ostream& operator<< (std::ostream& stream, const string& object)
{
	for (size_t i = 0; i < object.m_size; i++)
	{
		stream << object.m_data[i];
	}
	return stream;
}

std::istream& operator>> (std::istream& stream, const string& object)
{

	return stream;
}



// ========================================== Overloaded Operators ===================================================
//
// ========================================== Iterator class =========================================================


string::iterator::iterator()
	: it_ptr{ NULL }
{}

string::iterator::iterator(char* address)
	: it_ptr{ address }
{}

char& string::iterator::operator* () { return *it_ptr; }

void string::iterator::operator++ () { it_ptr++; }
void string::iterator::operator++ (int) { ++(*this); }

void string::iterator::operator-- () { it_ptr--; }
void string::iterator::operator-- (int) { --(*this); }

// ========================================== Iterator class =========================================================