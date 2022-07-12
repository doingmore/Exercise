#ifndef RESOURCE_H
#define RESOURCE_H
#include <string>

namespace SoftUni
{
	class Resource
	{
	private:
		int m_id{0};
		std::string m_type;
		std::string m_link;
	public:
		Resource() = default;

		int getId()const { return m_id; }
		std::string getLink()const { return m_link; }
		std::string getType()const { return m_type; }
		void setLink(const std::string& newLink) { m_link = newLink; }

		friend std::istream& operator>> (std::istream& in, Resource& instantiate);
		friend std::ostream& operator<< (std::ostream& stream , const Resource& object);
	};

	std::ostream& operator<< (std::ostream& stream, const Resource& object)
	{
		stream << object.m_id << " " << object.m_type << " " << object.m_link;
		return stream;
	}


	std::istream& operator>> (std::istream& in, Resource& instantiate)
	{
		in >> instantiate.m_id;
		in >> instantiate.m_type;
		in >> instantiate.m_link;
		return in;
	}


}



#endif // !RESOURCE_H
