#include "Armor.h"


IMPLEMENT_SERIAL(Armor, CObject, 1)

Armor::Armor(string name):Item(ItemTypes[ARMOR], name)
{
}


Armor::~Armor()
{
}

Armor::Armor()
{
}

void Armor::Serialize(CArchive & archive)
{
	// call base class function first
	// base class is CObject in this case
	Item::Serialize(archive);

}
