#include "List.h"
#include <iostream>

#define zero 0 

// -----------------------------------------------CLASS List----------------------------------------------- // 


List::List() : head{ NULL }, tail{ NULL }, size{ zero }
{
	std::cout << "Default List Constructor called" << '\n';
}


List::List(const List& other) : size(zero), head(nullptr), tail(nullptr)
{
	Node* temp = other.head;
	while (size != other.size)
	{
		add(temp->getValue());
		temp = temp->getNext();
	}
	std::cout << "Copy Constructor called" << '\n';
}

int List::first() const
{
	return head->getValue();
}


// Generates new dynamically allocated Nodes 
//Links the list

void List::add(int value)
{
	if (size > 0 && size != 1)
	{
		Node* ptr = new Node{ value, tail, nullptr };
		tail->setNext(ptr);
		tail = ptr;
	}
	else if (size == 1)
	{
		Node* ptr = new Node{ value, tail, nullptr };
		tail = ptr;
		head->setNext(ptr);
	}
	else
	{
		Node* ptr = new Node{ value, nullptr, nullptr };
		head = ptr;
		tail = ptr;
	}
	++size;

}
//Not used
void List::addAll(const List& other)
{
	head = other.head;
	tail = other.tail;
}

//Releases resources for the first Node in the list
void List::removeFirst()
{
	if (size == 1) {
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		this->size--;
	}
	else if (size > 1) {
		Node* toDelete = this->head;
		this->head = this->head->getNext();
		this->head->setPrev(nullptr);
		delete toDelete;
		this->size--;
	}

}

//Removes and releases resources for all Nodes in the list
//One by one
void List::removeAll()
{

	while (size != 0)
	{
		removeFirst();
	}

}

size_t List::getSize() const
{
	return size;
}

bool List::isEmpty() const
{
	return !(size > 0);
}

//Not used
List List::getReversed(List l)
{
	return l;
}

//Takes care for the output 
std::string List::toString() const
{
	std::string out;
	Node* tempHead = head;

	while (true)
	{
		if (tempHead != nullptr)
		{
			std::string temp = std::to_string(tempHead->getValue());
			temp.append(" ");
			tempHead = tempHead->getNext();
			out.append(temp);
		}
		else
		{
			break;
		}

	}
	return out;
}

//OPERATOR OVERLOAD Calls the add function
List& List::operator<<(const int& value)
{
	add(value);
	return *this;
}

//Not used
List& List:: operator<<(const List& other)
{
	return *this;
}

//ASSIGMENT OPERATOR - same as copy c-tor
List& List::operator=(const List& other)
{
	/*std::cout << "Ass opp List called" << std::endl;*/
	if (other.size == 0)
	{
		this->size = 0;
		head = nullptr;
		tail = nullptr;
		return *this;
	}
	size = 0;

	Node* temp = other.head;
	while (size != other.size)
	{
		add(temp->getValue());
		temp = temp->getNext();
	}


	return*this;
}

List::~List()
{
	/*std::cout << "Destructor List called" << std::endl;*/
	this->removeAll();

}


// -----------------------------------------------CLASS NODE----------------------------------------------- // 


List::Node::Node(int value, Node* prev, Node* next) : m_value{ value }, m_prev{ NULL }, m_next{NULL}
{
}

int List::Node::getValue() const
{
	return m_value;
}

void List::Node::setValue(int value)
{
	m_value = value;
}

List::Node* List::Node::getNext() const
{
	return m_next;
}

void List::Node::setNext(Node* next)
{
	m_next = next;
}

List::Node* List::Node::getPrev() const
{
	return m_prev;
}

void List::Node::setPrev(Node* prev)
{
	m_prev = prev;
}