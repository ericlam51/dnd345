#include "CombatController.h"

CombatController* CombatController::instance() {
	if (!s_instance)
		s_instance = new CombatController();

	return s_instance;
	return new CombatController();
}

void CombatController::beginCombat(Active* fighter, Active* enemy) {
	CombatController::fighter = fighter;
	CombatController::enemy = enemy;
	int fighterInit = Dice::instance()->roll(1, 20, fighter ->getDexterity());
	int enemyInit = Dice::instance()->roll(1, 20, enemy->getDexterity());;
	bool fighterStart = fighterInit >= enemyInit;
	cv.printCombat(CombatController::fighter, CombatController::enemy, fighterStart);
}

void CombatController::fighterTurn() {
	int input;
	int damageRoll = 0;
	int hitRoll = Dice::instance()->roll(1, 20, CombatController::fighter->getAttackBonus());
	if (hitRoll < CombatController::enemy->getArmorClass()) {
		cout << fighter->getName() << "'s Attack missed!" << endl;
	}
	else {
		damageRoll = Dice::instance()->roll(2, 4, 0);
		CombatController::enemy->hit(damageRoll);
		cout << fighter->getName() << " hits " << CombatController::enemy->getName() << " for " << damageRoll << " damage. " << endl;
		if (enemy->getCurrentHitPoints() <= 0) {
			cout << enemy->getName() << " is dead! Enter anything to exit combat " ;
			cin >> input;
			CombatController::exitCombat();
			return;
		}
	}
	cout << "Enter anything to continue the combat" << endl;
	cin >> input;
	cv.printCombat(CombatController::fighter, CombatController::enemy, false);
}

void CombatController::enemyTurn() {
	int input;
	int damageRoll = 0;
	int hitRoll = Dice::instance()->roll(1, 20, CombatController::enemy->getAttackBonus());
	if (hitRoll < CombatController::fighter->getArmorClass()) {
		cout << enemy->getName() << "'s Attack missed!" << endl;
	}
	else {
		damageRoll = Dice::instance()->roll(2, 4, 0);
		CombatController::fighter->hit(damageRoll);
		cout << enemy->getName() << "hits " << CombatController::fighter->getName() << " for " << damageRoll << " damage. " << endl;
		if (fighter->getCurrentHitPoints() <= 0) {
			cout << fighter->getName() << " is dead! Enter anything to exit combat ";
			cin >> input;
			CombatController::exitCombat();
			return;
		}
	}
	cout << "Enter anything to continue the combat" << endl;
	cin >> input;
	cv.printCombat(CombatController::fighter, CombatController::enemy, true);
}

void CombatController::exitCombat() {
	system("cls");
	CombatController::enemy = NULL;
	CombatController::fighter = NULL;
}

CombatController* CombatController::s_instance = CombatController::instance();
Active* CombatController::enemy = NULL;
Active* CombatController::fighter = NULL;


