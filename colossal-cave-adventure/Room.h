#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"
#include "Connection.h"
using namespace std;

class Room
{
public:
	int id;
	string name;
	string description;
	vector<Connection> connections;
	vector<Item> items;
	bool isDark;

	Room(int id, const string& name, const string& description, const vector<Connection>& connections, const vector<Item>& items, bool isDark);
	Room();
};

#endif
