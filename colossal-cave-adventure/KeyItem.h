#pragma once
#include "Item.h"

class KeyItem :
	public Item
{
public:
	Obstacle obsToOpen;
	KeyItem(string name, string description, Object objType, Obstacle obsToOpen);

	void Use(Room* room) override;
};

