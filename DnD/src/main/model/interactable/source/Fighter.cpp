#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/Fighter.h"
#include <string>

using namespace std;

Fighter::Fighter(string name, string description, Location location, int level) : Character(name, description, location, level){
	for (int i = 0; i < sizeof(abilityScores); i++)
		abilityScores[i] = generateRandomNumber(3, 18);

	armorClass = calculateArmorClass();
	currentHitPoints = calculateHitPoints();
	attackBonus = calculateAttackBonus();
	damageBonus = getStrength();
}

bool Fighter::validateNewPlayer() {
	for (int i = 0; i <= 5; i++)
		if (abilityScores[i]<3 || abilityScores[i]>18)
			return false;
	return true;
}

void Fighter::interact() {
	cout << "interacting with fighter";
}

void Fighter::move(int x, int y) {
	Interactable::location.setXCoordinate(x);
	Interactable::location.setYCoordinate(y);
}
void Fighter::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage;
}

int Fighter::getAbilityModifier(int abilityScore) {
	return static_cast <int>(floor((abilityScore - 10) / 2));
}

int Fighter::calculateHitPoints() {
	return generateRandomNumber(Character::getLevel(), 10 * Character::getLevel()) + getAbilityModifier(abilityScores[2]);
}

int Fighter::calculateAttackBonus() {
	return Character::getLevel() + getAbilityModifier(abilityScores[0]);
}

int Fighter::calculateArmorClass() {
	return 10 + getAbilityModifier(getDexterity());
}

//Generated a number between max and min
int Fighter::generateRandomNumber(int min, int max) {
	/* initialize random seed: */
	return rand() % (max - min + 1) + min;
}

bool Fighter::equipItem(char item) {
	cout << "Equipping item ...." << endl;
	switch (item) {
	case 'h':
		inventory.helmet = item;
		return true;
	case 'a':
		inventory.armor = item;
		return true;
	case 's':
		inventory.shield = item;
		return true;
	case 'r':
		inventory.ring = item;
		return true;
	case 'b':
		inventory.belt = item;
		return true;
	case 'j':
		inventory.boots = item;
		return true;
	case 'w':
		return true;
		break;
	default:
		cout << "Failed to equip item " << item << endl;
		return false;
	}
}
void Fighter::printEquipments() {
	cout << "-+-+-+-+-+-+-+-+ EQUIPMENTS +-+-+-+-+-+-+-+-+-+-" << endl;
	cout << "Helmet: " << inventory.helmet << endl;
	cout << "Armor: " << inventory.armor << endl;
	cout << "Shield: " << inventory.shield << endl;
	cout << "Ring: " << inventory.ring << endl;
	cout << "Belt: " << inventory.belt << endl;
	cout << "Boots: " << inventory.boots << endl;
	cout << "Weapon: " << inventory.weapon << endl;
	cout << "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-" << endl;
}

std::ostream& operator<<(std::ostream &strm, Fighter &player) {
	return strm
		<< "Your player has the following attributes:"
		<< "Name:" << player.getName() << "\n"
		<< "Ability Modifier" << player.getAbilityModifier(player.getConstitution()) << "\n"
		<< "Level: " << player.getLevel() << "\n"
		<< "Strength: " << player.getStrength() << "\n"
		<< "Dexterity: " << player.getDexterity() << "\n"
		<< "Constitution: " << player.getConstitution() << "\n"
		<< "Intelligence: " << player.getIntelligence() << "\n"
		<< "Wisdom: " << player.getWisdom() << "\n"
		<< "Charisma: " << player.getCharisma() << "\n"
		<< "Hit Point: " << player.getCurrentHitPoints() << "\n"
		<< "Attack bonus: " << player.getAttackBonus() << "\n"
		<< "Armor class: " << player.getArmorClass() << "\n"
		<< "Damage bonus: " << player.getDamageBonus() << endl;
}

void Fighter::setStrength(int str) {
	abilityScores[0] = str;
}

void Fighter::setDexterity(int dex) {
	abilityScores[1] = dex;
}

void Fighter::setConstitution(int con) {
	abilityScores[2] = con;
}

void Fighter::setIntelligence(int intel) {
	abilityScores[3] = intel;
}

void Fighter::setWisdom(int wis) {
	abilityScores[4] = wis;
}

void Fighter::setCharisma(int cha) {
	abilityScores[5] = cha;
}

int Fighter::getStrength() const {
	return abilityScores[0];
}

int Fighter::getDexterity() const {
	return abilityScores[1];
}

int Fighter::getConstitution() const {
	return abilityScores[2];
}

int Fighter::getIntelligence() const {
	return abilityScores[3];
}

int Fighter::getWisdom() const {
	return abilityScores[4];
}

int Fighter::getCharisma() const {
	return abilityScores[5];
}

int Fighter::getArmorClass() const {
	return armorClass;
}
int Fighter::getAttackBonus() const {
	return attackBonus;
}

int Fighter::getDamageBonus() const {
	return damageBonus;
}

int Fighter::getCurrentHitPoints() {
	return currentHitPoints;
}

char Fighter::getHelmet() const {
	return inventory.helmet;
}

char Fighter::getArmor() const {
	return inventory.armor;
}

char Fighter::getShield() const {
	return inventory.shield;
}

char Fighter::getRing() const {
	return inventory.ring;
}

char Fighter::getBelt() const {
	return inventory.belt;
}

char Fighter::getBoots() const {
	return inventory.boots;
}

char Fighter::getWeapon() const {
	return inventory.weapon;
}