#pragma once
#include "Words.h"
using namespace Words;


class Player;

class ItemSystem
{
public:
	void TakeItem(Player& p, Object obj);
	void TossItem(Player& p, Object obj);
	void Swing(Player& p, Object obj);
	void Kill(Player& p, Object obj);
	void Light(Player& p, Object obj);
	void Unlock(Player& p, Obstacle obs);
	void Free(Player& p, Object obj);
	void Pour(Player& p, Object obj);

private:
	void TryAddItem(Player& p, Object obj);
	bool TryTossItem(Player& p, Object obj);
	void TryLight(Player& p, Object obj);
	bool UseItemFromInventory(Player& p, Object obj);
};

