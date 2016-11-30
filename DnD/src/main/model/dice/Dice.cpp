#include "Dice.h"
#include <iostream>
#include <regex>
#include<time.h>
using namespace std;

Dice::Dice() {
	srand(time(NULL));
}

int Dice :: roll(int times, int type, int z) {
	if (type != 4 && type != 6 && type != 8 && type != 10 && type != 20 && type != 100) {
		return 0;
	}
	numberDice = times;
	typeOfDie = type;

	rolledValue = 0;
	for (int i = 0; i < times; i++) {
		rolledValue += rand() % type + 1;
	}
	Notify();
	return rolledValue + z;
}


void Dice::displayRollingMessage() {
	cout << rollingMessage();
}

string Dice::rollingMessage() {
	string str;
	str.append("Rolling ");
	str.append(numberDice + " ");
	str.append("d");
	str.append(" " + typeOfDie);
	str.append(". Value Rolled: " + rolledValue);
	return str;
}


Dice* Dice::instance() {
	if (!s_instance) {
		s_instance = new Dice();
	}
		
	return s_instance;
}

Dice* Dice::s_instance = Dice::instance();
