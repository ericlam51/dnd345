#include "GodmodeInteractableView.h"
#include <string>

//! method to prompt user to load or create Interactable Fighter, Monster, NPC, Chest)
void GodmodeInteractableView::interactableFileSelectionView() {
	int input = 0;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;;
	
	cout << "Interactable (Fighter, Monster, NPC, Chest)" << endl;
	cout << "1. New Interactable" << endl
		<< "2. Load Interactable" << endl
		<< "3. Return to Selection menu" << endl
		<< "Selection: ";

	cin >> input;

	GodmodeInteractableController::instance()->interactableFileSelection(input);
}

//! method to prompt user to show the interactable that can be created
void GodmodeInteractableView::interactableElementSelectionView() {

	int input = 0;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Which of the following do you want to create?" << endl;
	cout << "1. Fighter" << endl
		<< "2. Monster" << endl
		<< "3. NPC" << endl
		<< "4. Chest" << endl
		<< "Selection: ";

	cin >> input;
	GodmodeInteractableController::instance()->interactableCreation(input);
}

//! method to prompt user to show the interactable that can be loaded 
void GodmodeInteractableView::interactableLoadView() {
	int input = 0;

	cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;

	cout << "Which of the following do you want to load?" << endl;
	cout << "1. Fighter" << endl
		<< "2. Monster" << endl
		<< "3. NPC" << endl
		<< "4. Chest" << endl
		<< "Selection: ";

	cin >> input;
	GodmodeInteractableController::instance()->interactableLoad(input);
}
void GodmodeInteractableView::warningMsgInvalidInput() {
	cout << "Invalid input!" << endl;
}