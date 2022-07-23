#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
// * Our goal is to add and remove elements without copying all elements
// 
// * Dynamically allocated elements little slow, but. I don't know how many will be elements during runtime.
// Creating too many objects on the stack will increase the chances for stack overflow.
// Base on that I would prefer work with heap and my container will eligible on rule of 3.
// 
// * (for that example we work with int) when we remove element we remove first element with that value
// In other case I'll need for index and I'll work with member m_size.... Or all elements must be unique
// 
// * Get first or last element  - complexity constant(1) in all cases
// * Add element at begin or end - complexity constant(1) in all cases (but use heap)
// * Find element - complexity (N)
// * Add element after other - complexity (N) 

class LinkedList
{	
class Node;
public:
	LinkedList();                 
	LinkedList(const int& value);
	//
	LinkedList(const LinkedList& other);
	LinkedList& operator= (const LinkedList& other);
	~LinkedList();
	//

	int& find(const int& element);
	void insert_after_element(const int& elementAfter, const int& newValue);
	void delete_element(const int& element);
	Node* getHead() const { return head; }
	Node* getTail() const { return tail; }
	void erase();
	void add(const int& value); // at end
	void insert_at_begin(const int& newValue);
	void print() const;  
	bool isHere(const int& element) const;
private:
	
	class Node 
	{
	public:
		Node(const int& value) : m_value{ value }, next{ NULL }
		{}
		int& getRef() { return m_value; }
		int getValue() const { return m_value; }
		Node* getNext() { return next; }
		void setNext(Node* nextElement) { next = nextElement; }
	private:
		int m_value;
		Node* next;
	};
	Node* head;
	Node* tail;
};



#endif // !LINKED_LIST_H
