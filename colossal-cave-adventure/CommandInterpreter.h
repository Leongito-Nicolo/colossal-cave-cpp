#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <variant>
#include "CommandParser.h"
#include "Words.h"

using namespace Words;

using namespace std;

struct Command
{
	Action action;
	Argument arg = monostate{};
};

struct Shortcut
{
	string word;
	Action action;
	Argument arg = monostate{};
};

class CommandInterpreter
{
	CommandParser parser;

public:
	Action InterpretVerb(const string& input);
	Command InterpretCommand(const string& input);
	Direction InterpretDirection(const string& input);
	Object InterpretObject(const string& input);
	Obstacle InterpretObstacle(const string& input);
};

