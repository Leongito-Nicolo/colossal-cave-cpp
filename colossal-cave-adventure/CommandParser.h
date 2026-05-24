#pragma once

#include <vector>
#include <string>
using namespace std;

class CommandParser
{
public:
	CommandParser();
	vector<string> TokenizeInput(const string& input);
	vector<string> NormalizeInput(const string& input);

};

