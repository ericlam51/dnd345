#pragma once
#include <iostream>;
#include "Character.h";

using namespace std;

struct Inventory {
	char helmet;
	char armor;
	char shield;
	char ring;
	char belt;
	char boots;
	char weapon;
};

class Fighter : public Character
{
public:
	Fighter();
	Fighter(string name, string description, int level);
	void interact() = 0;

	bool validateNewPlayer();
	void hit(int damage);
	int getArmorClass() const;
	int getAttackBonus() const;
	int getDamageBonus() const;
	int getCurrentHitPoints();
	int getStrength() const;
	int getDexterity() const;
	int getConstitution() const;
	int getIntelligence() const;
	int getWisdom() const;
	int getCharisma() const;
	int getAbilityModifier(int);
	char getHelmet() const;
	char getArmor() const;
	char getShield() const;
	char getRing() const;
	char getBelt() const;
	char getBoots() const;
	char getWeapon() const;
	bool equipItem(const char item);
	void printEquipments();

private:
	int level;
	int abilityScores[6];
	int armorClass;
	int attackBonus;
	int damageBonus;
	int currentHitPoints;
	Inventory inventory;

	int generateRandomNumber(int, int);
	int calculateHitPoints();
	int calculateAttackBonus();
	int calculateArmorClass();

	friend std::ostream& operator<<(std::ostream &strm, Fighter &player);
};
