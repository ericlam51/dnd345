#include "Weapon.h"

IMPLEMENT_SERIAL(Weapon, CObject, 1)

Weapon::Weapon(string name):Item(ItemTypes[WEAPON], name)
{
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
