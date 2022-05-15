#ifndef LECTURE_H
#define LECTURE_H

#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>

#include "ResourceType.h"
#include "Resource.h"

namespace SoftUni
{
	class Lecture
	{
	private:
		std::map<int, Resource> m_map;
		std::set<Resource> resources;
	public:
		Lecture() {}

		std::set<Resource>::iterator begin() const {return this->resources.begin();};
		std::set<Resource>::iterator end() const {return this->resources.end();};
		friend Lecture& operator<< (Lecture& list, Resource& object);
		friend void actualization_resources(Lecture& object);
		friend std::vector<ResourceType>& operator<< (std::vector<ResourceType>& vec, Lecture& en);

		// operator subscribe[] must will be member function, but for this task. I must print, number of Resource objects from this type
		// I can't change skeleton main.cpp
		int operator[] (const ResourceType& type)
		{
			int number_object_from_this_type{ 0 };
			for (std::set<Resource>::iterator it = resources.begin(); it != resources.end(); it++)
			{
				if (it->getType() == type)
				{
					number_object_from_this_type++;
				}
			}
			return number_object_from_this_type;
		}
	};
	// implementation Lecture.cpp
	std::vector<ResourceType>& operator<< (std::vector<ResourceType>& vec, Lecture& en)
	{
		std::set<ResourceType> registerTypes;
		for (std::set<Resource>::iterator it = en.resources.begin(); it != en.resources.end(); it++)
		{
			if (registerTypes.count(it->getType()))
			{
				// do nothing I need only one type from kinds
			}
			else
			{
				vec.push_back(it->getType());
				registerTypes.insert(it->getType());
			}
		}
		return vec;
	}
	// implementation Lecture.cpp
	void actualization_resources(Lecture& object)
	{
		object.resources.clear();
		for (std::map<int, Resource>::iterator it = object.m_map.begin(); it != object.m_map.end(); it++)
		{
			object.resources.insert(it->second);
		}
	}
	// implementation Lecture.cpp
	Lecture& operator<< (Lecture& left, Resource& object)
	{
		int object_ID{ object.getId() };
		if (left.m_map.count(object_ID))
		{
			for (std::map<int, Resource>::iterator it = left.m_map.begin(); it != left.m_map.end(); it++)
			{
				if (it->first == object_ID)
				{
					std::string newLink{ object.getLink() };
					it->second.setLink(newLink);
					break;
				}
			}
		}
		else
		{
			left.m_map.emplace(object_ID, object);
		}
		actualization_resources(left);
		return left;
	}
}



#endif // !LECTURE_H
