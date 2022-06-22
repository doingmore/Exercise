#include "Article13Filter.h"

#include <sstream>
#include <string>
#include <set>

Article13Filter::Article13Filter(std::set<std::string> copyrighted) : copyrighted{ copyrighted }
{}

bool Article13Filter::blockIfCopyrighted(std::string s)
{
	if (copyrighted.count(s))
	{
		blocked.push_back(s);
		return true;
	}
	return false;
}

std::vector<std::string> Article13Filter::getBlocked()
{
	return blocked;
}
