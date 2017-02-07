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

int main(void)
{
	std::string in1 = "a rose is a rose is a rose";
	std::string in2 = "And in the morning, I'm making waffles.";
	std::string in3 = "this is a rose";
	std::vector<std::string> bannedWords = {"fudge", "cake"};

	cout << "The sentence '" << in1 << "' contains banned word: '" << containsBannedWords(in1, bannedWords) << "'" << endl;

	cout << "The simple similarity between '" << in1 << "' and '" << in2 << "' is " << similarity(in1, in2) << endl;
	cout << "The simple similarity between '" << in1 << "' and '" << in3 << "' is " << similarity(in1, in3) << endl;

	return 0;
}
