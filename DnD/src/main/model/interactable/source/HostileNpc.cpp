#include <iostream>
#include "../header/HostileNpc.h"
#include "../../../controller/PlayModeController.h"
#include "../../../controller/combat/CombatController.h"
#include "../../../controller/loot/LootController.h"
IMPLEMENT_SERIAL(HostileNpc, CObject, 1)

HostileNpc::HostileNpc() : Active() {}

HostileNpc::HostileNpc(string name, string description, int level) : Active(name, description, level), size(size){

}

HostileNpc::~HostileNpc() {}

void HostileNpc::interact(){

	PlayModeController * pmc = PlayModeController::instance();
	Active * active = PlayModeController::instance()->getPlayer();
	CombatController::instance()->beginCombat(active, this);
	cout << "Combat Ended." << endl;
	if (active->getCurrentHitPoints() <= 0) {
		cout << "Game Over!" << endl;
		pmc->endGame();
	}
	else {
		LootController::instance()->startMonsterLoot(this, active);
	}
	Sleep(1000);
	system("cls");
}

void HostileNpc::Serialize(CArchive& archive) {
	CObject::Serialize(archive);
	CString cName(getName().c_str());
	CString cDescription(getDescription().c_str());

	if (archive.IsStoring()) {
		archive << cName << cDescription << level << maxHitPoints << currentHitPoints
			<< armorClass << attackBonus << damageBonus
			<< abilityScores[0] << abilityScores[1] << abilityScores[2]
			<< abilityScores[3] << abilityScores[4] << abilityScores[5]; 

		_equippedItems->Serialize(archive);
	}
	else {
		archive >> cName >> cDescription >> level >> maxHitPoints >> currentHitPoints
			>> armorClass >> attackBonus >> damageBonus
			>> abilityScores[0] >> abilityScores[1] >> abilityScores[2]
			>> abilityScores[3] >> abilityScores[4] >> abilityScores[5];

		_equippedItems->Serialize(archive);

		name = ((LPCTSTR)cName);
		description = ((LPCTSTR)cDescription);
	}
}