#include "GodmodeInteractableController.h"

void GodmodeInteractableController::interactableFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	case 2:
		GodmodeInteractableView::interactableFileSelectionView();
		break;
	default:
		GodmodeInteractableView::interactableFileSelectionView();
		break;
	}
}

void GodmodeInteractableController::interactableCreation(int input) {
	switch (input) {
	case 1:
		GodmodeActiveView::newActiveView(0);
		break;
	case 2:
		GodmodeActiveView::newActiveView(1);
		break;
	case 3:
		GodmodeFriendlyNpcView::newFriendlyNpcView();
		break;
	case 4:
		GodmodeChestView::newChestView();
		break;
	default:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	}
}

GodmodeInteractableController* GodmodeInteractableController::instance() {
	if (!s_instance)
		s_instance = new GodmodeInteractableController();

	return s_instance;
}

GodmodeInteractableController* GodmodeInteractableController::s_instance = GodmodeInteractableController::instance();