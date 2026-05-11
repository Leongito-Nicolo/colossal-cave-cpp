#pragma once

#include <vector>
#include <string>
using namespace std;

class CommandParser
{
public:
	CommandParser();
	vector<string> tokenizeInput(const string& input);
	vector<string> normalizeInput(const string& input);

};

