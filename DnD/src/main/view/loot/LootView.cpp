#include "LootView.h"


void LootView::chestLootOptionsView(int input) {
	char in;
	string entity;

	if (input == 1)
		entity = "chest";
	else
		entity = "hostile";

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Do you want to loot the content of the " << entity << " [Y/n]? " << endl;
	cin >> in;

	bool cond = false;
	if (in == 'y' || in == 'Y')
		cond = true;

	if (in == 'n' || in == 'N')
		cond = false;
	
	if (input == 1)
		LootController::instance()->lootChest(cond);
	else
		LootController::instance()->lootHostile(cond);
	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;
}