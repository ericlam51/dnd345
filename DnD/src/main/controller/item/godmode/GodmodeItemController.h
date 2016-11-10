#pragma once

#include "../../../model/item/ItemContainer.h"
#include "../../../model/item/Armor.h"
#include "../../../model/item/Boots.h"
#include "../../../model/item/Helmet.h"
#include "../../../model/item/Ring.h"
#include "../../../model/item/Shield.h"
#include "../../../model/item/Weapon.h"


class GodmodeItemController
{
	static GodmodeItemController *s_instance;
public:
	static GodmodeItemController* instance();
	void addItem(int, string);
	void removeItem(string, int);
	vector<Item*> getItemsOfType(int);
private:
	ItemContainer* container;
	GodmodeItemController();
};

