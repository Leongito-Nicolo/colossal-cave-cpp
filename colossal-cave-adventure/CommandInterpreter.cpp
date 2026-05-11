#include "CommandInterpreter.h"

const vector<Shortcut> shortcuts = {
	{"n",     Action::GO, Direction::NORTH},
	{"north",  Action::GO, Direction::NORTH},
	{"s",     Action::GO, Direction::SOUTH},
	{"south",     Action::GO, Direction::SOUTH},
	{"e",     Action::GO, Direction::EAST},
	{"east",     Action::GO, Direction::EAST},
	{"w",     Action::GO, Direction::WEST},
	{"west",     Action::GO, Direction::WEST},
	{"i",     Action::INVENTORY },
	{"inv",     Action::INVENTORY },
	{"l",     Action::LOOK }
};

Action CommandInterpreter::InterpretVerb(const string& input)
{
	if (input == "go") return Action::GO;
	if (input == "get" || input == "take" || input == "pick") return Action::TAKE;
	if (input == "toss" || input == "leave" || input == "discard") return Action::LEAVE;
	if (input == "look" || input == "examine") return Action::LOOK;
	if (input == "inventory") return Action::INVENTORY;
	if (input == "enter") return Action::ENTER;
	if (input == "exit") return Action::EXIT;
	if (input == "open" || input == "unlock") return Action::OPEN;
	if (input == "swing" || input == "wave") return Action::SWING;
	if (input == "kill") return Action::KILL;
	if (input == "xyzzy" || input == "XYZZY") return Action::XYZZY;
	if (input == "plugh" || input == "PLUGH") return Action::PLUGH;

	return Action::UNKNOWN;
}

Direction CommandInterpreter::InterpretDirection(const string& input)
{
	if (input == "north" || input == "n") return Direction::NORTH;
	if (input == "northeast" || input == "ne") return Direction::NORTHEAST;
	if (input == "northwest" || input == "nw") return Direction::NORTHWEST;
	if (input == "east" || input == "e") return Direction::EAST;
	if (input == "west" || input == "w") return Direction::WEST;
	if (input == "south" || input == "s") return Direction::SOUTH;
	if (input == "southeast" || input == "se") return Direction::SOUTHEAST;
	if (input == "southwest" || input == "sw") return Direction::SOUTHWEST;
	if (input == "up" || input == "u") return Direction::UP;
	if (input == "down" || input == "d") return Direction::DOWN;


	return Direction::NONE;
}

Object CommandInterpreter::InterpretObject(const string& input)
{
	if (input == "keys" || input == "key") return Object::KEYS;
	if (input == "food") return Object::FOOD;
	if (input == "bottle") return Object::BOTTLE;
	if (input == "lamp") return Object::LAMP;
	if (input == "cage") return Object::CAGE;
	if (input == "grate" || input == "gate") return Object::GATE;
	if (input == "bird") return Object::BIRD;
	if (input == "rod") return Object::ROD;
	if (input == "diamonds" || input == "diamond") return Object::DIAMONDS;
	if (input == "gold") return Object::GOLD;
	if (input == "silver") return Object::SILVER;
	if (input == "snake") return Object::SNAKE;
	if (input == "jewels" || input == "jewel") return Object::JEWELS;
	if (input == "vase") return Object::VASE;
	if (input == "egg") return Object::EGG;
	if (input == "oil") return Object::OIL;
	if (input == "water") return Object::WATER;
	if (input == "plant") return Object::PLANT;

	return Object::NOTHING;
}

Command CommandInterpreter::InterpretCommand(const string& input)
{
	auto tokens = parser.normalizeInput(input);
	if (tokens.empty()) return { Action::UNKNOWN };

	// Single word
	if (tokens.size() == 1)
	{
		// Look for a shortcut
		for (auto& s : shortcuts)
			if (tokens[0] == s.word)
				return { s.action, s.dir, s.obj };

		// Just verb, should throw a message (e.g. go where?)
		return { InterpretVerb(tokens[0]) };

	}

	// Two words
	if (tokens.size() == 2)
	{
		string tok0 = tokens[0], tok1 = tokens[1];

		// Normal order action direction/object
		Action verb = InterpretVerb(tok0);

		// If verb is unknown, try order direction/object action
		if (verb == Action::UNKNOWN)
		{
			verb = InterpretVerb(tok1);

			if (verb == Action::UNKNOWN) return { Action::UNKNOWN };

			swap(tok0, tok1);
		}

		Direction dir = InterpretDirection(tok1);
		Object obj = InterpretObject(tok1);

		return { verb, dir, obj };
	}

	return { Action::UNKNOWN };


}
