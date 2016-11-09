#include "../header/Chest.h"

Chest::Chest() {}

Chest::Chest(string name, string description) : Passive(name, description, location) {


}

void Chest::interact() {
	open();
}

void Chest::open() {
	cout << "open chest" << endl;
}

