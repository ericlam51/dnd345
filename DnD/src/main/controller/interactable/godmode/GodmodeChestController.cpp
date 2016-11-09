#include "GodmodeChestController.h"

void GodmodeChestController::newChest(string name, string description) {
	_chest = new Chest(name, description);
}

GodmodeChestController* GodmodeChestController::instance() {
	if (!s_instance)
		s_instance = new GodmodeChestController();

	return s_instance;
}

GodmodeChestController* GodmodeChestController::s_instance = GodmodeChestController::instance();