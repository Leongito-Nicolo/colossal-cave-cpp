#include "CommandParser.h"

#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>



CommandParser::CommandParser()
{
}

vector<string> CommandParser::TokenizeInput(const string& input)
{
	vector<string> tokens;
	istringstream stream(input);
	string word;

	while (stream >> word)
	{
		tokens.push_back(word);
	}

	return tokens;
}

vector<string> CommandParser::NormalizeInput(const string& input)
{
	vector<string> normalizedTokens = TokenizeInput(input);

	for (auto& word : normalizedTokens)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);

		if (word == "to" || word == "the")
		{
			normalizedTokens.erase(remove(normalizedTokens.begin(), normalizedTokens.end(), word), normalizedTokens.end());
		}
	}

	return normalizedTokens;
}