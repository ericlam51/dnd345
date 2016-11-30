#include "CombatView.h"
#include <iostream>
#include <iomanip>
using namespace std;

CombatView* CombatView::instance() {
	if (!s_instance)
		s_instance = new CombatView();

	return s_instance;
	return new CombatView();
}

void CombatView::printCombat(Active* fighter, Active* monster, bool fighterStart) {
	int input;
	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	system("cls");
	int outputSpace = 30;
	string output;
	//!print name
	SetConsoleTextAttribute(m_hConsole, 11);
	cout.width(outputSpace); cout << left << fighter->getName(); cout.width(outputSpace); cout << left << monster->getName() << endl;
	SetConsoleTextAttribute(m_hConsole, 15);
	//!print hp
	output = "HP: " + to_string(fighter->getCurrentHitPoints());
	cout.width(outputSpace); cout << left << output;
	output = "HP: " + to_string(monster->getCurrentHitPoints());
	cout.width(outputSpace); cout << left << output << endl;
	//! print armor class
	output = "Armor Class: " + to_string(fighter->getArmorClass());
	cout.width(outputSpace); cout << left << output;
	output = "Armor Class: " + to_string(monster->getArmorClass());
	cout.width(outputSpace); cout << left << output << endl;
	//! print armor class
	output = "Attack Bonus: " + to_string(fighter->getAttackBonus());
	cout.width(outputSpace); cout << left << output;
	output = "Attack Bonus: " + to_string(monster->getAttackBonus());
	cout.width(outputSpace); cout << left << output << endl;

	if (fighterStart) {
		cout << "It is " << fighter->getName() << "'s turn." << endl;
		cout << "Enter anything to roll the dice." << endl;
		cin >> input;
		cc.fighterTurn();
	}
	else {
		cout << "It is " << monster->getName() << "'s turn." << endl;
		cout << "Enter anything to start " <<monster->getName()<<"'s turn." << endl;
		cin >> input;
		cc.enemyTurn();
	}
}

CombatView* CombatView::s_instance = CombatView::instance();