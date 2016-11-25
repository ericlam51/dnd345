#include "../header/Passive.h"
#include <iostream>

using namespace std;

IMPLEMENT_SERIAL(Passive, CObject, 1)

Passive::Passive() {}

Passive::Passive(string name, string description) : Interactable(name, description) {
}

Passive::~Passive() {}

void Passive::interact() {}
	
void Passive::Serialize(CArchive& archive) {}



