#include "Item.h"
#include <iostream>

Item::Item(int id, string name, string description)
{
	Item::id = id;
	Item::name = name;
	Item::description = description;
}

Item::Item()
{
}
