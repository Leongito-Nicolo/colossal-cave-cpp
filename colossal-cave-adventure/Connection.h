#ifndef CONNECTION_H
#define CONNECTION_H

#include "Item.h"

enum Direction {
	NORTH,
	NORTHEAST,
	NORTHWEST,
	EAST,
	WEST,
	SOUTH,
	SOUTHEAST,
	SOUTHWEST,
	UP,
	DOWN
};


class Connection
{
public:
	int from;
	int to;
	Direction direction;
	Item itemRequired;

	Connection(int from, int to, const Direction direction);
	Connection(int from, int to, const Direction direction, Item itemRequired);
};



#endif

