#ifndef INVENTORYSYSTEM_H
#define INVENTORYSYSTEM_H

#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class InventorySystem
{

	struct Node
	{
		Item* data;
		Node* next;

		Node(Item* value) : data(value), next(nullptr) {}
	};

private:
	Node* head;
	int maxItems;

public:

	InventorySystem();
	bool AddToInventory(Item* value);
	void RemoveFromInventory(Item* value);
	Item* GetItem(Object obj);
	void ShowInventory();
	int CountItems();

	~InventorySystem()
	{
		Node* temp;
		while (head)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

#endif