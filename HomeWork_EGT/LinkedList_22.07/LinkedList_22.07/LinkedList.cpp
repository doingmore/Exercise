#include <iostream>

#include "LinkedList.h"


// these initializer lists are necessary for function add !!
LinkedList::LinkedList()
	:head{ NULL }
	,tail{ NULL }
{}

LinkedList::LinkedList(const int& value) 
	:head{ NULL }
	,tail{ NULL }
{
	add(value);
}

LinkedList::LinkedList(const LinkedList& other) : head{ NULL }, tail{ NULL }  
{
	Node* it = other.head;
	while (it != NULL)
	{
		this->add(it->getValue());
		it = it->getNext();
	}
	std::cout << "The copy CTR been executed!" << '\n';
}

LinkedList& LinkedList::operator= (const LinkedList& other)
{
	if (this->head == other.head)  // this &head == other &head
	{
		return *this;
	}
	// self-assignment guard but also work if no need assignment
	//  between this two object, because they are default

	if (head != NULL)
	{
		this->erase();
	}

	Node* it = other.head;
	while (it != NULL)
	{
		this->add(it->getValue());
		it = it->getNext();
	}
	std::cout << "The assignment operator been executed!" << '\n';
	return *this;
}

LinkedList::~LinkedList()
{
	this->erase();
}

int& LinkedList::find(const int& element)
{
	Node* it = head;
	while (it != NULL)
	{
		if (it->getValue() == element)
		{
			return it->getRef();
		}
		it = it->getNext();
	}
	return tail->getRef();
}

void LinkedList::insert_after_element(const int& elementAfter, const int& newValue)
{
	bool flagAdded = true;
	Node* it = head;
	while (it != NULL)
	{
		if (elementAfter == it->getValue())
		{
			Node* newElement = new Node{ newValue };
			newElement->setNext(it->getNext());
			it->setNext(newElement);
			flagAdded = false;
			break;
		}
		it = it->getNext();
	}
	if (flagAdded) // In case when we have a default container add element at head. Or wrong "elementAfter" just add element at tail.
	{
		add(newValue);
	}
}

void LinkedList::delete_element(const int& element)
{
	Node* it = head;
	Node* del = NULL;
	while (it != NULL)
	{//                next element after "it" is our element for delete
		if (element == it->getNext()->getValue())
		{
			del = it->getNext();
			it->setNext(del->getNext()); // jump over element del
			it = NULL;
			break;
		}
		it = it->getNext();
	}
	delete del;
}

void LinkedList::erase()
{
	Node* it = head;
	head = NULL;
	while (it != NULL)
	{
		Node* del = it;
		it = it->getNext();
		delete del;
	}
	tail = NULL;
}

void LinkedList::add(const int& value)
{
	if (head == NULL)
	{
		head = new Node{ value };   // Node CTR set next ptr to NULL
		// default tail to NULL
	}
	else if (tail == NULL)
	{
		tail = new Node{ value }; 
		head->setNext(tail);    
	}
	else
	{
		Node* newElement = new Node{ value };
		tail->setNext(newElement);
		// in that moment my NewElement is the real tail;
		// now I'll bind tail pointer to new element;
		tail = newElement;
	}
}

void LinkedList::insert_at_begin(const int& newValue)
{
	Node* newElement = new Node{ newValue };
	newElement->setNext(head);
	head = newElement;
}

void LinkedList::print() const
{
	Node* it = head;
	while (it != NULL)
	{
		std::cout << it->getValue() << ' ';
		it = it->getNext();
	}
	std::cout << '\n';
}


bool LinkedList::isHere(const int& element) const
{
	Node* it = head;
	while (it != NULL)
	{
		if (element == it->getValue())
		{
			return true;
		}
		it = it->getNext();
	}
	return false;
}
