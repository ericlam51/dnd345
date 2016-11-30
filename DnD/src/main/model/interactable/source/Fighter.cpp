#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/Fighter.h"
#include <string>

using namespace std;

IMPLEMENT_SERIAL(Fighter, CObject, 1)

Fighter::Fighter() : Active() {}

Fighter::Fighter(string name, string description, int level) : Active(name, description, level) {
}

Fighter::~Fighter() {}

void Fighter::move(int x, int y) {

}

void Fighter::levelUp()
{
	level = level + 1;
	maxHitPoints = calculateHitPoints();
	attackBonus = calculateAttackBonus();

}

void Fighter::lootItem(Item* item)
{
	_itemContainer->addItem(item);
}

void Fighter::interact() {
	cout << "interact with fighter" << endl;
}


void Fighter::Serialize(CArchive& archive) {
	CObject::Serialize(archive);

	CString cName;
	CString cDescription;

	if (archive.IsStoring()) {
		cName = getName().c_str();
		cDescription = getDescription().c_str();
		archive << cName << cDescription << level << maxHitPoints
			<< armorClass << attackBonus << damageBonus
			<< abilityScores[0] << abilityScores[1] << abilityScores[2]
			<< abilityScores[3] << abilityScores[4] << abilityScores[5];
		
		_equippedItems->Serialize(archive);

	}
	else {
		archive >> cName >> cDescription >> level >> maxHitPoints
			>> armorClass >> attackBonus >> damageBonus
			>> abilityScores[0] >> abilityScores[1] >> abilityScores[2]
			>> abilityScores[3] >> abilityScores[4] >> abilityScores[5];

		_equippedItems->Serialize(archive);

		name = ((LPCTSTR)cName);
		description = ((LPCTSTR)cDescription);
	}
}