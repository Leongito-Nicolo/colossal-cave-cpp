#include "GameManager.h"
#include <vector>
#include <string>
#include <iostream>
#include "CommandInterpreter.h"

using namespace std;

void GameManager::StartGame()
{
	bool playing = true;
	CommandInterpreter c;
	while (playing)
	{
		string input;
		cout << ">> ";
		getline(std::cin, input);
		auto s = c.InterpretCommand(input);

		switch (s.action)
		{
		case Action::GO:
			cout << "going ";
			break;
		case Action::TAKE:
			cout << "taking ";
			break;
		case Action::LEAVE:
			cout << "leaving ";
			break;
		case Action::LOOK:
			cout << "looking ";
			break;
		case Action::INVENTORY:
			cout << "open inv";
			break;
		case Action::ENTER:
			cout << "entering ";
			break;

		case Action::EXIT:
			cout << "exiting ";
			break;

		case Action::OPEN:
			cout << "opening ";
			break;

		case Action::SWING:
			cout << "swinging ";
			break;

		case Action::KILL:
			cout << "killing ";
			break;

		case Action::XYZZY:
			cout << "xyzzy";
			break;

		case Action::PLUGH:
			cout << "plugh";
			break;
		default:
			cout << "HUH??";
			break;
		}

		switch (s.direction)
		{
		case Direction::NORTH:
			cout << "north";
			break;

		case Direction::NORTHEAST:
			cout << "northeast";
			break;

		case Direction::NORTHWEST:
			cout << "northwest";
			break;

		case Direction::EAST:
			cout << "east";
			break;

		case Direction::WEST:
			cout << "west";
			break;

		case Direction::SOUTH:
			cout << "south";
			break;

		case Direction::SOUTHEAST:
			cout << "southeast";
			break;

		case Direction::SOUTHWEST:
			cout << "southwest";
			break;

		case Direction::UP:
			cout << "up";
			break;

		case Direction::DOWN:
			cout << "down";
			break;
		}

		switch (s.object)
		{
		case Object::KEYS:
			cout << "keys";
			break;

		case Object::FOOD:
			cout << "food";
			break;

		case Object::BOTTLE:
			cout << "bottle";
			break;

		case Object::LAMP:
			cout << "lamp";
			break;

		case Object::CAGE:
			cout << "cage";
			break;

		case Object::GATE:
			cout << "grate";
			break;

		case Object::BIRD:
			cout << "bird";
			break;

		case Object::ROD:
			cout << "rod";
			break;

		case Object::DIAMONDS:
			cout << "diamonds";
			break;

		case Object::GOLD:
			cout << "gold";
			break;

		case Object::SILVER:
			cout << "silver";
			break;

		case Object::SNAKE:
			cout << "snake";
			break;

		case Object::JEWELS:
			cout << "jewels";
			break;

		case Object::VASE:
			cout << "vase";
			break;

		case Object::EGG:
			cout << "egg";
			break;

		case Object::OIL:
			cout << "oil";
			break;

		case Object::WATER:
			cout << "water";
			break;

		case Object::PLANT:
			cout << "plant";
			break;
		}

		cout << endl;
	}
}
