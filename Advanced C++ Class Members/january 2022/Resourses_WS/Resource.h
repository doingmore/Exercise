#ifndef Resource_H
#define Resource_H

#include <iostream>
#include <ostream>

using SoftUni::ResourceType;

namespace SoftUni
{
	class Resource
	{
	private:
		int m_id;
		SoftUni::ResourceType m_resourceType;
		std::string m_link;
	public:
		Resource() // default
		{
		}

		/*
		Resource(int id = 0, SoftUni::ResourceType  resourceType, std::string  link = " ")
			: m_id{ id }, m_resourceType{ resourceType }, m_link{ link }
		{
		}
		*/
		ResourceType getType() const { return m_resourceType; }

		friend std::istream& operator>> (std::istream& in, Resource& r);
		friend std::ostream& operator<< (std::ostream& out, const Resource& r);
		friend bool operator< (const Resource& left, const Resource& right);

	};


	bool operator< (const Resource& left, const Resource& right)
	{
		return left.m_id < right.m_id;
	}

	std::ostream& operator<< (std::ostream& out, const Resource& r)
	{
		out << r.m_id << " " << r.m_resourceType << " " << r.m_link;
		return out;
	}

	std::istream& operator>>(std::istream& in, ResourceType& resourceType)
	{
		std::string type;
		in >> type;
		if (type == "Presentation")
			resourceType = ResourceType::PRESENTATION;
		else if (type == "Demo")
			resourceType = ResourceType::DEMO;
		else if (type == "Video")
			resourceType = ResourceType::VIDEO;

		return in;
	}
	std::istream& operator>>(std::istream& in, Resource& r)
	{
		in >> r.m_id;
		in >> r.m_resourceType;
		in >> r.m_link;
		return in;
	}
}
#endif // !Resourse_h