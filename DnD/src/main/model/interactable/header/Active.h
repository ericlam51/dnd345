/*! Active class
* Super class of HostileNpc and Fighter
* Contains common attributes to all Fighter and Monster of this game
*/

#pragma once
#include <iostream>
#include "Interactable.h"
#include "../../item/Item.h"
#include "../../item/EquippedItems.h"

using namespace std;

class Active : public Interactable
{
public:
	Active();
	Active(string name, string description, int level);
	~Active();
	bool validateNewPlayer();
	void attack(Active &activeObj);
	void hit(int damage);
	void equipItem(Item* item);

	void print();
	void printEquipments();

	int getLevel() const;
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

	void interact();

	void Serialize(CArchive& archive);
	DECLARE_SERIAL(Active);

private:
	int generateRandomNumber(int, int);
	int calculateHitPoints();
	int calculateAttackBonus();
	int calculateArmorClass();
	int calculateBonusAbilityScore();

protected: 
	int level;
	int abilityScores[6];
	int armorClass;
	int attackBonus;
	int damageBonus;
	int currentHitPoints;
	EquippedItems* _equippedItems;
};
