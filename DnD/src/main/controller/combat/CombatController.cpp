#include "CombatController.h"

CombatController* CombatController::instance() {
	if (!s_instance)
		s_instance = new CombatController();

	return s_instance;
	return new CombatController();
}

CombatController* CombatController::s_instance = CombatController::instance();

