#ifndef LECTURE_H
#define LECTURE_H

#include "Resource.h"

#include <string>
#include <cassert>
#include <set>
#include <map>

namespace SoftUni
{
	class Lecture
	{
		std::map<int, Resource> m_map_register;
		std::set<Resource> m_set;
	protected:
		void set_actualization()
		{
			this->m_set.clear();
			std::map<int, Resource>::iterator it;
			for (it = this->m_map_register.begin(); it != this->m_map_register.end(); it++)
			{
				this->m_set.insert(it->second);
			}
		}
	public:

		std::set<Resource>::iterator begin() { return m_set.begin(); }
		std::set<Resource>::iterator end() { return m_set.end(); }

		std::set<Resource> getSet() const { return m_set; }
		
		friend Lecture operator<< (Lecture& left ,const Resource& object);
		int operator[] (enum ResourceType type)
		{
			unsigned int answer{ 0 }; // number_that_type
			for ( const Resource& o : this->m_set)
			{
				if (o.getType() == type)
				{
					answer++;
				}
			}
			return answer;
		}

	};

	std::vector<ResourceType>& operator<<(std::vector<ResourceType>& vec, const Lecture& object)
	{
		std::set<ResourceType> register_of_types;
		for (const Resource& o : object.getSet() )
		{
			if ( register_of_types.count( o.getType() ) )
			{
				// do nothing, just skip, I need only one type of kind
			}
			else
			{
				register_of_types.insert(o.getType());
				vec.push_back(o.getType());
			}
		}

		return vec;
	}







	Lecture operator<< (Lecture& left, const Resource& object)
	{
		int id{object.getId()};
		if (left.m_map_register.count(id))
		{
			std::map<int, Resource>::iterator it;
			for ( it = left.m_map_register.begin(); it != left.m_map_register.end(); it++)
			{
				if (it->first == id && it->second.getLink() != object.getLink() ) // refresh fild m_set with new link on member with same id
				{
					std::string newLink = object.getLink();
					it->second.setLink(newLink);
					left.set_actualization(); 
					break;
				}
			}
		}
		else
		{
			left.m_map_register.emplace(id, object);
			left.m_set.insert(object);
		}


		return left;
	}





}


#endif // !LECTURE_H
