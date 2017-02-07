#include "utils.h"

#include <string>
#include <set>
#include <vector>

#include <iostream>
using namespace std;

bool containsBannedWords(const std::string& input, const std::vector<std::string>& bannedSet)
{
	for (const std::string& bannedWord : bannedSet)
	{
		if (input.find(bannedWord) != std::string::npos)
		{
			return true;
		}
	}
	return false;
}

int main(void)
{
	std::string in = "What the fudge.";
	std::vector<std::string> bannedWords = {"fudge"};

	if (containsBannedWords(in, bannedWords))
	{
		cout << "The sentence '" << in << "' contains a banned word." << endl;
	}
	else
	{
		cout << "The sentence '" << in << "' is clean!" << endl;
	}

	return 0;
}
