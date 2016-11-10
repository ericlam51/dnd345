#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/Fighter.h"
#include <string>

using namespace std;

IMPLEMENT_SERIAL(Fighter, CObject, 1)

Fighter::Fighter() {}

Fighter::Fighter(string name, string description, int level) : Active(name, description, level){
}

Fighter::~Fighter() {}

void Fighter::move(int x, int y) {
	Interactable::location.setXCoordinate(x);
	Interactable::location.setYCoordinate(y);
}
void Fighter::interact() {
	cout << "interact with fighter" << endl;
}

void Fighter::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	if (archive.IsStoring()) {
		CString cName(getName().c_str());
		CString cDescription(getDescription().c_str());
		archive << cName << cDescription << getLevel()
			<< getStrength() << getDexterity() << getConstitution()
			<< getIntelligence() << getWisdom() << getCharisma(); //TODO serialize item
	}
}