#include "CommandInterpreter.h"

const vector<Shortcut> shortcuts = {
	{"n",     Action::GO, Direction::NORTH},
	{"north",  Action::GO, Direction::NORTH},
	{"ne",  Action::GO, Direction::NORTHEAST},
	{"northeast",  Action::GO, Direction::NORTHEAST},
	{"nw",  Action::GO, Direction::NORTHWEST},
	{"northwest",  Action::GO, Direction::NORTHWEST},
	{"s",     Action::GO, Direction::SOUTH},
	{"south",     Action::GO, Direction::SOUTH},
	{"southeast",     Action::GO, Direction::SOUTHEAST},
	{"se",     Action::GO, Direction::SOUTHEAST},
	{"southwest",     Action::GO, Direction::SOUTHWEST},
	{"sw",     Action::GO, Direction::SOUTHWEST},
	{"e",     Action::GO, Direction::EAST},
	{"east",     Action::GO, Direction::EAST},
	{"w",     Action::GO, Direction::WEST},
	{"west",     Action::GO, Direction::WEST},
	{"down",     Action::GO, Direction::DOWN},
	{"d",     Action::GO, Direction::DOWN},
	{"up",     Action::GO, Direction::UP},
	{"u",     Action::GO, Direction::UP},
	{"i",     Action::INVENTORY },
	{"inv",     Action::INVENTORY },
	{"l",     Action::LOOK }
};

Action CommandInterpreter::InterpretVerb(const string& input)
{
	if (input == "go") return Action::GO;
	if (input == "get" || input == "take" || input == "pick") return Action::TAKE;
	if (input == "toss" || input == "leave" || input == "discard" || input == "drop") return Action::LEAVE;
	if (input == "look" || input == "examine") return Action::LOOK;
	if (input == "inventory") return Action::INVENTORY;
	if (input == "enter") return Action::ENTER;
	if (input == "exit") return Action::EXIT;
	if (input == "open" || input == "unlock") return Action::OPEN;
	if (input == "swing" || input == "wave") return Action::SWING;
	if (input == "kill") return Action::KILL;
	if (input == "light" || input == "on") return Action::LIGHT;
	if (input == "free") return Action::FREE;
	if (input == "pour") return Action::POUR;
	if (input == "xyzzy") return Action::XYZZY;
	if (input == "plugh") return Action::PLUGH;
	if (input == "quit") return Action::QUIT;

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


	return Direction::UNKNOWN;
}

Object CommandInterpreter::InterpretObject(const string& input)
{
	if (input == "keys" || input == "key") return Object::KEYS;
	if (input == "food") return Object::FOOD;
	if (input == "bottle") return Object::BOTTLE;
	if (input == "lamp") return Object::LAMP;
	if (input == "cage") return Object::CAGE;
	if (input == "bird") return Object::BIRD;
	if (input == "rod") return Object::ROD;
	if (input == "diamonds" || input == "diamond") return Object::DIAMONDS;
	if (input == "gold") return Object::GOLD;
	if (input == "silver") return Object::SILVER;
	if (input == "jewels" || input == "jewel") return Object::JEWELS;
	if (input == "vase") return Object::VASE;
	if (input == "egg" || input == "eggs") return Object::EGG;
	if (input == "water") return Object::WATER;

	return Object::UNKNOWN;
}

Obstacle CommandInterpreter::InterpretObstacle(const string& input)
{
	if (input == "grate" || input == "gate") return Obstacle::GATE;
	if (input == "snake") return Obstacle::SNAKE;
	if (input == "plant") return Obstacle::PLANT;

	return Obstacle::UNKNOWN;


}

Command CommandInterpreter::InterpretCommand(const string& input)
{
	auto tokens = parser.NormalizeInput(input);
	if (tokens.empty()) return { Action::UNKNOWN };

	// Single word
	if (tokens.size() == 1)
	{
		// Look for a shortcut
		for (auto& s : shortcuts)
			if (tokens[0] == s.word)
				return { s.action, s.arg };

		// Just verb, should throw a message (e.g. go where?)
		return { InterpretVerb(tokens[0]) };

	}

	// Two or more words
	if (tokens.size() >= 2)
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

		if (dir == Direction::UNKNOWN)
		{
			Object obj = InterpretObject(tok1);
			if (obj == Object::UNKNOWN)
			{
				Obstacle obs = InterpretObstacle(tok1);
				if (obs == Obstacle::UNKNOWN)
				{
					cout << "I don't know the word " << tok1 << endl;
					return { verb, obs };
				}

				return { verb, obs };
			}

			return { verb, obj };

		}

		return { verb, dir };
	}

	return { Action::UNKNOWN };


}
