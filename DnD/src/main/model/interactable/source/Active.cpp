#include <iostream>
#include <ctime>
#include <math.h>
#include "../header/Active.h"
#include <string>

using namespace std;

Active::Active(){}
Active::Active(string name, string description, int level) : Interactable(name, description), level(level){
	for (int i = 0; i < sizeof(abilityScores); i++)
		abilityScores[i] = generateRandomNumber(3, 18);

	armorClass = calculateArmorClass();
	currentHitPoints = calculateHitPoints();
	attackBonus = calculateAttackBonus();
	damageBonus = getStrength();
}

bool Active::validateNewPlayer() {
	for (int i = 0; i <= 5; i++)
		if (abilityScores[i]<3 || abilityScores[i]>18)
			return false;
	return true;
}

void Active::attack(Active &activeObj) {
	activeObj.hit(1); //TODO calculate damage
}

void Active::interact() {
	cout << "interacting with fighter";
}

void Active::hit(int damage)
{
	currentHitPoints = currentHitPoints - damage;
}

int Active::getAbilityModifier(int abilityScore) {
	return static_cast <int>(floor((abilityScore - 10) / 2));
}

int Active::calculateHitPoints() {
	return generateRandomNumber(level, 10 * level) + getAbilityModifier(abilityScores[2]);
}

int Active::calculateAttackBonus() {
	return level + getAbilityModifier(abilityScores[0]);
}

int Active::calculateArmorClass() {
	return 10 + getAbilityModifier(getDexterity());
}

//Generated a number between max and min
int Active::generateRandomNumber(int min, int max) {
	/* initialize random seed: */
	return rand() % (max - min + 1) + min;
}

bool Active::equipItem(char item) {
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
void Active::printEquipments() {
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

std::ostream& operator<<(std::ostream &strm, Active &player) {
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

void Active::setStrength(int str) {
	abilityScores[0] = str;
}

void Active::setDexterity(int dex) {
	abilityScores[1] = dex;
}

void Active::setConstitution(int con) {
	abilityScores[2] = con;
}

void Active::setIntelligence(int intel) {
	abilityScores[3] = intel;
}

void Active::setWisdom(int wis) {
	abilityScores[4] = wis;
}

void Active::setCharisma(int cha) {
	abilityScores[5] = cha;
}

int Active::getLevel() const {
	return level;
}

int Active::getStrength() const {
	return abilityScores[0];
}

int Active::getDexterity() const {
	return abilityScores[1];
}

int Active::getConstitution() const {
	return abilityScores[2];
}

int Active::getIntelligence() const {
	return abilityScores[3];
}

int Active::getWisdom() const {
	return abilityScores[4];
}

int Active::getCharisma() const {
	return abilityScores[5];
}

int Active::getArmorClass() const {
	return armorClass;
}
int Active::getAttackBonus() const {
	return attackBonus;
}

int Active::getDamageBonus() const {
	return damageBonus;
}

int Active::getCurrentHitPoints() {
	return currentHitPoints;
}

char Active::getHelmet() const {
	return inventory.helmet;
}

char Active::getArmor() const {
	return inventory.armor;
}

char Active::getShield() const {
	return inventory.shield;
}

char Active::getRing() const {
	return inventory.ring;
}

char Active::getBelt() const {
	return inventory.belt;
}

char Active::getBoots() const {
	return inventory.boots;
}

char Active::getWeapon() const {
	return inventory.weapon;
}