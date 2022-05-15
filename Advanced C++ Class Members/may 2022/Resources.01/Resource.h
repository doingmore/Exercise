#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <sstream>

#include "ResourceType.h"
using namespace SoftUni;

class Resource
{
private:
	int m_id=0;
	enum ResourceType m_type;
	std::string m_link="";
public:
	Resource() = default; // Resource() {} ;

	ResourceType getType() const { return m_type; }

	bool operator<(const Resource& resource) const { return (this->m_id) < resource.m_id; }

	friend std::istream& operator>> (std::istream& stream, Resource& object);	
	friend std::ostream& operator<< (std::ostream& stream, const Resource& object);
};

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

std::ostream& operator<< (std::ostream& stream, const Resource& object)
{
	std::string type;
	switch (object.getType())
	{
	case 0:
		type = "Presentation";
		break;
	case 1:
		type = "Demo";
		break;
	case 2:
		type = "Video";
		break;
	default:
		break;
	}
	stream << object.m_id;
	stream << " ";
	stream << type;
	stream << " ";
	stream << object.m_link;
	return stream;
}

#endif // !RESOURCE_H
