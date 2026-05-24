#include "KeyItem.h"
#include "Room.h"
#include <iostream>

KeyItem::KeyItem(string name, string description, Object objType, Obstacle obsToOpen)
	: Item(name, description, objType)
{
	this->obsToOpen = obsToOpen;
}

void KeyItem::Use(Room* room)
{
	Blocker* obs = room->GetObstacle(obsToOpen);
	if (obs != nullptr)
	{
		obs->PrintOpenMessage();
		room->DeactivateObstacle();

		return;
	}

	cout << "Nothing happens." << endl;

}
