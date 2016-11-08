#include "../header/Passive.h"
#include "../../Location.h"
#include <iostream>

using namespace std;

Passive::Passive() {}

Passive::Passive(string name, string description, Location location) : Interactable(name, description, location) {
}

void Passive::interact() {
	
}

