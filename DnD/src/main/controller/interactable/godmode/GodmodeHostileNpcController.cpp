#include "GodmodeHostileNpcController.h"

void GodmodeHostileNpcController::newHostileNpc(string name, string description, int level) {
	_hostileNpc = new HostileNpc(name, description, level);
}

GodmodeHostileNpcController* GodmodeHostileNpcController::instance() {
	if (!s_instance)
		s_instance = new GodmodeHostileNpcController();

	return s_instance;
}

GodmodeHostileNpcController* GodmodeHostileNpcController::s_instance = GodmodeHostileNpcController::instance();