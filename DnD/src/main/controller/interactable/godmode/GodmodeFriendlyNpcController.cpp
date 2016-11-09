#include "GodmodeFriendlyNpcController.h"

void GodmodeFriendlyNpcController::newFriendlyNpc(string name, string description, string dialog) {
	_friendlyNpc = new FriendlyNpc(name, description, dialog);
}

GodmodeFriendlyNpcController* GodmodeFriendlyNpcController::instance() {
	if (!s_instance)
		s_instance = new GodmodeFriendlyNpcController();

	return s_instance;
}

GodmodeFriendlyNpcController* GodmodeFriendlyNpcController::s_instance = GodmodeFriendlyNpcController::instance();