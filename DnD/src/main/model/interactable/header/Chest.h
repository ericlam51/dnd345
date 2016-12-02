/*! Chest class
* Placed in map and allow player to interact
*/
#pragma once
#include <iostream>
#include "Passive.h"
#include "../../item/ItemContainer.h"
#include "../../item/Item.h"

using namespace std;

class Chest : public Passive
{
public:
	Chest();
	Chest(string name, string description);
	~Chest();
	void interact();
	void addItem(Item* item);
	ItemContainer* lootItems();
	void open();
	void print();
	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Chest);
private:
	ItemContainer* _chestContent;
};
