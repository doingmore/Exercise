#ifndef ORDERED_INSERTER_H
#define ORDERED_INSERTER_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Company.h"



class OrderedInserter
{
private:
	std::vector<const Company*> m_list;
protected:
	struct less_than_id
	{
		bool operator() (const Company* left, const Company* right)
		{
			return ( left->getId() < right->getId() );
		}
	};

	
public:
	OrderedInserter(std::vector<const Company*>& list) : m_list{list}
	{}

	
	void insert(const Company* c)
	{
		m_list.emplace_back(c);
		std::sort( m_list.begin() , m_list.end() , less_than_id() );
	}

	std::vector<const Company*> getOrderedList()const { return m_list; }

};


#endif // !ORDERED_INSERTER_H
