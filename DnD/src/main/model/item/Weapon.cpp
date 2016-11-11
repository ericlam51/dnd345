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

	// now do the stuff for our specific class
	//if (archive.IsStoring())
	//	archive << m_name << m_number;
	//else
	//	archive >> m_name >> m_number;
}
