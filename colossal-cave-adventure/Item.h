#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
public:
	int id;
	string name;
	string description;

	Item(int id, string name, string description);
	Item();
};

#endif