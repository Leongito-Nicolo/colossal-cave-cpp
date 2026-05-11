#include "InventorySystem.h"
#include <iostream>

InventorySystem::InventorySystem()
{
	InventorySystem::itemList = vector<Item>();
	InventorySystem::maxItems = 8;
}