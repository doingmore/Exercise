#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <sstream>
#include <set>
#include "ResourceType.h"

namespace SoftUni
{
	class Resource
	{
	private:
		int m_id = 0;
		ResourceType m_type;
		std::string m_link;
	public:
		Resource() {};

		int getId() const { return m_id; }
		std::string getLink() const { return m_link; }
		ResourceType getType() const { return m_type; }
		void setId(const int newId) { m_id = newId; }
		void setLink(const std::string newLink) { m_link = newLink; }

		bool operator< (const Resource& resource) const { return (this->m_id) < resource.m_id; }

		friend std::istream& operator>> (std::istream& stream, Resource& object);
		friend std::ostream& operator<< (std::ostream& stream, const Resource& object);
	};
	// implementation Resource.cpp
	std::ostream& operator<< (std::ostream& stream, const Resource& object)
	{
		stream << object.m_id;
		stream << " ";
		stream << object.m_type;
		stream << " ";
		stream << object.m_link;
		return stream;
	}
	// implementation Resource.cpp
	std::istream& operator>> (std::istream& stream, Resource& object)
	{
		std::string type;
		stream >> object.m_id;
		stream >> type;
		if (type == "Presentation")
		{
			object.m_type = ResourceType::PRESENTATION;
		}
		else if (type == "Demo")
		{
			object.m_type = ResourceType::DEMO;
		}
		else if (type == "Video")
		{
			object.m_type = ResourceType::VIDEO;
		}
		else
		{
			throw _EXCEPTION_;
		}
		stream >> object.m_link;
		return stream;
	}
}







#endif // !RESOURCE_H
