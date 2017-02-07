#include "utils.h"

std::vector<std::string> split(std::string str, const std::string& delimiter)
{
	std::vector<std::string> parts;

	while (!str.empty())
	{
		std::size_t pos = str.find(delimiter);
		std::string part = str.substr(0, pos);
		if (pos == std::string::npos)
		{
			str = "";
		}
		else
		{
			str = str.substr(pos + delimiter.size());
		}

		if (!part.empty())
		{
			parts.push_back(part);
		}
	}

	return parts;
}

std::string join(const std::vector<std::string>& parts, const std::string& delimiter)
{
	std::string ret = "";
	for (std::vector<std::string>::const_iterator iter = parts.begin(); iter != parts.end(); iter++)
	{
		ret += *iter;
		auto tmpIter = iter;
		tmpIter++;
		if (tmpIter != parts.end())
		{
			ret += delimiter;
		}
	}
	return ret;
}

std::set<std::string> shingle(const std::string& s, int shingleWidth)
{
	std::vector<std::string> vec = split(s, " ");
	std::set<std::string> ret;

	std::vector<std::string>::iterator iter = vec.begin();
	std::vector<std::string>::iterator iter2 = iter + shingleWidth;
	std::vector<std::string>::iterator end = vec.end();
	bool hitEnd = false;
	for(; !hitEnd; iter++, iter2++)
	{
		hitEnd = iter2 == end;
		std::vector<std::string> intermediate;
		intermediate.insert(intermediate.begin(), iter, iter2);
		ret.insert(join(intermediate, " "));
	}

	return ret;
}

std::set<std::string> intersectionOf(const std::set<std::string>& setA, const std::set<std::string>& setB)
{
	std::set<std::string> intersection;
	for (const std::string& wordA : setA)
	{
		if (setB.count(wordA)) // 0 is false, non-0 is true
		{
			intersection.insert(wordA);
		}
	}
	return intersection;
}

std::set<std::string> unionOf(const std::set<std::string>& setA, const std::set<std::string>& setB)
{
	std::set<std::string> unionSet = setA;
	unionSet.insert(setB.begin(), setB.end());
	return unionSet;
}

