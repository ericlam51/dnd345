#include "Dice.h"
#include <iostream>
#include <regex>
using namespace std;

Dice::Dice()
{
	
}


Dice::~Dice()
{
}

int Dice :: roll(int times, int type, int z) {
	if (type != 4 && type != 6 && type != 8 && type != 10 && type != 20 && type != 100) {
		return 0;
	}
	srand((unsigned)time(NULL));
	int rolledValue = 0;
	for (int i = 0; i < times; i++) {
		rolledValue += rand() % type + 1;
		cout << rolledValue << endl;
	}
	return rolledValue + z;
}
