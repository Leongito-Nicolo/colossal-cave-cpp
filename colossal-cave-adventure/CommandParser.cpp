#include "CommandParser.h"

#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>



CommandParser::CommandParser()
{
}

vector<string> CommandParser::tokenizeInput(const string& input)
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

vector<string> CommandParser::normalizeInput(const string& input)
{
	vector<string> normalizedTokens = tokenizeInput(input);

	for (auto& word : normalizedTokens)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
	}

	return normalizedTokens;
}