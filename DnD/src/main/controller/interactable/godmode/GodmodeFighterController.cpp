#include "GodmodeFighterController.h"

void GodmodeFighterController::newFighter(string name, string description, int level) {
	_fighter = new Fighter(name, description, level);
}

GodmodeFighterController* GodmodeFighterController::instance() {
	if (!s_instance)
		s_instance = new GodmodeFighterController();

	return s_instance;
}

GodmodeFighterController* GodmodeFighterController::s_instance = GodmodeFighterController::instance();