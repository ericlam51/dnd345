#pragma once
#include "../../model/interactable/header/Active.h"
#include "../../model/interactable/header/Chest.h"

class LootController
{
	static LootController*s_instance;
public:
	LootController();
	~LootController();

	void startChestLoot(Chest* chest, Active* active);
	void lootChest(bool input);
	void startMonsterLoot(Active* monster, Active* active);
	void lootHostile(bool input);

	static LootController* instance();

private:
	Active* _fighter;
	Active* _hostile;
	Chest* _chest;
};

