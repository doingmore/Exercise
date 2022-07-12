#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"
#include <sstream>
#include <string>

namespace SoftUni
{
	class Resource
	{
	private:
		int m_id{ 0 };
		std::string m_type;
		std::string m_link;
	public:
		Resource() {}

		enum ResourceType getType()const 
		{
			if (this->m_type == "Presentation")
			{
				return ResourceType{ static_cast<ResourceType>(0) };
			}
			else if (this->m_type == "Demo")
			{
				return ResourceType{ static_cast<ResourceType>(1) };
			}
			else if (this->m_type == "Video")
			{
				return ResourceType{ static_cast<ResourceType>(2) };
			}
			else
			{
				std::cout << "Error with enum cast!!" << '\n';
				throw _EXCEPTION_;
			}
			return ResourceType{ static_cast<ResourceType>(0) };
		}

		friend bool operator< (const Resource& left, const Resource& right);

		
		friend std::ostream& operator<< (std::ostream& stream  , const Resource& instance);
		friend std::istream& operator>> (std::istream& in, Resource& instance);

	};

	std::ostream& operator<< (std::ostream& stream, const Resource& instance)
	{
		stream << instance.m_id;
		stream << ' ';
		stream << instance.m_type;
		stream << ' ';
		stream << instance.m_link;
		return stream;
	}
	

	bool operator< (const Resource& left, const Resource& right)
	{
		return (left.m_id < right.m_id);
	}

	std::istream& operator>> (std::istream& in, Resource& instance)
	{
		in >> instance.m_id;
		in >> instance.m_type;
		in >> instance.m_link;
		return in;
	}


}





#endif // !RESOURCE_H
