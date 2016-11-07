#pragma once
#include <iostream>
#include "Character.h"

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
	Fighter(string name, string description, Location location, int level);
	void interact();

	bool validateNewPlayer();
	void hit(int damage);
	bool equipItem(const char item);
	void move(int x, int y);
	void printEquipments();

	int getArmorClass() const;
	int getAttackBonus() const;
	int getDamageBonus() const;
	int getCurrentHitPoints();
	void setStrength(int str);
	void setDexterity(int dex);
	void setConstitution(int con);
	void setIntelligence(int intel);
	void setWisdom(int wis);
	void setCharisma(int cha);
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
