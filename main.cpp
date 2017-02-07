#include "utils.h"

#include <string>
#include <set>
#include <vector>

#include <iostream>
using namespace std;

/**
 * A less naive approach - look at whole words at a time.
 */
std::string containsBannedWords(const std::string& input, const std::vector<std::string>& bannedSet)
{
	std::vector<std::string> vec = split(input, " ");
	std::set<std::string> words;
	words.insert(vec.begin(), vec.end());
	for (const std::string& bannedWord : bannedSet)
	{
		if (words.find(bannedWord) != words.end())
		{
			return bannedWord;
		}
	}
	return "";
}

/**
 * The problem here is obviously that we can potentially get a very similar
 * string out of things that are very different in practice.
 */
double similarity(const std::string& a, const std::string& b)
{
	std::vector<std::string> vec = split(a, " ");
	std::set<std::string> setA;
	setA.insert(vec.begin(), vec.end());

	vec = split(b, " ");
	std::set<std::string> setB;
	setB.insert(vec.begin(), vec.end());

	std::set<std::string> intersection;
	std::set<std::string> unionSet;

	for (const std::string& wordA : setA)
	{
		if (setB.count(wordA)) // 0 is false, non-0 is true
		{
			intersection.insert(wordA);
		}
	}
	unionSet = setA;
	unionSet.insert(setB.begin(), setB.end());

	double top = intersection.size();
	double bottom = unionSet.size();

	return top / bottom;
}

/**
 * Shingling is nice because it compares a larger segment of the string at a
 * time. So not only do words in the string matter, but phrases as well.
 */
double shingling(const std::string& a, const std::string& b)
{
	auto shingler = [](const std::string& s, int shingleWidth = 4) -> std::set<std::string>
	{
		std::vector<std::string> vec = split(s, " ");
		std::set<std::string> ret;

		std::vector<std::string>::iterator iter = vec.begin();
		std::vector<std::string>::iterator iter2 = iter + shingleWidth;
		std::vector<std::string>::iterator end = vec.end();
		for(; iter2 != end; iter++, iter2++)
		{
			std::vector<std::string> intermediate;
			intermediate.insert(intermediate.begin(), iter, iter2);
			ret.insert(join(intermediate, " "));
		}

		return ret;
	};
	std::set<std::string> setA = shingler(a);
	std::set<std::string> setB = shingler(b);

	std::set<std::string> intersection;
	std::set<std::string> unionSet;

	for (const std::string& wordA : setA)
	{
		if (setB.count(wordA)) // 0 is false, non-0 is true
		{
			intersection.insert(wordA);
		}
	}
	unionSet = setA;
	unionSet.insert(setB.begin(), setB.end());

	double top = intersection.size();
	double bottom = unionSet.size();

	return top / bottom;
}


int main(void)
{
	std::string in1 = "a rose is a rose is a rose";
	std::string in2 = "And in the morning, I'm making waffles.";
	std::string in3 = "this is a rose";
	std::string in4 = "a rose is a sweet flower";
	std::vector<std::string> bannedWords = {"fudge", "cake"};

	cout << "The sentence '" << in1 << "' contains banned word: '" << containsBannedWords(in1, bannedWords) << "'" << endl;

	cout << "The simple similarity between '" << in1 << "' and '" << in2 << "' is " << similarity(in1, in2) << ", shingling " << shingling(in1, in2) << endl;
	cout << "The simple similarity between '" << in1 << "' and '" << in3 << "' is " << similarity(in1, in3) << ", shingling " << shingling(in1, in3) << endl;
	cout << "The simple similarity between '" << in1 << "' and '" << in4 << "' is " << similarity(in1, in4) << ", shingling " << shingling(in1, in4) << endl;

	return 0;
}
