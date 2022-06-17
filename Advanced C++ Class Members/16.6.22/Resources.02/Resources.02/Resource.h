#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <sstream>
#include <cassert>

#include "ResourceType.h"
using namespace SoftUni;

class Resource
{
private:
	int m_id;
	enum ResourceType m_type;
	std::string m_link;
public:
	Resource() {}

	int getId() const { return m_id; }
	enum ResourceType getType() const { return m_type; }
	std::string getLink() const { return m_link; }

	friend std::istream& operator>> (std::istream& input, Resource& object);
	
	friend bool operator<  (const Resource& left, const Resource& right);

};

bool operator< (const Resource& left, const Resource& right)
{
	return left.getId() < right.getId();
}

std::ostream& operator<< (std::ostream& stream, const Resource& object)
{
	stream << object.getId() << " ";
	stream << object.getType() << " ";
	stream << object.getLink();
	return stream;
}

std::istream& operator>> (std::istream& input, Resource& object)
{
	//first 
	input >> object.m_id;
	//second 
	std::string strType;
	input >> strType;
	enum ResourceType type;
	if (strType == "Presentation")
	{
		type = static_cast <enum ResourceType>(0); // ResourceType::PRESENTATION
	}
	else if (strType == "Demo")
	{
		type = static_cast <enum ResourceType>(1);
	}
	else if (strType == "Video")
	{
		type = static_cast <enum ResourceType>(2);
	}
	else
	{
		throw _EXCEPTION_;
	}

	object.m_type = type;

	// third 
	input >> object.m_link;

	return input;
}
#endif // !RESOURCE_H
