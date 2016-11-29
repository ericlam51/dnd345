#include "Boots.h"

IMPLEMENT_SERIAL(Boots, CObject, 1)

const string Boots::enchantmentTypes[2] = { "Armor", "Dexterity" };

Boots::Boots(string name):Item(ItemTypes[BOOTS], name)
{
	enchantmentType = enchantmentTypes[rand() % 2];
	enchantmentModifier = rand() % 6 + 1;
}


Boots::~Boots()
{
}

Boots::Boots()
{
}

void Boots::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
