#include "Connection.h"

Connection::Connection(int from, int to, const Direction direction)
{
	Connection::from = from;
	Connection::to = to;
	Connection::direction = direction;
	Connection::itemRequired = Item(-1, "", "");
}

Connection::Connection(int from, int to, const Direction direction, Item itemRequired)
{
	Connection::from = from;
	Connection::to = to;
	Connection::direction = direction;
	Connection::itemRequired = itemRequired;
}
