#include "utils.h"

template<typename T>
std::set<T> shingle(const T& s, int shingleWidth)
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

template<typename T>
std::set<T> intersectionOf(const std::set<T>& setA, const std::set<T>& setB)
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

template<typename T>
std::set<T> unionOf(const std::set<T>& setA, const std::set<T>& setB)
{
	std::set<std::string> unionSet = setA;
	unionSet.insert(setB.begin(), setB.end());
	return unionSet;
}

