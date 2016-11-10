
#include "ViewHelper.h"

using namespace std;

namespace ViewHelper {
	void ViewHelper::printDelimiter() {
		cout << "-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-" << endl;
	}

	bool readBooleanInput(char input) {
		if (input == 'y' || input == 'Y')
			return true;

		if (input == 'n' || input == 'N')
			return false;

		return false;
	}


	bool isInputInValidRange(int input, int min, int max) {
		if (input >= min && input <= max) {
			return true;
		}
		else {
			printErrorMessage();
			return false;
		}

	}

	void printErrorMessage() {
		cout << "Invalid input!" << endl;
	}
}