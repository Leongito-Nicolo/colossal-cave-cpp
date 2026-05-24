#include "Item.h"
#include "Room.h"
#include "Player.h"
#include <iostream>

Item::Item(string name, string description, Object objType)
{
	this->name = name;
	this->description = description;
	this->objType = objType;
}

void Item::PrintInfo()
{
	if (description != "")
	{
		cout << description << endl;
	}

}

void Item::Use(Room* room)
{
	cout << "You can't use that." << endl;
}

void Item::IncreaseObjective(Player* p)
{
}

void Item::DecreaseObjective(Player* p)
{
}
