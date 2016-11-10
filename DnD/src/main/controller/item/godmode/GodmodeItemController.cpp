#include "GodmodeItemController.h"

GodmodeItemController::GodmodeItemController() 
{
	container = new ItemContainer();
}


GodmodeItemController* GodmodeItemController::instance() {
	if (!s_instance)
		s_instance = new GodmodeItemController();

	return s_instance;
}

void GodmodeItemController::addItem(int selection, string name)
{
	Item* item;
	switch (selection) 
	{
		case 1:
			item = new Armor(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 2:
			item = new Shield(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 3:
			item = new Weapon(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 4:
			item = new Boots(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 5:
			item = new Ring(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
		case 6:
			item = new Helmet(name);
			GodmodeItemController::instance()->container->addItem(item);
			break;
	}
}

void GodmodeItemController::removeItem(string type, int index)
{
	Item* item = container->getItem(type, index - 1);
	container->removeItem(item);
}

vector<Item*> GodmodeItemController::getItemsOfType(int selection)
{
	return GodmodeItemController::instance()->container->getItemsOfType(ItemTypes[selection - 1]);
}

GodmodeItemController* GodmodeItemController::s_instance = GodmodeItemController::instance();
