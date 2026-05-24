#pragma once
#include "Item.h"

class TreasureItem :
	public Item
{
public:
	TreasureItem(string name, string description, Object objType);

	void IncreaseObjective(Player* p) override;
	void DecreaseObjective(Player* p) override;
};
