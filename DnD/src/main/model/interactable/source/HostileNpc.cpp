#include <iostream>
#include "../header/HostileNpc.h"

IMPLEMENT_SERIAL(HostileNpc, CObject, 1)

HostileNpc::HostileNpc(){}

HostileNpc::HostileNpc(string name, string description, int level) : Active(name, description, level), size(size){

}

HostileNpc::~HostileNpc() {}

void HostileNpc::interact(){
	cout << "interact with hostile npc" << endl;
	Sleep(1000);
}

void HostileNpc::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	CString cName(getName().c_str());
	CString cDescription(getDescription().c_str());

	if (archive.IsStoring()) {
		archive << cName << cDescription << level << maxHitPoints
			<< armorClass << attackBonus << damageBonus
			<< abilityScores[0] << abilityScores[1] << abilityScores[2]
			<< abilityScores[3] << abilityScores[4] << abilityScores[5]; //TODO serialize item
	}
	else {
		archive >> cName >> cDescription >> level >> maxHitPoints
			>> armorClass >> attackBonus >> damageBonus
			>> abilityScores[0] >> abilityScores[1] >> abilityScores[2]
			>> abilityScores[3] >> abilityScores[4] >> abilityScores[5];

		name = ((LPCTSTR)cName);
		description = ((LPCTSTR)cDescription);
	}
}