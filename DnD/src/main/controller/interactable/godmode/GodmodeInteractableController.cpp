#include "GodmodeInteractableController.h"

//! method to parse selection of GodmodeInteractableView::interactableFileSelectionView()
void GodmodeInteractableController::interactableFileSelection(int input) {
	switch (input) {
	case 1:
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	case 2:
		GodmodeInteractableView::interactableLoadView();
		break;
	case 3:
		GameModeView::displayView(3);
		break;
	default:
		GodmodeInteractableView::interactableFileSelectionView();
		break;
	}
}

//! method to parse selection of GodmodeInteractableView::interactableCreationView()
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

//! method to parse selection of GodmodeInteractableView::interactableLoadView()
void GodmodeInteractableController::interactableLoad(int input) {
	switch (input) {
	case 1:
		GodmodeActiveView::loadActiveView(0);
		break;
	case 2:
		GodmodeActiveView::loadActiveView(1);
		break;
	case 3:
		GodmodeFriendlyNpcView::loadFriendlyNpcView();
		break;
	case 4:
		GodmodeChestView::loadChestView();
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