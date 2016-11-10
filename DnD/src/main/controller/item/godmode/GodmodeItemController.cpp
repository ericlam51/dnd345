#include "GodmodeItemController.h"


GodmodeItemController* GodmodeItemController::instance() {
	if (!s_instance)
		s_instance = new GodmodeItemController();

	return s_instance;
}

ItemContainer * GodmodeItemController::containerInstance()
{
	if (!contInstance)
		contInstance = new ItemContainer();

	return contInstance;
}

void GodmodeItemController::addItem(int selection, string name)
{
	Item* item;
	switch (selection) 
	{
		case 1:
			item = new Armor(name);
			GodmodeItemController::containerInstance()->addItem(item);
			break;
		case 2:
			item = new Shield(name);
			GodmodeItemController::containerInstance()->addItem(item);
			break;
		case 3:
			item = new Weapon(name);
			GodmodeItemController::containerInstance()->addItem(item);
			break;
		case 4:
			item = new Boots(name);
			GodmodeItemController::containerInstance()->addItem(item);
			break;
		case 5:
			item = new Ring(name);
			GodmodeItemController::containerInstance()->addItem(item);
			break;
		case 6:
			item = new Helmet(name);
			GodmodeItemController::containerInstance()->addItem(item);
			break;
	}
}

vector<Item*> GodmodeItemController::getItemsOfType(int selection)
{
	return GodmodeItemController::containerInstance()->getItemsOfType(ItemTypes[selection - 1]);
}

GodmodeItemController* GodmodeItemController::s_instance = GodmodeItemController::instance();
ItemContainer* GodmodeItemController::contInstance = GodmodeItemController::containerInstance();
