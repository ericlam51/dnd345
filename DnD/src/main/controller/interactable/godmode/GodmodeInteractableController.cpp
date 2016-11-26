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
		break;
	default:
		GodmodeInteractableView::warningMsgInvalidInput();
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
		GodmodeInteractableView::warningMsgInvalidInput();
		GodmodeInteractableView::interactableElementSelectionView();
		break;
	}
}

//! method to parse selection of GodmodeInteractableView::interactableLoadView()
void GodmodeInteractableController::interactableLoad(int input) {
	switch (input) {
	case 1:
		GodmodeActiveController::instance()->getSavedActiveFiles(0);
		break;
	case 2:
		GodmodeActiveController::instance()->getSavedActiveFiles(1);
		break;
	case 3:
		GodmodeFriendlyNpcController::instance()->getSavedFiles();
		break;
	case 4:
		GodmodeChestController::instance()->getSavedFiles();
		break;
	default:
		GodmodeInteractableView::warningMsgInvalidInput();
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