#include "Weapon.h"

IMPLEMENT_SERIAL(Weapon, CObject, 1)

const string Weapon::enchantmentTypes[2] = { "Attack", "Damage" };

Weapon::Weapon(string name):Item(ItemTypes[WEAPON], name)
{
	enchantmentType = enchantmentTypes[rand() % 2];
	enchantmentModifier = rand() % 6 + 1;
}


Weapon::~Weapon()
{
}

Weapon::Weapon()
{
}

void Weapon::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);


}
