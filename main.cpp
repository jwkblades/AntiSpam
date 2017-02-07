#include "utils.h"

#include <string>
#include <set>
#include <vector>

#include <iostream>
using namespace std;

/**
 * Naive approach - substring matching is a bad idea since it doesn't guarantee
 * that they were meaning to be vulgar.
 *
 * "I am late on my assignment."
 *                  ---          
 * Contains a curse word, but it isn't a cursing/ bad sentence.
 */
std::string containsBannedWords(const std::string& input, const std::vector<std::string>& bannedSet)
{
	for (const std::string& bannedWord : bannedSet)
	{
		if (input.find(bannedWord) != std::string::npos)
		{
			return bannedWord;
		}
	}
	return "";
}

int main(void)
{
	std::string in = "Pancakes and waffles.";
	std::vector<std::string> bannedWords = {"fudge", "cake"};

	cout << "The sentence '" << in << "' contains banned word: '" << containsBannedWords(in, bannedWords) << "'" << endl;

	return 0;
}
