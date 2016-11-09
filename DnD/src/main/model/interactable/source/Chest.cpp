#include "../header/Chest.h"

Chest::Chest() {}

Chest::Chest(string name, string description) : Passive(name, description) {


}

void Chest::interact() {
	open();
}

void Chest::open() {
	cout << "open chest" << endl;
}

