#include "ViewHelper.h"
#include <iostream>
#include <string>

using namespace std;

const string ViewHelper::DELIMITER = "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-";
const string ViewHelper::INVALID_INPUT = "Invalid input!";

void ViewHelper::printDelimiter() {
	cout << DELIMITER << endl;
}

bool ViewHelper::readBooleanInput(char input) {
	if (input == 'y' || input == 'Y')
		return true;

	if (input == 'n' || input == 'N')
		return false;

	return false;
}


bool ViewHelper::isInputInValidRange(int input, int min, int max) {
	if (input >= min && input <= max) {
		return true;
	}
	else {
		printErrorMessage();
		return false;
	}
		
}

void ViewHelper::printErrorMessage() {
	cout << INVALID_INPUT << endl;
}