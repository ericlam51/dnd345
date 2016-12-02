#include "CombatController.h"

CombatController* CombatController::instance() {
	if (!s_instance)
		s_instance = new CombatController();

	return s_instance;
	return new CombatController();
}

void CombatController::beginCombat(Active* fighter, Active* enemy) {
	Logger::instance()->appendToNewLine("Combat initialized between " + fighter->getName() + " and " + enemy->getName(), "COMBAT");
	CombatController::fighter = fighter;
	CombatController::enemy = enemy;

	int fighterInit = Dice::instance()->roll(1, 20, fighter ->getDexterity());
	int enemyInit = Dice::instance()->roll(1, 20, enemy->getDexterity());;
	Logger::instance()->appendToNewLine(fighter->getName() + " rolled " + to_string(fighterInit) + " for initiative.", "COMBAT");
	Logger::instance()->appendToNewLine(enemy->getName() + " rolled " + to_string(enemyInit) + " for initiative.", "COMBAT");	
	bool fighterStart = fighterInit >= enemyInit;
	Logger::instance()->appendToNewLine(fighter->getName() + " starting: " + to_string(fighterStart), "COMBAT");
	cv.printCombat(CombatController::fighter, CombatController::enemy, fighterStart);
}

void CombatController::fighterTurn() {
	Logger::instance()->appendToNewLine(fighter->getName() + "'s turn started. ", "COMBAT");
	int input;
	int damageRoll = 0;
	int hitRoll = Dice::instance()->roll(1, 20, CombatController::fighter->getAttackBonus());
	Logger::instance()->appendToNewLine(fighter->getName() + " rolled " + to_string(hitRoll) + " for hit roll against an AC of " + to_string(enemy->getArmorClass()), "COMBAT");
	if (hitRoll < CombatController::enemy->getArmorClass()) {
		Logger::instance()->appendToNewLine(fighter->getName() + "'s Attack missed!", "COMBAT");
		cout << fighter->getName() << "'s Attack missed!" << endl;
	}
	else {
		damageRoll = Dice::instance()->roll(2, 4, 1);
		CombatController::enemy->hit(damageRoll);
		Logger::instance()->appendToNewLine(fighter->getName() + "'s Attack landed, and dealt " + to_string(damageRoll) + " damage.", "COMBAT");
		cout << fighter->getName() << " hits " << CombatController::enemy->getName() << " for " << damageRoll << " damage. " << endl;
		if (enemy->getCurrentHitPoints() <= 0) {
			cout << enemy->getName() << " is dead! Enter anything to exit combat " ;
			Logger::instance()->appendToNewLine(enemy->getName() + " is dead.", "COMBAT");
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
	Logger::instance()->appendToNewLine(enemy->getName() + "'s turn started. ", "COMBAT");
	int input;
	int damageRoll = 0;
	int hitRoll = Dice::instance()->roll(1, 20, CombatController::enemy->getAttackBonus());
	Logger::instance()->appendToNewLine(enemy->getName() + " rolled " + to_string(hitRoll) + " for hit roll against an AC of " + to_string(fighter->getArmorClass()), "COMBAT");
	if (hitRoll < CombatController::fighter->getArmorClass()) {
		Logger::instance()->appendToNewLine(enemy->getName() + "'s Attack missed!", "COMBAT");
		cout << enemy->getName() << "'s Attack missed!" << endl;
	}
	else {
		damageRoll = Dice::instance()->roll(2, 4, 1);
		CombatController::fighter->hit(damageRoll);
		Logger::instance()->appendToNewLine(enemy->getName() + "'s Attack landed, and dealt " + to_string(damageRoll) + " damage.", "COMBAT");
		cout << enemy->getName() << " hits " << CombatController::fighter->getName() << " for " << damageRoll << " damage. " << endl;
		if (fighter->getCurrentHitPoints() <= 0) {
			cout << fighter->getName() << " is dead! Enter anything to exit combat ";
			Logger::instance()->appendToNewLine(fighter->getName() + " is dead.", "COMBAT");
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
	Logger::instance()->appendToNewLine("Combat ended.", "COMBAT");
	CombatController::enemy = NULL;
	CombatController::fighter = NULL;
}

CombatController* CombatController::s_instance = CombatController::instance();
Active* CombatController::enemy = NULL;
Active* CombatController::fighter = NULL;


