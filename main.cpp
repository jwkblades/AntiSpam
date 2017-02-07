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
	std::set<std::string> setA = shingle(a, 1);
	std::set<std::string> setB = shingle(b, 1);

	std::set<std::string> intersection = intersectionOf(setA, setB);
	std::set<std::string> unionSet = unionOf(setA, setB);

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
	std::set<std::string> setA = shingle(a);
	std::set<std::string> setB = shingle(b);

	std::set<std::string> intersection = intersectionOf(setA, setB);
	std::set<std::string> unionSet = unionOf(setA, setB);

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
