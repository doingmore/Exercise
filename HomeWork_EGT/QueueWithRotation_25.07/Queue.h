#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

/*
	The queue pushes the elements on the back of the underlying container and pops them from the front. 
	Simple action good for class helper. 

	benefits:  
	* direct access to begin and end elements - const (1)
	* push elements without copy all content - time const (1) but with call OS for heap memory
	 
	// aditional 
	* rotation all content at queue - const (1) !!
	* possibility to implement all functions from linked list

*/


class Queue
{
	class Element;
public:
	Queue();
	//
	Queue(const Queue& other);
	Queue& operator= (const Queue& other);
	~Queue();
	//

	// Element access 
	int& front();
	int& back();

	// Capacity 
	size_t size() const;
	bool empty() const;

	// Modifiers 
	void push(const int& value);
	void pop(); // Removes an element from the front of the queue.
	void swap(Queue& other);


	// custom functionality rotation all content
	void rotation();

private:
	void erase()
	{
		m_end = NULL;

		Element* del = m_begin;
		while (m_begin != NULL)
		{
			m_begin = m_begin->getNext();
			delete del;
			del = m_begin;
		}
	}

	class Element
	{
	public:
		Element(const int& value)
			: m_value{value}
			, m_next{NULL}
			, m_previous{NULL}
		{}
		Element* getNext() { return m_next; }
		Element* getPrevious() { return m_previous; }
		int& getValue() { return m_value; }

		void setNext(Element* next) { m_next = next; }
		void setPrevious(Element* previous) { m_previous = previous; }
		void setValue(const int& value) { m_value = value; }
	private:
		int m_value;
		Element* m_next;
		Element* m_previous;
	};

	bool reverse_mode;
	Element* m_begin;
	Element* m_end;
	unsigned int m_size;
};


#endif // !QUEUE_H
