#include <ctime>
#include <math.h>
#include "../header/Active.h"
#include <string>

using namespace std;

IMPLEMENT_SERIAL(Active, CObject, 1)

Active::Active(){}

Active::Active(string name, string description, int level) : Interactable(name, description), level(level){
	for (int i = 0; i < sizeof(abilityScores); i++)
		abilityScores[i] = generateRandomNumber(3, 18);

	armorClass = calculateArmorClass();
	currentHitPoints = calculateHitPoints();
	attackBonus = calculateAttackBonus();
	damageBonus = getStrength();
}

Active::~Active() {}

bool Active::validateNewPlayer() {
	for (int i = 0; i <= 5; i++)
		if (abilityScores[i] < 3 || abilityScores[i] > (18 + calculateBonusAbilityScore()))
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
	return 10 + getAbilityModifier(abilityScores[1]);
}

int Active::calculateBonusAbilityScore() {
	return (level % 4); //Players receive +1 ability score per 4 levels
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

void Active::print() {
	cout << "Your player has the following attributes:" << endl
		<< "Name: " << name << endl
		<< "Ability Modifier: " << getAbilityModifier(abilityScores[2]) << endl
		<< "Level: " << getLevel() << endl
		<< "Strength: " << abilityScores[0] << endl
		<< "Dexterity: " << abilityScores[1] << endl
		<< "Constitution: " << abilityScores[2] << endl
		<< "Intelligence: " << abilityScores[3] << endl
		<< "Wisdom: " << abilityScores[4] << endl
		<< "Charisma: " << abilityScores[5] << endl
		<< "Hit Point: " << abilityScores[6] << endl
		<< "Attack bonus: " << attackBonus << endl
		<< "Armor class: " << armorClass << endl
		<< "Damage bonus: " << damageBonus << endl;
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

void Active::Serialize(CArchive& archive) {}