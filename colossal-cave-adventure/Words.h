#pragma once

#include <variant>

namespace Words
{
	enum class Action
	{
		GO, TAKE, LEAVE, LOOK, INVENTORY,
		ENTER, EXIT, OPEN, SWING, KILL, LIGHT, FREE, POUR,
		XYZZY, PLUGH, QUIT, UNKNOWN
	};

	enum class Direction
	{
		NORTHWEST, NORTH, NORTHEAST,
		EAST, SOUTHEAST, SOUTH,
		SOUTHWEST, WEST, UP, DOWN, NONE, UNKNOWN
	};

	enum class Object
	{
		KEYS, FOOD, BOTTLE, LAMP, CAGE,
		BIRD, ROD, DIAMONDS, GOLD,
		SILVER, JEWELS, VASE, EGG, WATER,
		NONE, UNKNOWN
	};

	enum class Obstacle
	{
		GATE, SNAKE, PLANT, VOID, NONE, UNKNOWN
	};

	using Argument = std::variant<Direction, Object, Obstacle, std::monostate>;
}