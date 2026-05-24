#include "TreasureItem.h"
#include "Player.h"

TreasureItem::TreasureItem(string name, string description, Object objType)
	: Item(name, description, objType)
{
}

void TreasureItem::IncreaseObjective(Player* p)
{
	p->score++;
}

void TreasureItem::DecreaseObjective(Player* p)
{
	p->score--;
}
