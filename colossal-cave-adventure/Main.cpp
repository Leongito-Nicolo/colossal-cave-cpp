#include <vector>
#include <string>
#include <iostream>

#include "Player.h"
#include "Room.h"
#include "CommandParser.h"
#include "GameManager.h"

using namespace std;

int main()
{
	Item keys = Item(0, "Key", "A set of keys");			//KeyItem
	Item lantern = Item(1, "Lantern", "A lantern");			//ToolItem
	Item bottle = Item(2, "Bottle", "A bottle of water");	//PuzzleItem
	Item food = Item(3, "Food", "Some food");				//ToolItem

	Room room1 = Room(1, "Building",
		"You are inside a building, a well house for a large spring.",
		vector<Connection>{}, vector<Item>{keys, lantern, bottle, food}, false);

	Room room2 = Room(2, "End of road",
		"You are standing at the end of a road before a small brick building. Around you is a forest. A small stream flows out of the building and down a gully.",
		vector<Connection>
	{
		Connection(2, 1, EAST),
			Connection(2, 5, NORTH),
			Connection(2, 3, WEST),
			Connection(2, 3, UP),
			Connection(2, 6, SOUTH),
	}
	, vector<Item>{}, false);

	Room room3 = Room(3, "Hill in road",
		"You have walked up a hill, still in the forest. The road slopes back down the other side of the hill. There is a building in the distance.",
		vector<Connection>
	{
		Connection(3, 2, EAST),
			Connection(3, 5, SOUTH)
	}
	, vector<Item>{}, false);

	Room room4 = Room(4, "Open forest near valley & road", "You are in open forest near both a valley and a road.",
		vector<Connection>
	{
		Connection(4, 6, EAST),
			Connection(4, 5, SOUTH)
	}
	, vector<Item>{}, false);

	Room room5 = Room(5, "Open forest with deep valley to one side", "You are in open forest, with a deep valley to one side.",
		vector<Connection>
	{
		Connection(5, 4, NORTH),
			Connection(5, 6, EAST)
	}
	, vector<Item>{}, false);

	Room room6 = Room(6, "Valley", "You are in a valley in the forest beside a stream tumbling along a rocky bed.",
		vector<Connection>
	{
		Connection(6, 1, NORTH),
			Connection(6, 5, WEST),
			Connection(6, 7, SOUTH),
	}
	, vector<Item>{}, false);

	Player player = Player(room2);

	GameManager game;
	game.StartGame();

}