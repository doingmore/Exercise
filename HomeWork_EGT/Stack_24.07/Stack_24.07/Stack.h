#ifndef STACK_H
#define STACK_H
#include <iostream>

#define default_start_capacity 50

/*
	The class template acts as a wrapper to the underlying container - only a specific set of functions is provided.
	The stack pushes and pops the element from top of the stack.

	*   Goals:
	*   Fast push and pop elements - no memory and time constant(1)
	*   Swap two stack - no memory and time constant(1) 



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
	size_t size()const { return m_size; }
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
