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
	static ItemContainer *contInstance;
public:
	static GodmodeItemController* instance();
	static ItemContainer* containerInstance();
	void addItem(int, string);
	vector<Item*> getItemsOfType(int);
};

