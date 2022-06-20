#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>
#include <sstream>
#include <cassert>
#include <vector>

	
namespace SoftUni
{
	

	class Resource
	{
	private:
		int m_id;
		enum ResourceType m_type;
		std::string m_link;
	public:
		Resource() {}
		/*Resource(const Resource& object) = delete;
		Resource& operator= (const Resource& object) = delete;*/
		int getId()const { return m_id; }
		std::string getLink() const { return m_link; }
		enum ResourceType getType() const { return m_type; }
		void setLink(const std::string& newLINK) { m_link = newLINK; }

		friend std::istream& operator>> (std::istream& stream, Resource& object);
		
		friend bool operator< (const Resource& left, const Resource& right);


	};

	std::ostream& operator<< (std::ostream& stream, const Resource& object)
	{
		stream << object.getId() << " ";
		stream << object.getType() << " ";
		stream << object.getLink() << " ";
		return stream;
	}


	bool operator< (const Resource& left, const Resource& right)
	{
		return left.m_id < right.m_id;
	}

	std::istream& operator>> (std::istream& stream, Resource& object)
	{
		stream >> object.m_id;
	
		std::string strType;
		stream >> strType;
		if (strType == "Presentation")
		{
			//enum ResourceType type = static_cast< ResourceType>(0);
			//object.m_type= type;
			object.m_type = static_cast<ResourceType>(0);
		}
		else if (strType == "Demo")
		{
			object.m_type = static_cast<ResourceType>(1);
		}
		else if (strType == "Video")
		{
			object.m_type = static_cast<ResourceType>(2);
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
