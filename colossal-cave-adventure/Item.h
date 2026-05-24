#pragma once

#include <string>
#include "Words.h"
using namespace std;
using namespace Words;

class Room;
class Player;

class Item
{
public:
	string name;
	string description;
	Object objType;

	Item(string name, string description, Object objType);
	virtual void PrintInfo();
	virtual void Use(Room* room);
	virtual void IncreaseObjective(Player* p);
	virtual void DecreaseObjective(Player* p);
};