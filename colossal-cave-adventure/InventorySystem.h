#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class InventorySystem
{
public:
	vector<Item> itemList;
	int maxItems;

	InventorySystem();
};

#endif