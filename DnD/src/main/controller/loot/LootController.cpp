#include "LootController.h"
#include "../../view/loot/LootView.h"

LootController::LootController(){}
LootController::~LootController(){}

void LootController::startChestLoot(Chest* chest, Active* active){
	chest->print();
	_fighter = active;
	_chest = chest;
	LootView::chestLootOptionsView(1);
}

void LootController::lootChest(bool input) {
	if (input) {
		ItemContainer* itemContainer = _chest->lootItems();
		for (int i = 0; i <= HELMET; i++)
		{
			vector<Item*> items = itemContainer->getItemsOfType(ItemTypes[i]);
			for (vector<Item*>::iterator it = items.begin(); it != items.end(); ++it)
			{
				_fighter->addItemToInventory(*it);
			}
		}
	}
}

void LootController::startMonsterLoot(Active* hostile, Active* active){
	_hostile = hostile;
	_fighter = active;

	_hostile->printEquipments();
	LootView::chestLootOptionsView(2);
}

void LootController::lootHostile(bool input) {
	if (input) {
		map<string, Item*> items = _hostile->getEquippedItem()->getEquipped();
		for (int i = 0; i <= HELMET; i++) {
			if(items[ItemTypes[i]] != nullptr)
				_fighter->addItemToInventory(items[ItemTypes[i]]);
		}
	}
}

LootController* LootController::instance() {
	if (!s_instance)
		s_instance = new LootController();

	return s_instance;
}

LootController* LootController::s_instance = LootController::instance();