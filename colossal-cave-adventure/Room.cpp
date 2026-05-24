#include "Room.h"
#include <iostream>


Room::Room(const string& description, vector<Item*> items, bool isDark, Blocker* obstacle)
	: description(description)
	, items(items)
	, isDark(isDark)
	, obstacle(obstacle)
{
}

Room::Room(const string& description, bool isDark, Blocker* obstacle)
	: description(description)
	, isDark(isDark)
	, obstacle(obstacle)
{
}

void Room::AddConnection(vector<Room*> roomsToAdd)
{
	for (auto& room : roomsToAdd)
	{
		connections.push_back(room);
	}
}

Item* Room::FindItem(Object item)
{
	for (auto& i : items)
	{
		if (i->objType == item)
		{
			return i;
		}
	}

	return nullptr;
}

Blocker* Room::GetObstacle(Obstacle obs)
{
	if (obstacle != nullptr)
	{
		if (obstacle->obsType == obs)
		{
			return obstacle;
		}
		cout << "Nothing happens." << endl;
	}

	return nullptr;
}

void Room::RemoveItem(Item* item)
{
	items.erase(remove(items.begin(), items.end(), item), items.end());
}

void Room::AddItem(Item* item)
{
	items.push_back(item);
}

void Room::DeactivateObstacle()
{
	obstacle->isActive = false;
}

void Room::PrintInfo()
{
	/*cout << name << endl;*/
	cout << description << endl;

	if (items.size() > 0)
	{
		cout << endl;
		for (auto& item : items)
		{
			item->PrintInfo();
		}
	}

	if (obstacle != nullptr)
	{
		if (obstacle->isActive)
		{
			cout << endl;
			obstacle->PrintInfo();
		}
	}


}
