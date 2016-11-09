#include "GodmodeInteractableView.h"
#include <string>

void GodmodeInteractableView::interactableFileSelectionView() {
	int input = 0;

	ViewHelper::printDelimiter();
	
	cout << "Interactable (Fighter, Monster, NPC, Chest)" << endl;
	cout << "1. New Interactable" << endl
		<< "2. Load Interactable" << endl
		<< "Selection: ";

	cin >> input;

	if (ViewHelper::isInputInValidRange(input, 1, 2))
		GodmodeInteractableController::instance()->interactableFileSelection(input);
}


void GodmodeInteractableView::interactableElementSelectionView() {

	int input = 0;

	ViewHelper::printDelimiter();

	cout << "Which of the following do you want to create?" << endl;
	cout << "1. Fighter" << endl
		<< "2. Monster" << endl
		<< "3. NPC" << endl
		<< "4. Chest" << endl
		<< "Selection: ";

	cin >> input;
	if (ViewHelper::isInputInValidRange(input, 1, 4))
		GodmodeInteractableController::instance()->interactableCreation(input);
}