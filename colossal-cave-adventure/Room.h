#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"
#include "KeyItem.h"
#include "TreasureItem.h"
#include "Blocker.h"
using namespace std;

class Room
{
public:
	string description;
	vector<Room*> connections;
	vector<Item*> items;
	Blocker* obstacle;
	bool isDark;
	Direction enterDirection = Direction::NONE;
	Direction exitDirection = Direction::NONE;

	Room(const string& description, vector<Item*> items, bool isDark, Blocker* obstacle = nullptr);
	Room(const string& description, bool isDark, Blocker* obstacle = nullptr);

	void AddConnection(vector<Room*> roomsToAdd);
	Item* FindItem(Object item);
	Blocker* GetObstacle(Obstacle obs);
	void RemoveItem(Item* item);
	void AddItem(Item* item);
	void DeactivateObstacle();
	void PrintInfo();

	~Room()
	{
		for (auto& item : items)
		{
			delete item;
		}

		delete obstacle;
	}
};

#endif
