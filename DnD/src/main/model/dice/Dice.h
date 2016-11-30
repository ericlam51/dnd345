#pragma once
#include <string>
#include "../../helper/Subject.h"
using namespace std;

class Dice : public Subject {

public:
	Dice();
	static Dice* instance();
	int roll(int, int, int);
	void displayRollingMessage();

private:
	int typeOfDie;
	int numberDice;
	int rolledValue;
	static Dice *s_instance;
};


