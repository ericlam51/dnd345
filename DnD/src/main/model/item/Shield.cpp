#include "Shield.h"

IMPLEMENT_SERIAL(Shield, CObject, 1)

Shield::Shield(string name):Item(ItemTypes[SHIELD], name)
{
	enchantmentType = "Armor";
	enchantmentModifier = rand() % 6 + 1;
}


Shield::~Shield()
{
}

Shield::Shield()
{
}

void Shield::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
