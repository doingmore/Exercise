#include "List.h"
#include <iostream>
#include <string>
#include <vector>

// ============================== nested class Node ==================================

List::Node::Node(int value, Node* prev, Node* next) : value{ value }, prev{ NULL }, next{ NULL }
{}

int List::Node::getValue() const
{
	return value;
}

void List::Node::setValue(int value)
{
	this->value = value;
}

List::Node* List::Node::getNext() const
{
	return next;
}

void List::Node::setNext(Node* next)
{
	this->next = next;
}

List::Node* List::Node::getPrev() const
{
	return prev;
}

void List::Node::setPrev(Node* prev)
{
	this->prev = prev;
}


// ============================== nested class Node ==================================
// ================================== class List =====================================

List::List() : head{ NULL }, tail{ NULL }, size{ 0 }
{}
List::List(const List& other)
{
	if (other.head != NULL && other.size != 0)
	{
		size = other.size;
		Node* operate = other.head;
		for (size_t i = 0; i < size; i++)
		{
			if (i == 0)
			{
				head = new Node{ operate->getValue(),NULL,NULL };
			}
			else if (i == 1)
			{
				tail = new Node{ operate->getValue(),NULL,NULL };
				tail->setPrev(head);
				head->setNext(tail);
			}
			else
			{
				Node* newElement = new Node{ operate->getValue(),NULL,NULL };
				tail->setNext(newElement);
				newElement->setPrev(tail);
				tail = tail->getNext();
				newElement = NULL;
			}
			operate = operate->getNext();
		}
		std::cout << "The copy CTR been executed!" << '\n';
	}
	else
	{
		size = 0;
		head = NULL;
		tail = NULL;
	}
}
List& List::operator=(const List& other)
{
	if (this == &other) // head
	{
		return *this;
	}
	if (this->head != NULL)
	{
		this->erase();
	}

	this->size = other.size;

	Node* operate = other.head;
	for (size_t i = 0; i < this->size; i++)
	{
		if (i == 0)
		{
			this->head = new Node{ operate->getValue(),NULL,NULL };
		}
		else if (i == 1)
		{
			this->tail = new Node{ operate->getValue(),NULL,NULL };
			this->tail->setPrev(head);
			this->head->setNext(tail);
		}
		else
		{
			Node* newElement = new Node{ operate->getValue(),NULL,NULL };
			this->tail->setNext(newElement);
			newElement->setPrev(tail);
			this->tail = this->tail->getNext();
			newElement = NULL;
		}
		operate = operate->getNext();
	}

	std::cout << "The assignment operator been executed!" << '\n';

	return *this;
}
void List::erase()
{
	Node* temporary = NULL;
	for (size_t i = size; i > 0; i--)
	{
		temporary = this->tail->getPrev();
		delete this->tail;
		this->tail = temporary;
	}

	this->size = 0;
	this->head = NULL;
	this->tail = NULL;
}
std::string List::toString() const
{
	std::string answer;
	Node* iterate = NULL;
	iterate = this->head;
	for (size_t i = 0; i < this->size; i++)
	{
		answer += std::to_string(iterate->getValue());
		answer += " ";
		iterate = iterate->getNext();
	}
	iterate = NULL;
	return answer;
}
List& List::operator<<(const int& value)
{
	if (this->isEmpty())
	{
		head = new Node{ value,NULL,NULL };
		size++;
	}
	else if (head->getNext() == NULL)
	{
		tail = new Node{ value,NULL,NULL };
		head->setNext(tail);
		tail->setPrev(head);
		size++;
	}
	else
	{
		tail->setNext(new Node{ value,NULL,NULL });
		Node* temporarity = tail;
		tail = tail->getNext();
		tail->setPrev(temporarity);
		size++;
		temporarity = NULL;
	}


	return *this;
}
int List::first() const
{
	return head->getValue();
}
void List::add(int value)
{
	if (this->head == NULL) // if first element
	{
		this->head = new Node{ value,NULL,NULL };
	}
	else if (this->head->getNext() == NULL) // if second element
	{
		this->tail = new Node{ value,NULL,NULL };
		this->head->setNext(this->tail);
		this->tail->setPrev(this->head);
	}
	else // other cases
	{
		Node* operate = new Node{ value,NULL,NULL };
		this->tail->setNext(operate);
		operate->setPrev(this->tail);
		operate = NULL;
		this->tail = this->tail->getNext();
	}
	this->size++;
}
void List::removeFirst()
{
	if (this->head == NULL)
	{
		// do nothing   
		// can throw exeption, but not neccessery in this case
	}
	else if (this->head->getNext() == NULL) // if hold only one element
	{
		delete this->head;
		this->head = NULL;
		this->size = 0;
	}
	else
	{
		Node* operate = this->head->getNext();
		delete this->head;
		operate->setPrev(NULL);
		this->head = operate;
		operate = NULL;
		if (this->head == this->tail)
		{
			this->tail = NULL;
		}
		this->size--;
	}
}
List::~List()
{
	Node* temporary = NULL;
	for (size_t i = size; i > 0; i--)
	{
		temporary = tail->getPrev();
		delete tail;
		tail = temporary;
	}
	delete temporary;
	std::cout << "The destructor been executed!" << '\n';
}
size_t List::getSize() const
{
	return this->size;
}
bool List::isEmpty() const
{
	if (head != NULL)
	{
		return false;
	}
	return true;
}


// ================================== class List =====================================

