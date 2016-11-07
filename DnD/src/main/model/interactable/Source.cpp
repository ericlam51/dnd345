#include <iostream>
#include <ctime>
#include <math.h>
#include "./header/FighterBuilder.h"
#include <string>

using namespace std;

int main() {
	string name = "eric";
	string desc = "eric";
	FighterBuilder *fighterBuilder = new FighterBuilder(name, desc, Location(1, 1), 1);
	fighterBuilder->setStrength(51);
	Fighter* fighter = fighterBuilder->build();

	cout << *fighter;

	return 0;
}
