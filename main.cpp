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

int main(void)
{
	std::string in = "Pancakes and fudge waffles.";
	std::vector<std::string> bannedWords = {"fudge", "cake"};

	cout << "The sentence '" << in << "' contains banned word: '" << containsBannedWords(in, bannedWords) << "'" << endl;

	return 0;
}
