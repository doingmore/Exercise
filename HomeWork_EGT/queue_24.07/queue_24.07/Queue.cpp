#include "Queue.h"


Queue::Queue()
	: m_begin{ NULL }
	, m_end{ NULL }
	, m_size{0}
{}

Queue::Queue(const Queue& other)
	: m_begin{ NULL }
	, m_end{ NULL }
{
	if (other.m_size > 0)  // else no need copy !
	{
		Element* it = other.m_begin;
		while (it != NULL)
		{
			this->push(it->getValue() );
			it = it->getNext();
		}
	}
	else
	{
		m_size = 0;
	}
}

Queue& Queue::operator= (const Queue& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (this->m_begin != NULL)
	{
		this->erase();
	}

	if (other.m_size > 0)  // else no need copy !
	{
		Element* it = other.m_begin;
		while (it != NULL)
		{
			this->push(it->getValue());
			it = it->getNext();
		}
	}
	else
	{
		m_size = 0;
	}


	return *this;
}

Queue::~Queue()
{
	erase();
}

int& Queue::front() { return m_begin->getValue(); }
int& Queue::back() { return m_end->getValue(); }

size_t Queue::size() const { return static_cast<size_t>(m_size); }
bool Queue::empty() const { return m_size == 0; }


void Queue::push(const int& value)
{
	Element* newElement = new Element{ value };

	if (m_begin == NULL)
	{
		m_begin = newElement;
	}
	else if (m_begin != NULL && m_end == NULL)
	{
		m_end = newElement;

		m_begin->setNext(m_end);
		m_end->setPrevious(m_begin);
	}
	else
	{
		m_end->setNext(newElement);
		newElement->setPrevious(m_end);
		// newElement->setNext(NULL); default next element on newElement is NULL
		// now real end is "newElement"

		m_end = newElement;
	}
	m_size++;
}

void Queue::pop()
{
	if (m_begin != NULL) // if do pop on default or empty container 
	{
		Element* del = m_begin;

		m_begin = m_begin->getNext();

		if (m_begin == NULL)  // case when pop last element , on this line m_begin will be NULL 
		{
			m_end = NULL;
		}
		else
		{
			m_begin->setPrevious(NULL);
		}

		delete del;
		m_size--;
	}
	// else do nothing 
}

void Queue::swap(Queue& other)
{
	Element* temp_begin=this->m_begin;
	Element* temp_end=this->m_end;
	unsigned int temp_size=this->m_size;

	this->m_begin = other.m_begin;
	this->m_end = other.m_end;
	this->m_size = other.m_size;

	other.m_begin = temp_begin;
	other.m_end = temp_end;
	other.m_size = temp_size;
}