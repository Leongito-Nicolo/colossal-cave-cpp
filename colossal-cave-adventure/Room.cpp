#include "Room.h"

Room::Room(int id, const string& name, const string& description, const vector<Connection>& connections, const vector<Item>& items, bool isDark)
{
	Room::id = id;
	Room::name = name;
	Room::description = description;
	Room::connections = connections;
	Room::items = items;
	Room::isDark = isDark;
}

Room::Room()
{
}
