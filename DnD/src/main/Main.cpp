#include <iostream>
#include <ctime>
#include <math.h>
#include "./model/interactable/header/ActiveBuilder.h"
#include "./model/interactable/header/Fighter.h"
#include <string>

using namespace std;

int main() {
	string name = "eric";
	string desc = "eric";
	ActiveBuilder *fighterBuilder = new ActiveBuilder(name, desc, Location(1, 1), 1, 0);
	fighterBuilder->setStrength(51);
	Fighter* fighter = dynamic_cast<Fighter*>(fighterBuilder->build());

	cout << *fighter << endl;

	fighter->interact();

	bool done;
	cin >> done;

	delete fighter;

	return 0;
}
