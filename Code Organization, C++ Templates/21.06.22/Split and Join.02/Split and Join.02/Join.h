#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <vector>
#include <sstream>
#define begin 0



template<typename U>
std::string join(const U& vector, const std::string& joinElement)
{
	std::string answer;

	for (size_t i = begin; i < vector.size(); i++)
	{
		std::stringstream stream;
		std::string element;
		stream << vector[i];
		while (stream >> element)
		{
			answer += element;
			if (stream >> element)
			{
				answer += ' ';
				answer += element;
			}
		}
		if (i < (vector.size() - 1))
		{
			answer += joinElement;
		}
	}
	return answer;
}







/*
template<typename U>
std::string join(const U& vector , const std::string& joinElement )
{
	std::string answer;
	
	
	for (size_t i=begin;i < vector.size();i++)
	{
		std::stringstream stream;
		std::string element;
		stream << vector[i];
		stream >> element;
		answer += element;
		if (i < (vector.size() - 1 ) )
		{
			answer += joinElement;
		}
	}
	return answer;
}


class Song;
std::string join(const std::vector<Song>& vector, const std::string& joinElement)
{
	std::string answer;
	
	for (size_t i = begin ; i < vector.size(); i++)
	{
		std::string element;
		element += vector[i].getName();
		element += ' ';
		element += std::to_string( vector[i].getLengthSeconds() );
		answer += element;
		if (i < (vector.size() - 1))
		{
			answer += joinElement;
		}
	}

	return answer;
}*/




#endif // !JOIN_H
