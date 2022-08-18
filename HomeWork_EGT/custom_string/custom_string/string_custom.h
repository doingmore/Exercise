#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H
#include "cstddef" // need for NULL
#include <sstream>

#define incrementStep 2
#define defaultCapacity 15
#define firstIN 0

class string
{
public:
	string();
	string(const char* literalArray);
	//
	string(const string& other);
	string& operator= (const string& other);
	~string();
	string(string&& other);
	string& operator= (string&& other);
	// ===================== Element access =======================
	char& at(const size_t& index); // with bounds checking 
	char& operator[] (const size_t& index); // no bounds checking, if index > m_size udefined behavior
	char& operator[] (const size_t& index) const;
	char& front();
	char& back();
	char* data();
	// ===================== Element access =======================
	// 
	// ===================== Capacity =============================
	const size_t& size() const;
	const size_t& capacity() const;
	bool empty() const;
	size_t max_size() const;
	void reserve(const size_t& newCapacity);
	// ===================== Capacity =============================
	//
	// ===================== Operations ===========================
	void clear();
	void resize(const size_t& newSize);

	// ===================== Operations ===========================
	//
	// ===================== Overloaded Operators For string class =================
	friend std::ostream& operator<< (std::ostream& stream, const string& object);
	friend std::istream& operator>> (std::istream& stream, const string& object);

	string& operator+= (const string& object);

	// ===================== Overloaded Operators =================
	//
	// ===================== Iterator =============================

	class iterator
	{
	public:
		iterator();
		iterator(char* address);

		char& operator* ();

		void operator++ ();
		void operator++ (int);

		void operator-- ();
		void operator-- (int);
	private:
		char* it_ptr;
	};

	iterator begin() // return object of type iterator pointed to first char 
	{
		return &m_data[0]; // return by value create iterator object at return statment 
	}
	iterator end()
	{
		return &m_data[m_size - 1];
	}

	// ===================== Iterator =============================

private:

	void deallocateMemory();
	size_t getSizeFromLiteralCharPTR(const char* literalArray);  // get length from char* to array posible only with this way


	size_t m_capacity;
	size_t m_size;
	char* m_data;
};


#endif // !CUSTOM_STRING_H
