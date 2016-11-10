#pragma once

#include <iostream>
#include <string>

namespace ViewHelper {
	void printDelimiter();
	bool readBooleanInput(char input);
	bool isInputInValidRange(int input, int min, int max);
	void printErrorMessage();
};

