#pragma once

#include <vector>
#include "Room.h"

using namespace std;


class WorldManager
{
private:
	vector<Room*> rooms;
public:
	Room* startRoom;
	Room* buildingRoom;
	Room* xyzzyTpRoom;
	Room* plughTpRoom;


	void InitializeRooms();

	~WorldManager()
	{
		for (auto& room : rooms)
		{
			delete room;
		}
	}
};

