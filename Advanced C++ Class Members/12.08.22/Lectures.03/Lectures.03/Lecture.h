#ifndef LECTURE_H
#define LECTURE_H
#include <vector>
#include <set>
#include <algorithm>

#include "ResourceType.h"
#include "Resource.h"
#include <iostream>

namespace SoftUni
{
	class Lecture
	{
	private:
		std::vector<Resource> m_list;

		void changeLinkOnObject(const std::string& newLink,const int& id)
		{
			for (size_t i = 0; i < m_list.size(); i++)
			{
				if (m_list[i].getId() == id)
				{
					m_list[i].setLink(newLink);
				}
			}
		}

		bool checkForSameId(const int& id)
		{
			for (size_t i = 0; i < m_list.size(); i++)
			{
				if (m_list[i].getId() == id)
				{
					return true;
				}
			}
			return false;
		}

		void sortById()
		{
			std::sort( this->m_list.begin() , this->m_list.end() , [](Resource& left, Resource& right) { return  (left.getId() < right.getId()); });
		}
	public:
		Lecture() {}

		friend Lecture& operator<<(Lecture& left, const Resource& right);
		friend std::vector<ResourceType>& operator<<(std::vector<ResourceType>&, const Lecture& right);

		std::vector<Resource>::iterator begin() { return this->m_list.begin(); }
		std::vector<Resource>::iterator end() { return this->m_list.end(); }

		int operator[](const ResourceType& index);

	};

	int Lecture::operator[](const ResourceType& index)
	{
		int answer{ 0 };
		std::string type;
		if (static_cast<int>(index) == 0)
		{
			type = "Presentation";
		}
		else if (static_cast<int>(index) == 1)
		{
			type = "Demo";
		}
		else if (static_cast<int>(index) == 2)
		{
			type = "Video";
		}
		else
		{
			std::cout << "error with cast ResourceType to str_type " << '\n';
			throw _EXCEPTION_;
		}

		for (size_t i = 0; i < this->m_list.size(); i++)
		{
			if (this->m_list[i].getType() == type)
			{
				answer++;
			}
		}

		return answer;
	}


	std::vector<ResourceType>& operator<<(std::vector<ResourceType>& left, const Lecture& right)
	{
		std::set<std::string> mySetRegister;
		
		for (size_t i = 0; i < right.m_list.size(); i++)
		{
			std::string type{ right.m_list[i].getType()};
			if (!mySetRegister.count(type))
			{
				mySetRegister.insert(type);
				int int_for_cast{ 0 };
				if (type == "Presentation")
				{
					int_for_cast = 0;
				}
				else if (type == "Demo")
				{
					int_for_cast = 1;
				}
				else if (type == "Video")
				{
					int_for_cast = 2;
				}
				else
				{
					std::cout << "error with cast str_type to ResourceType " << '\n';
					throw _EXCEPTION_;
				}

				left.push_back( static_cast<ResourceType>(int_for_cast));
			}

		}
		return left;
	}


	Lecture& operator<<(Lecture& left, const Resource& right)
	{
		if (!left.checkForSameId(right.getId()))
		{
			left.m_list.emplace_back(right);
			left.sortById();
		}
		else
		{
			left.changeLinkOnObject(right.getLink(), right.getId());
		}
		
		return left;
	}


}



#endif // !LECTURE_H
