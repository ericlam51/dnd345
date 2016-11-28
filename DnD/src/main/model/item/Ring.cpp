#include "Ring.h"

IMPLEMENT_SERIAL(Ring, CObject, 1)

const string Ring::enchantmentTypes[5] = { "Armor", "Strength", "Constitution", "Wisdom", "Charisma" };

Ring::Ring(string name):Item(ItemTypes[RING], name)
{
	enchantmentType = enchantmentTypes[rand() % 5];
	enchantmentModifier = rand() % 6 + 1;
}


Ring::~Ring()
{
}

Ring::Ring() 
{
}

void Ring::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
