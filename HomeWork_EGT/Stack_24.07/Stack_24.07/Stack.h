#ifndef STACK_H
#define STACK_H
#include <iostream>

#define default_start_capacity 50

/*
	Simple action. Adapter, good for class helper.
	
	*   advantages:
	-   Fast action push and pop elements - no memory and time constant(1)
	-   Swap two stack objects - no memory and time constant(1) 

	*   disadvantages:
	-   Fixed size
*/


class Stack
{
public:
	Stack();
	//
	Stack(const Stack& other);
	Stack& operator= (const Stack& other);
	~Stack();
	//

	// Element access
	int& top();
	
	// Capacity 
	size_t size()const { return static_cast<size_t>(m_size); }
	bool empty() const { return (m_size == 0); }
	// Modifiers 
	void push(const int& element);
	void pop(); // no return element just remove top element  ( if that container is template and object will be user defined class !! not OK ) 
	void swap(Stack& right);
private:
	void erase(); // at real Stack( data structure ) no have erase function, because that this function will be private

	int* m_begin;
	int* m_end;
	unsigned int m_size; // 4 byte unsigned int	0 to 4 294 967 295
};


#endif // !STACK_H
