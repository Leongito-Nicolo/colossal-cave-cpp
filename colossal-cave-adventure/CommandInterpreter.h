#pragma once

#include <vector>
#include <string>
#include <iostream>
#include "CommandParser.h"

using namespace std;

enum class Action { GO, TAKE, LEAVE, LOOK, INVENTORY, ENTER, EXIT, OPEN, SWING, KILL, XYZZY, PLUGH, UNKNOWN };
enum Direction { NORTH, NORTHEAST, NORTHWEST, EAST, WEST, SOUTH, SOUTHEAST, SOUTHWEST, UP, DOWN, NONE };
enum Object { KEYS, FOOD, BOTTLE, LAMP, CAGE, GATE, BIRD, ROD, DIAMONDS, GOLD, SILVER, SNAKE, JEWELS, VASE, EGG, OIL, WATER, PLANT, NOTHING };

struct Command
{
	Action action;
	Direction direction = Direction::NONE;
	Object object = Object::NOTHING;
};

struct Shortcut
{
	string word;
	Action action;
	Direction dir = Direction::NONE;
	Object obj = Object::NOTHING;
};

class CommandInterpreter
{
	CommandParser parser;

public:
	Action InterpretVerb(const string& input);
	Command InterpretCommand(const string& input);
	Direction InterpretDirection(const string& input);
	Object InterpretObject(const string& input);
};

