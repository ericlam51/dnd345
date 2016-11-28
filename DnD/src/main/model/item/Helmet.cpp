#include "Helmet.h"

IMPLEMENT_SERIAL(Helmet, CObject, 1)

const string Helmet::enchantmentTypes[3] = { "Intelligence", "Wisdom", "Armor" };

Helmet::Helmet(string name):Item(ItemTypes[HELMET], name)
{
	enchantmentType = enchantmentTypes[rand() % 3];
	enchantmentModifier = rand() % 6 + 1;
}


Helmet::~Helmet()
{
}

Helmet::Helmet()
{
}

void Helmet::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
